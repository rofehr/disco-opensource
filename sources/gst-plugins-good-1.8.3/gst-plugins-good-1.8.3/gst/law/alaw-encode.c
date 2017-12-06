/* GStreamer PCM to A-Law conversion
 * Copyright (C) 2000 by Abramo Bagnara <abramo@alsa-project.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
/**
 * SECTION:element-alawenc
 *
 * This element encode alaw audio. Alaw coding is also known as G.711.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/audio/audio.h>
#include "alaw-encode.h"

GST_DEBUG_CATEGORY_STATIC (alaw_enc_debug);
#define GST_CAT_DEFAULT alaw_enc_debug

extern GstStaticPadTemplate alaw_enc_src_factory;
extern GstStaticPadTemplate alaw_enc_sink_factory;

G_DEFINE_TYPE (GstALawEnc, gst_alaw_enc, GST_TYPE_AUDIO_ENCODER);

static gboolean gst_alaw_enc_start (GstAudioEncoder * audioenc);
static gboolean gst_alaw_enc_set_format (GstAudioEncoder * enc,
    GstAudioInfo * info);
static GstFlowReturn gst_alaw_enc_handle_frame (GstAudioEncoder * enc,
    GstBuffer * buffer);

/* some day we might have defines in gstconfig.h that tell us about the
 * desired cpu/memory/binary size trade-offs */
#define GST_ALAW_ENC_USE_TABLE

#ifdef GST_ALAW_ENC_USE_TABLE

static const guint8 alaw_encode[2048 + 1] = {
  0xd5, 0xd4, 0xd7, 0xd6, 0xd1, 0xd0, 0xd3, 0xd2, 0xdd, 0xdc, 0xdf, 0xde,
  0xd9, 0xd8, 0xdb, 0xda, 0xc5, 0xc4, 0xc7, 0xc6, 0xc1, 0xc0, 0xc3, 0xc2,
  0xcd, 0xcc, 0xcf, 0xce, 0xc9, 0xc8, 0xcb, 0xca, 0xf5, 0xf5, 0xf4, 0xf4,
  0xf7, 0xf7, 0xf6, 0xf6, 0xf1, 0xf1, 0xf0, 0xf0, 0xf3, 0xf3, 0xf2, 0xf2,
  0xfd, 0xfd, 0xfc, 0xfc, 0xff, 0xff, 0xfe, 0xfe, 0xf9, 0xf9, 0xf8, 0xf8,
  0xfb, 0xfb, 0xfa, 0xfa, 0xe5, 0xe5, 0xe5, 0xe5, 0xe4, 0xe4, 0xe4, 0xe4,
  0xe7, 0xe7, 0xe7, 0xe7, 0xe6, 0xe6, 0xe6, 0xe6, 0xe1, 0xe1, 0xe1, 0xe1,
  0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xe2, 0xe2, 0xe2, 0xe2,
  0xed, 0xed, 0xed, 0xed, 0xec, 0xec, 0xec, 0xec, 0xef, 0xef, 0xef, 0xef,
  0xee, 0xee, 0xee, 0xee, 0xe9, 0xe9, 0xe9, 0xe9, 0xe8, 0xe8, 0xe8, 0xe8,
  0xeb, 0xeb, 0xeb, 0xeb, 0xea, 0xea, 0xea, 0xea, 0x95, 0x95, 0x95, 0x95,
  0x95, 0x95, 0x95, 0x95, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94,
  0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x97, 0x96, 0x96, 0x96, 0x96,
  0x96, 0x96, 0x96, 0x96, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x93, 0x93, 0x93, 0x93,
  0x93, 0x93, 0x93, 0x93, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
  0x9d, 0x9d, 0x9d, 0x9d, 0x9d, 0x9d, 0x9d, 0x9d, 0x9c, 0x9c, 0x9c, 0x9c,
  0x9c, 0x9c, 0x9c, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
  0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x99, 0x99, 0x99, 0x99,
  0x99, 0x99, 0x99, 0x99, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98,
  0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9a, 0x9a, 0x9a, 0x9a,
  0x9a, 0x9a, 0x9a, 0x9a, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85,
  0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x84, 0x84, 0x84, 0x84,
  0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,
  0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
  0x87, 0x87, 0x87, 0x87, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86,
  0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x81, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83,
  0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
  0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d, 0x8d,
  0x8d, 0x8d, 0x8d, 0x8d, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c,
  0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8f, 0x8f, 0x8f, 0x8f,
  0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f,
  0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e, 0x8e,
  0x8e, 0x8e, 0x8e, 0x8e, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89,
  0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b, 0x8b,
  0x8b, 0x8b, 0x8b, 0x8b, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a,
  0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0x8a, 0xb5, 0xb5, 0xb5, 0xb5,
  0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5,
  0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5,
  0xb5, 0xb5, 0xb5, 0xb5, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4,
  0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4,
  0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4,
  0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7,
  0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7,
  0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb6, 0xb6, 0xb6, 0xb6,
  0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6,
  0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6,
  0xb6, 0xb6, 0xb6, 0xb6, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1,
  0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1,
  0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1, 0xb1,
  0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0,
  0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0,
  0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb3, 0xb3, 0xb3, 0xb3,
  0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3,
  0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3, 0xb3,
  0xb3, 0xb3, 0xb3, 0xb3, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2,
  0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2,
  0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2, 0xb2,
  0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd,
  0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd,
  0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbc, 0xbc, 0xbc, 0xbc,
  0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc,
  0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc, 0xbc,
  0xbc, 0xbc, 0xbc, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
  0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
  0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf,
  0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe,
  0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe,
  0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xbe, 0xb9, 0xb9, 0xb9, 0xb9,
  0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9,
  0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9, 0xb9,
  0xb9, 0xb9, 0xb9, 0xb9, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8,
  0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8,
  0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8, 0xb8,
  0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
  0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb,
  0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xba, 0xba, 0xba, 0xba,
  0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba,
  0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba, 0xba,
  0xba, 0xba, 0xba, 0xba, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5,
  0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5,
  0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5,
  0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5,
  0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5,
  0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa5, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7, 0xa7,
  0xa7, 0xa7, 0xa7, 0xa7, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6,
  0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6,
  0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6,
  0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6,
  0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6,
  0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa6, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1, 0xa1,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0,
  0xa0, 0xa0, 0xa0, 0xa0, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3,
  0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa3, 0xa2, 0xa2, 0xa2, 0xa2,
  0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2,
  0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2,
  0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2,
  0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2,
  0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2, 0xa2,
  0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad,
  0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad,
  0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad,
  0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad,
  0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad, 0xad,
  0xad, 0xad, 0xad, 0xad, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac,
  0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac,
  0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac,
  0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac,
  0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac,
  0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xac, 0xaf, 0xaf, 0xaf, 0xaf,
  0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf,
  0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf,
  0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf,
  0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf,
  0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xaf,
  0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae, 0xae,
  0xae, 0xae, 0xae, 0xae, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9,
  0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9,
  0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9,
  0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9,
  0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9,
  0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa9, 0xa8, 0xa8, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8,
  0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab,
  0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab,
  0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab,
  0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab,
  0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab, 0xab,
  0xab, 0xab, 0xab, 0xab, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x2a
};

static inline guint8
s16_to_alaw (gint16 pcm_val)
{
  if (pcm_val >= 0)
    return alaw_encode[pcm_val / 16];
  else
    return (0x7F & alaw_encode[pcm_val / -16]);
}

#else /* GST_ALAW_ENC_USE_TABLE */

/*
 * s16_to_alaw() - Convert a 16-bit linear PCM value to 8-bit A-law
 *
 * s16_to_alaw() accepts an 16-bit integer and encodes it as A-law data.
 *
 *              Linear Input Code       Compressed Code
 *      ------------------------        ---------------
 *      0000000wxyza                    000wxyz
 *      0000001wxyza                    001wxyz
 *      000001wxyzab                    010wxyz
 *      00001wxyzabc                    011wxyz
 *      0001wxyzabcd                    100wxyz
 *      001wxyzabcde                    101wxyz
 *      01wxyzabcdef                    110wxyz
 *      1wxyzabcdefg                    111wxyz
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */

static inline gint
val_seg (gint val)
{
  gint r = 1;

  val >>= 8;
  if (val & 0xf0) {
    val >>= 4;
    r += 4;
  }
  if (val & 0x0c) {
    val >>= 2;
    r += 2;
  }
  if (val & 0x02)
    r += 1;
  return r;
}

static inline guint8
s16_to_alaw (gint pcm_val)
{
  gint seg;
  guint8 mask;
  guint8 aval;

  if (pcm_val >= 0) {
    mask = 0xD5;
  } else {
    mask = 0x55;
    pcm_val = -pcm_val;
    if (pcm_val > 0x7fff)
      pcm_val = 0x7fff;
  }

  if (pcm_val < 256)
    aval = pcm_val >> 4;
  else {
    /* Convert the scaled magnitude to segment number. */
    seg = val_seg (pcm_val);
    aval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0x0f);
  }
  return aval ^ mask;
}

#endif /* GST_ALAW_ENC_USE_TABLE */

static gboolean
gst_alaw_enc_start (GstAudioEncoder * audioenc)
{
  GstALawEnc *alawenc = GST_ALAW_ENC (audioenc);

  alawenc->channels = 0;
  alawenc->rate = 0;

  return TRUE;
}

static gboolean
gst_alaw_enc_set_format (GstAudioEncoder * audioenc, GstAudioInfo * info)
{
  GstCaps *base_caps;
  GstStructure *structure;
  GstALawEnc *alawenc = GST_ALAW_ENC (audioenc);
  gboolean ret;

  alawenc->rate = info->rate;
  alawenc->channels = info->channels;

  base_caps =
      gst_pad_get_pad_template_caps (GST_AUDIO_ENCODER_SRC_PAD (audioenc));
  g_assert (base_caps);
  base_caps = gst_caps_make_writable (base_caps);
  g_assert (base_caps);

  structure = gst_caps_get_structure (base_caps, 0);
  g_assert (structure);
  gst_structure_set (structure, "rate", G_TYPE_INT, alawenc->rate, NULL);
  gst_structure_set (structure, "channels", G_TYPE_INT, alawenc->channels,
      NULL);

  ret = gst_audio_encoder_set_output_format (audioenc, base_caps);
  gst_caps_unref (base_caps);

  return ret;
}

static GstFlowReturn
gst_alaw_enc_handle_frame (GstAudioEncoder * audioenc, GstBuffer * buffer)
{
  GstALawEnc *alawenc;
  GstMapInfo inmap, outmap;
  gint16 *linear_data;
  gsize linear_size;
  guint8 *alaw_data;
  guint alaw_size;
  GstBuffer *outbuf;
  GstFlowReturn ret;
  gint i;

  if (!buffer) {
    ret = GST_FLOW_OK;
    goto done;
  }

  alawenc = GST_ALAW_ENC (audioenc);

  if (!alawenc->rate || !alawenc->channels)
    goto not_negotiated;

  gst_buffer_map (buffer, &inmap, GST_MAP_READ);
  linear_data = (gint16 *) inmap.data;
  linear_size = inmap.size;

  alaw_size = linear_size / 2;

  outbuf = gst_audio_encoder_allocate_output_buffer (audioenc, alaw_size);

  g_assert (outbuf);

  gst_buffer_map (outbuf, &outmap, GST_MAP_WRITE);
  alaw_data = outmap.data;

  for (i = 0; i < alaw_size; i++) {
    alaw_data[i] = s16_to_alaw (linear_data[i]);
  }

  gst_buffer_unmap (outbuf, &outmap);
  gst_buffer_unmap (buffer, &inmap);

  ret = gst_audio_encoder_finish_frame (audioenc, outbuf, -1);

done:
  return ret;

not_negotiated:
  {
    GST_DEBUG_OBJECT (alawenc, "no format negotiated");
    ret = GST_FLOW_NOT_NEGOTIATED;
    goto done;
  }
}

static void
gst_alaw_enc_class_init (GstALawEncClass * klass)
{
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);
  GstAudioEncoderClass *audio_encoder_class = GST_AUDIO_ENCODER_CLASS (klass);

  audio_encoder_class->start = GST_DEBUG_FUNCPTR (gst_alaw_enc_start);
  audio_encoder_class->set_format = GST_DEBUG_FUNCPTR (gst_alaw_enc_set_format);
  audio_encoder_class->handle_frame =
      GST_DEBUG_FUNCPTR (gst_alaw_enc_handle_frame);

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&alaw_enc_src_factory));
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&alaw_enc_sink_factory));

  gst_element_class_set_static_metadata (element_class,
      "A Law audio encoder", "Codec/Encoder/Audio",
      "Convert 16bit PCM to 8bit A law",
      "Zaheer Abbas Merali <zaheerabbas at merali dot org>");
  GST_DEBUG_CATEGORY_INIT (alaw_enc_debug, "alawenc", 0, "A Law audio encoder");
}

static void
gst_alaw_enc_init (GstALawEnc * alawenc)
{
  GST_PAD_SET_ACCEPT_TEMPLATE (GST_AUDIO_ENCODER_SINK_PAD (alawenc));
}