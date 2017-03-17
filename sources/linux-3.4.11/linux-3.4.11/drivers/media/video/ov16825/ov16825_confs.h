#ifndef __OV16825_CONFS__H__
#define __OV16825_CONFS__H__

#include "ov16825_common.h"

static struct regval_list ov16825_10bit_fullres_config[] = {
	/* PLL control */
	{0x0300, 0x02},
	{0x0302, 0x80},
	{0x0305, 0x05},
	{0x0306, 0x00},
	{0x030b, 0x03},
	{0x030c, 0x14},
	{0x030e, 0x00},
	{0x030f, 0x02},
	{0x0313, 0x02},
	{0x0314, 0x12},
	{0x031f, 0x00},
	{0x3018, 0x72},
	{0x3022, 0x01},
	{0x3607, 0x2b},
	{0x360b, 0x82},

	/* System control */
	{0x3031, 0x0a},
	{0x3032, 0x80},

	/* Analog control */
	{0x3601, 0xf8},
	{0x3602, 0x00},
	{0x3603, 0x00},
	{0x3604, 0x00},
	{0x3605, 0x50},
	{0x3606, 0x00},
	{0x3608, 0x16},
	{0x3609, 0x00},
	{0x360a, 0x00},
	{0x360c, 0x1a},
	{0x360d, 0x00},
	{0x360e, 0x99},
	{0x360f, 0x75},
	{0x3610, 0x69},
	{0x3611, 0x59},
	{0x3612, 0x40},
	{0x3613, 0x89},
	{0x3614, 0x77},
	{0x3615, 0x64},
	{0x3616, 0x30},
	{0x3617, 0x00},
	{0x3618, 0x20},
	{0x3619, 0x00},
	{0x361a, 0x10},
	{0x361c, 0x10},
	{0x361d, 0x00},
	{0x361e, 0x00},
	{0x3631, 0x60},
	{0x3638, 0x00},
	{0x3640, 0x15},
	{0x3641, 0x54},
	{0x3642, 0x63},
	{0x3643, 0x32},
	{0x3644, 0x03},
	{0x3645, 0x04},
	{0x3646, 0x85},
	{0x364a, 0x07},

	/* Sensor timing control */
	{0x3700, 0x60},
	{0x3701, 0x10},
	{0x3702, 0x22},
	{0x3703, 0x40},
	{0x3704, 0x10},
	{0x3705, 0x01},
	{0x3706, 0x34},
	{0x3707, 0x08},
	{0x3708, 0x40},
	{0x3709, 0x78},
	{0x370a, 0x03},
	{0x370a, 0x03},
	{0x370b, 0xe2},
	{0x370c, 0x06},
	{0x370e, 0x40},
	{0x370f, 0x0a},
	{0x3710, 0x30},
	{0x3711, 0x40},
	{0x3714, 0x31},
	{0x3718, 0x75},
	{0x3719, 0x25},
	{0x371a, 0x55},
	{0x371b, 0x05},
	{0x371c, 0x55},
	{0x371d, 0x05},
	{0x371e, 0x11},
	{0x371f, 0x2d},
	{0x3720, 0x15},
	{0x3721, 0x30},
	{0x3722, 0x15},
	{0x3723, 0x30},
	{0x3724, 0x08},
	{0x3725, 0x08},
	{0x3726, 0x04},
	{0x3727, 0x04},
	{0x3728, 0x04},
	{0x3729, 0x04},
	{0x372a, 0x29},
	{0x372b, 0xc9},
	{0x372c, 0xa9},
	{0x372d, 0xb9},
	{0x372e, 0x95},
	{0x372f, 0x55},
	{0x3730, 0x55},
	{0x3731, 0x55},
	{0x3732, 0x05},
	{0x3733, 0x80},
	{0x3734, 0x90},
	{0x3739, 0x05},
	{0x373a, 0x40},
	{0x373b, 0x18},
	{0x373c, 0x38},
	{0x373e, 0x15},
	{0x373f, 0x80},
	{0x3760, 0x00},
	{0x3761, 0x30},
	{0x3762, 0x00},
	{0x3763, 0xc0},
	{0x3764, 0x03},
	{0x3765, 0x00},

	/* System timing control */
	{0x3800, 0x00},
	{0x3801, 0x20},
	{0x3802, 0x00},
	{0x3803, 0x0e},
	{0x3804, 0x12},
	{0x3805, 0x3f},
	{0x3806, 0x0d},
	{0x3807, 0x93},
	{0x3808, 0x12},
	{0x3809, 0x00},
	{0x380a, 0x0d},
	{0x380b, 0x80},
	{0x380c, 0x0d},
	{0x380d, 0x1f},
	{0x380e, 0x0f},
	{0x380f, 0x1e},
	{0x3811, 0x0f},
	{0x3813, 0x02},
	{0x3814, 0x01},
	{0x3815, 0x01},
	{0x3820, 0x00},
	{0x3821, 0x06},
	{0x3823, 0x08},
	{0x3827, 0x02},
	{0x3828, 0x00},
	{0x3829, 0x00},
	{0x382a, 0x01},
	{0x382b, 0x01},
	{0x3830, 0x08},
	{0x3832, 0x00},
	{0x3833, 0x00},
	{0x3834, 0x00},

	/* OTP control */
	{0x3d85, 0x17},
	{0x3d8c, 0x70},
	{0x3d8d, 0xa0},

	/* ??? */
	{0x3f00, 0x02},

	/* BLC control */
	{0x4000, 0xe1},
	{0x4001, 0x83},

	/* ??? */
	{0x400e, 0x00},
	{0x4011, 0x00},
	{0x4012, 0x00},

	/* Frame control */
	{0x4200, 0x08},

	/* Clipping */
	{0x4302, 0x7f},
	{0x4303, 0xff},
	{0x4304, 0x00},
	{0x4305, 0x00},

	/* ??? */
	{0x4501, 0x30},

	/* VFIFO control */
	{0x4603, 0x60},

	/* LVDS control */
	{0x4b00, 0x22},

	/* ISP frame control */
	{0x4903, 0x00},

	/* DSP general control */
	{0x5000, 0x7f},
	{0x5001, 0x01},
	{0x5004, 0x00},

	/* ??? */
	{0x5013, 0x20},
	{0x5051, 0x00},

	/* OTP cluster correction control */
	{0x5500, 0x01},
	{0x5501, 0x00},
	{0x5502, 0x07},
	{0x5503, 0xff},
	{0x5505, 0x6c},
	{0x5509, 0x02},

	/* Defective pixel cancellation */
	{0x5780, 0xfc},
	{0x5781, 0xff},
	{0x5787, 0x40},
	{0x5788, 0x08},
	{0x578a, 0x02},
	{0x578b, 0x01},
	{0x578c, 0x01},
	{0x578e, 0x02},
	{0x578f, 0x01},
	{0x5790, 0x01},
	{0x5792, 0x00},

	/* Windowing and scaling control */
	{0x5980, 0x00},
	{0x5981, 0x21},
	{0x5982, 0x00},
	{0x5983, 0x00},
	{0x5984, 0x00},
	{0x5985, 0x00},
	{0x5986, 0x00},
	{0x5987, 0x00},
	{0x5988, 0x00},

	/* ??? */
	{0x3201, 0x15},
	{0x3202, 0x2a},
	{0x3f00, 0x02},
	{0x3f02, 0x00},
	{0x3f04, 0x00},
	{0x3f05, 0x00},
	{0x3f08, 0x40},

	{0x4002, 0x04},
	{0x4003, 0x08},
	{0x4306, 0x00},

	/* PCLK Period */
	{0x4837, 0x3a},

	/* EXPO */
	{0x3501, 0xA9},
	{0x3502, 0xe0},

	/* Stream On */
	{0x0100, 0x01},
};

static struct regval_list ov16825_10bit_12mp_config[] = {
	/* PLL control */
	{0x0300, 0x02},
	{0x0302, 0x74},
	{0x0305, 0x05},
	{0x0306, 0x00},
	{0x030b, 0x03},
	{0x030c, 0x13},
	{0x030e, 0x00},
	{0x030f, 0x02},
	{0x0313, 0x02},
	{0x0314, 0x12},
	{0x031f, 0x00},
	{0x3018, 0x72},
	{0x3022, 0x01},
	{0x3607, 0x2b},
	{0x360b, 0x82},

	/* System control */
	{0x3031, 0x0a},
	{0x3032, 0x80},

	/* Analog control */
	{0x3601, 0xf8},
	{0x3602, 0x00},
	{0x3603, 0x00},
	{0x3604, 0x00},
	{0x3605, 0x50},
	{0x3606, 0x00},
	{0x3608, 0x16},
	{0x3609, 0x00},
	{0x360a, 0x00},
	{0x360c, 0x1a},
	{0x360d, 0x00},
	{0x360e, 0x99},
	{0x360f, 0x75},
	{0x3610, 0x69},
	{0x3611, 0x59},
	{0x3612, 0x40},
	{0x3613, 0x89},
	{0x3614, 0x77},
	{0x3615, 0x64},
	{0x3616, 0x30},
	{0x3617, 0x00},
	{0x3618, 0x20},
	{0x3619, 0x00},
	{0x361a, 0x10},
	{0x361c, 0x10},
	{0x361d, 0x00},
	{0x361e, 0x00},
	{0x3631, 0x60},
	{0x3638, 0x00},
	{0x3640, 0x15},
	{0x3641, 0x54},
	{0x3642, 0x63},
	{0x3643, 0x32},
	{0x3644, 0x03},
	{0x3645, 0x04},
	{0x3646, 0x85},
	{0x364a, 0x07},

	/* Sensor timing control */
	{0x3700, 0x60},
	{0x3701, 0x10},
	{0x3702, 0x22},
	{0x3703, 0x40},
	{0x3704, 0x10},
	{0x3705, 0x01},
	{0x3706, 0x34},
	{0x3707, 0x08},
	{0x3708, 0x40},
	{0x3709, 0x78},
	{0x370a, 0x03},
	{0x370a, 0x03},
	{0x370b, 0xe2},
	{0x370c, 0x06},
	{0x370e, 0x40},
	{0x370f, 0x0a},
	{0x3710, 0x30},
	{0x3711, 0x40},
	{0x3714, 0x31},
	{0x3718, 0x75},
	{0x3719, 0x25},
	{0x371a, 0x55},
	{0x371b, 0x05},
	{0x371c, 0x55},
	{0x371d, 0x05},
	{0x371e, 0x11},
	{0x371f, 0x2d},
	{0x3720, 0x15},
	{0x3721, 0x30},
	{0x3722, 0x15},
	{0x3723, 0x30},
	{0x3724, 0x08},
	{0x3725, 0x08},
	{0x3726, 0x04},
	{0x3727, 0x04},
	{0x3728, 0x04},
	{0x3729, 0x04},
	{0x372a, 0x29},
	{0x372b, 0xc9},
	{0x372c, 0xa9},
	{0x372d, 0xb9},
	{0x372e, 0x95},
	{0x372f, 0x55},
	{0x3730, 0x55},
	{0x3731, 0x55},
	{0x3732, 0x05},
	{0x3733, 0x80},
	{0x3734, 0x90},
	{0x3739, 0x05},
	{0x373a, 0x40},
	{0x373b, 0x18},
	{0x373c, 0x38},
	{0x373e, 0x15},
	{0x373f, 0x80},
	{0x3760, 0x00},
	{0x3761, 0x30},
	{0x3762, 0x00},
	{0x3763, 0xc0},
	{0x3764, 0x03},
	{0x3765, 0x00},

	/* System timing control */
	{0x3800, 0x00},
	{0x3801, 0x20},
	{0x3802, 0x00},
	{0x3803, 0x0e},
	{0x3804, 0x12},
	{0x3805, 0x3f},
	{0x3806, 0x0d},
	{0x3807, 0x93},
	{0x3808, 0x0f},
	{0x3809, 0xa0},
	{0x380a, 0x0b},
	{0x380b, 0xb8},
	{0x380c, 0x09},
	{0x380d, 0x00},
	{0x380e, 0x0d},
	{0x380f, 0xa2},
	{0x3811, 0x0f},
	{0x3813, 0x02},
	{0x3814, 0x01},
	{0x3815, 0x01},
	{0x3820, 0x00},
	{0x3821, 0x06},
	{0x3823, 0x08},
	{0x3827, 0x02},
	{0x3828, 0x00},
	{0x3829, 0x00},
	{0x382a, 0x01},
	{0x382b, 0x01},
	{0x3830, 0x08},
	{0x3832, 0x00},
	{0x3833, 0x00},
	{0x3834, 0x00},

	/* OTP control */
	{0x3d85, 0x17},
	{0x3d8c, 0x70},
	{0x3d8d, 0xa0},

	/* ??? */
	{0x3f00, 0x02},

	/* BLC control */
	{0x4000, 0xe1},
	{0x4001, 0x83},

	/* ??? */
	{0x400e, 0x00},
	{0x4011, 0x00},
	{0x4012, 0x00},

	/* Frame control */
	{0x4200, 0x08},

	/* Clipping */
	{0x4302, 0x7f},
	{0x4303, 0xff},
	{0x4304, 0x00},
	{0x4305, 0x00},

	/* ??? */
	{0x4501, 0x30},

	/* VFIFO control */
	{0x4603, 0x60},

	/* LVDS control */
	{0x4b00, 0x22},

	/* ISP frame control */
	{0x4903, 0x00},

	/* DSP general control */
	{0x5000, 0xff},
	{0x5001, 0x01},
	{0x5004, 0x00},

	/* ??? */
	{0x5013, 0x20},
	{0x5051, 0x00},

	/* OTP cluster correction control */
	{0x5500, 0x01},
	{0x5501, 0x00},
	{0x5502, 0x07},
	{0x5503, 0xff},
	{0x5505, 0x6c},
	{0x5509, 0x02},

	/* Defective pixel cancellation */
	{0x5780, 0xfc},
	{0x5781, 0xff},
	{0x5787, 0x40},
	{0x5788, 0x08},
	{0x578a, 0x02},
	{0x578b, 0x01},
	{0x578c, 0x01},
	{0x578e, 0x02},
	{0x578f, 0x01},
	{0x5790, 0x01},
	{0x5792, 0x00},

	/* Windowing and scaling control */
	{0x5980, 0x00},
	{0x5981, 0x21},
	{0x5982, 0x00},
	{0x5983, 0x00},
	{0x5984, 0x00},
	{0x5985, 0x00},
	{0x5986, 0x00},
	{0x5987, 0x00},
	{0x5988, 0x00},

	/* ??? */
	{0x3201, 0x15},
	{0x3202, 0x2a},
	{0x3f00, 0x02},
	{0x3f02, 0x00},
	{0x3f04, 0x00},
	{0x3f05, 0x00},
	{0x3f08, 0x40},

	{0x4002, 0x04},
	{0x4003, 0x08},
	{0x4306, 0x00},

	/* PCLK Period */
	{0x4837, 0x3f},

	/* EXPO */
	{0x3501, 0xA9},
	{0x3502, 0xe0},

	/* Stream On */
	{0x0100, 0x01},
};


static struct regval_list ov16825_10bit_bining_config[] = {
	/* PLL control */
	{0x0300, 0x02},
	{0x0302, 0x74},
	{0x0305, 0x05},
	{0x0306, 0x00},
	{0x030b, 0x03},
	{0x030c, 0x13},
	{0x030e, 0x01},
	{0x030f, 0x02},
	{0x0313, 0x02},
	{0x0314, 0x12},
	{0x031f, 0x00},
	{0x3018, 0x72},
	{0x3022, 0x01},
	{0x3607, 0x2b},
	{0x360b, 0x82},

	/* System control */
	{0x3031, 0x0a},
	{0x3032, 0x80},

	/* Analog control */
	{0x3601, 0xf8},
	{0x3602, 0x00},
	{0x3603, 0x00},
	{0x3604, 0x00},
	{0x3605, 0x50},
	{0x3606, 0x00},
	{0x3608, 0x16},
	{0x3609, 0x00},
	{0x360a, 0x00},
	{0x360c, 0x1a},
	{0x360d, 0x00},
	{0x360e, 0x99},
	{0x360f, 0x75},
	{0x3610, 0x69},
	{0x3611, 0x59},
	{0x3612, 0x40},
	{0x3613, 0x89},
	{0x3614, 0x77},
	{0x3615, 0x64},
	{0x3616, 0x30},
	{0x3617, 0x00},
	{0x3618, 0x20},
	{0x3619, 0x00},
	{0x361a, 0x10},
	{0x361c, 0x10},
	{0x361d, 0x00},
	{0x361e, 0x00},
	{0x3631, 0x60},
	{0x3638, 0x00},
	{0x3640, 0x15},
	{0x3641, 0x54},
	{0x3642, 0x63},
	{0x3643, 0x32},
	{0x3644, 0x03},
	{0x3645, 0x04},
	{0x3646, 0x85},
	{0x364a, 0x07},

	/* Sensor timing control */
	{0x3700, 0x30},
	{0x3701, 0x08},
	{0x3702, 0x11},
	{0x3703, 0x20},
	{0x3704, 0x08},
	{0x3705, 0x00},
	{0x3706, 0x9a},
	{0x3708, 0x20},
	{0x3709, 0x3c},
	{0x370a, 0x01},
	{0x370b, 0x6f},
	{0x370c, 0x03},
	{0x370e, 0x20},
	{0x370f, 0x05},
	{0x3710, 0x20},
	{0x3711, 0x20},
	{0x3714, 0x31},
	{0x3719, 0x13},
	{0x371b, 0x03},
	{0x371d, 0x03},
	{0x371e, 0x09},
	{0x371f, 0x17},
	{0x3720, 0x0b},
	{0x3721, 0x18},
	{0x3722, 0x0b},
	{0x3723, 0x18},
	{0x3724, 0x04},
	{0x3725, 0x04},
	{0x3726, 0x02},
	{0x3727, 0x02},
	{0x3728, 0x02},
	{0x3729, 0x02},
	{0x372a, 0x25},
	{0x372b, 0x65},
	{0x372c, 0x55},
	{0x372d, 0x65},
	{0x372e, 0x53},
	{0x372f, 0x33},
	{0x3730, 0x33},
	{0x3731, 0x33},
	{0x3732, 0x03},
	{0x3734, 0x90},
	{0x3739, 0x03},
	{0x373a, 0x20},
	{0x373b, 0x0c},
	{0x373c, 0x1c},
	{0x373e, 0x0b},
	{0x373f, 0x80},

	/* System timing control */
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x12},
	{0x3805, 0x3f},
	{0x3806, 0x0d},
	{0x3807, 0x97},
	{0x3808, 0x09},
	{0x3809, 0x00},
	{0x380a, 0x06},
	{0x380b, 0xc0},
	{0x380c, 0x04},
	{0x380d, 0x76},
	{0x380e, 0x0a},
	{0x380f, 0xa2},
	{0x3811, 0x17},
	{0x3813, 0x02},
	{0x3814, 0x03},
	{0x3815, 0x01},
	{0x3820, 0x01},
	{0x3821, 0x07},
	{0x3823, 0x08},
	{0x3827, 0x02},
	{0x3828, 0x00},
	{0x3829, 0x02},
	{0x382a, 0x03},
	{0x382b, 0x01},
	{0x3830, 0x08},
	{0x3832, 0x00},
	{0x3833, 0x00},
	{0x3834, 0x00},

	/* OTP control */
	{0x3d85, 0x17},
	{0x3d8c, 0x70},
	{0x3d8d, 0xa0},

	/* ??? */
	{0x3f00, 0x02},

	/* BLC control */
	{0x4000, 0xe1},
	{0x4001, 0x83},

	/* ??? */
	{0x400e, 0x00},
	{0x4011, 0x00},
	{0x4012, 0x00},

	/* Frame control */
	{0x4200, 0x08},

	/* Clipping */
	{0x4302, 0x7f},
	{0x4303, 0xff},
	{0x4304, 0x00},
	{0x4305, 0x00},

	/* ??? */
	{0x4501, 0x30},

	/* VFIFO control */
	{0x4603, 0x60},

	/* LVDS control */
	{0x4b00, 0x22},

	/* ISP frame control */
	{0x4903, 0x00},

	/* DSP general control */
	{0x5000, 0x7f},
	{0x5001, 0x01},
	{0x5004, 0x00},

	/* ??? */
	{0x5013, 0x20},
	{0x5051, 0x00},

	/* OTP cluster correction control */
	{0x5500, 0x01},
	{0x5501, 0x00},
	{0x5502, 0x07},
	{0x5503, 0xff},
	{0x5505, 0x6c},
	{0x5509, 0x02},

	/* Defective pixel cancellation */
	{0x5780, 0xfc},
	{0x5781, 0xff},
	{0x5787, 0x40},
	{0x5788, 0x08},
	{0x578a, 0x02},
	{0x578b, 0x01},
	{0x578c, 0x01},
	{0x578e, 0x02},
	{0x578f, 0x01},
	{0x5790, 0x01},
	{0x5792, 0x00},

	/* Windowing and scaling control */
	{0x5980, 0x00},
	{0x5981, 0x21},
	{0x5982, 0x00},
	{0x5983, 0x00},
	{0x5984, 0x00},
	{0x5985, 0x00},
	{0x5986, 0x00},
	{0x5987, 0x00},
	{0x5988, 0x00},

	/* ??? */
	{0x3201, 0x15},
	{0x3202, 0x2a},
	{0x3f00, 0x02},
	{0x3f02, 0x00},
	{0x3f04, 0x00},
	{0x3f05, 0x00},
	{0x3f08, 0x40},

	{0x4002, 0x04},
	{0x4003, 0x08},
	{0x4306, 0x00},

	/* PCLK Period */
	{0x4837, 0x3f},

	/* EXPO */
	{0x3501, 0xA9},
	{0x3502, 0xe0},

	/* Stream On */
	{0x0100, 0x01},
};

static struct regval_list ov16825_10bit_1080p_config[] = {
	/* PLL control */
	{0x0300, 0x02},
	{0x0302, 0x74},
	{0x0305, 0x05},
	{0x0306, 0x00},
	{0x030b, 0x03},
	{0x030c, 0x13},
	{0x030e, 0x01},
	{0x030f, 0x02},
	{0x0313, 0x02},
	{0x0314, 0x12},
	{0x031f, 0x00},
	{0x3018, 0x72},
	{0x3022, 0x01},
	{0x3607, 0x2b},
	{0x360b, 0x82},

	/* System control */
	{0x3031, 0x0a},
	{0x3032, 0x80},

	/* Analog control */
	{0x3601, 0xf8},
	{0x3602, 0x00},
	{0x3603, 0x00},
	{0x3604, 0x00},
	{0x3605, 0x50},
	{0x3606, 0x00},
	{0x3608, 0x16},
	{0x3609, 0x00},
	{0x360a, 0x00},
	{0x360c, 0x1a},
	{0x360d, 0x00},
	{0x360e, 0x99},
	{0x360f, 0x75},
	{0x3610, 0x69},
	{0x3611, 0x59},
	{0x3612, 0x40},
	{0x3613, 0x89},
	{0x3614, 0x77},
	{0x3615, 0x64},
	{0x3616, 0x30},
	{0x3617, 0x00},
	{0x3618, 0x20},
	{0x3619, 0x00},
	{0x361a, 0x10},
	{0x361c, 0x10},
	{0x361d, 0x00},
	{0x361e, 0x00},
	{0x3631, 0x60},
	{0x3638, 0x00},
	{0x3640, 0x15},
	{0x3641, 0x54},
	{0x3642, 0x63},
	{0x3643, 0x32},
	{0x3644, 0x03},
	{0x3645, 0x04},
	{0x3646, 0x85},
	{0x364a, 0x07},

	/* Sensor timing control */
	{0x3700, 0x30},
	{0x3701, 0x08},
	{0x3702, 0x11},
	{0x3703, 0x20},
	{0x3704, 0x08},
	{0x3705, 0x00},
	{0x3706, 0x9a},
	{0x3708, 0x20},
	{0x3709, 0x3c},
	{0x370a, 0x01},
	{0x370b, 0x6f},
	{0x370c, 0x03},
	{0x370e, 0x20},
	{0x370f, 0x05},
	{0x3710, 0x20},
	{0x3711, 0x20},
	{0x3714, 0x31},
	{0x3719, 0x13},
	{0x371b, 0x03},
	{0x371d, 0x03},
	{0x371e, 0x09},
	{0x371f, 0x17},
	{0x3720, 0x0b},
	{0x3721, 0x18},
	{0x3722, 0x0b},
	{0x3723, 0x18},
	{0x3724, 0x04},
	{0x3725, 0x04},
	{0x3726, 0x02},
	{0x3727, 0x02},
	{0x3728, 0x02},
	{0x3729, 0x02},
	{0x372a, 0x25},
	{0x372b, 0x65},
	{0x372c, 0x55},
	{0x372d, 0x65},
	{0x372e, 0x53},
	{0x372f, 0x33},
	{0x3730, 0x33},
	{0x3731, 0x33},
	{0x3732, 0x03},
	{0x3734, 0x90},
	{0x3739, 0x03},
	{0x373a, 0x20},
	{0x373b, 0x0c},
	{0x373c, 0x1c},
	{0x373e, 0x0b},
	{0x373f, 0x80},

	/* System timing control */
	{0x3800, 0x01},
	{0x3801, 0x80},
	{0x3802, 0x02},
	{0x3803, 0x94},
	{0x3804, 0x10},
	{0x3805, 0xbf},
	{0x3806, 0x0b},
	{0x3807, 0x0f},
	{0x3808, 0x07},
	{0x3809, 0x80},
	{0x380a, 0x04},
	{0x380b, 0x38},
	{0x380c, 0x03},
	{0x380d, 0xf7},
	{0x380e, 0x04},
	{0x380f, 0x50},
	{0x3811, 0x17},
	{0x3813, 0x02},
	{0x3814, 0x03},
	{0x3815, 0x01},
	{0x3820, 0x01},
	{0x3821, 0x07},
	{0x3823, 0x08},
	{0x3827, 0x02},
	{0x3828, 0x00},
	{0x3829, 0x02},
	{0x382a, 0x03},
	{0x382b, 0x01},
	{0x3830, 0x08},
	{0x3832, 0x00},
	{0x3833, 0x00},
	{0x3834, 0x00},

	/* OTP control */
	{0x3d85, 0x17},
	{0x3d8c, 0x70},
	{0x3d8d, 0xa0},

	/* ??? */
	{0x3f00, 0x02},

	/* BLC control */
	{0x4000, 0xe1},
	{0x4001, 0x83},

	/* ??? */
	{0x400e, 0x00},
	{0x4011, 0x00},
	{0x4012, 0x00},

	/* Frame control */
	{0x4200, 0x08},

	/* Clipping */
	{0x4302, 0x7f},
	{0x4303, 0xff},
	{0x4304, 0x00},
	{0x4305, 0x00},

	/* ??? */
	{0x4501, 0x30},

	/* VFIFO control */
	{0x4603, 0x60},

	/* LVDS control */
	{0x4b00, 0x22},

	/* ISP frame control */
	{0x4903, 0x00},

	/* DSP general control */
	{0x5000, 0x7f},
	{0x5001, 0x01},
	{0x5004, 0x00},

	/* ??? */
	{0x5013, 0x20},
	{0x5051, 0x00},

	/* OTP cluster correction control */
	{0x5500, 0x01},
	{0x5501, 0x00},
	{0x5502, 0x07},
	{0x5503, 0xff},
	{0x5505, 0x6c},
	{0x5509, 0x02},

	/* Defective pixel cancellation */
	{0x5780, 0xfc},
	{0x5781, 0xff},
	{0x5787, 0x40},
	{0x5788, 0x08},
	{0x578a, 0x02},
	{0x578b, 0x01},
	{0x578c, 0x01},
	{0x578e, 0x02},
	{0x578f, 0x01},
	{0x5790, 0x01},
	{0x5792, 0x00},

	/* Windowing and scaling control */
	{0x5980, 0x00},
	{0x5981, 0x21},
	{0x5982, 0x00},
	{0x5983, 0x00},
	{0x5984, 0x00},
	{0x5985, 0x00},
	{0x5986, 0x00},
	{0x5987, 0x00},
	{0x5988, 0x00},

	/* ??? */
	{0x3201, 0x15},
	{0x3202, 0x2a},
	{0x3f00, 0x02},
	{0x3f02, 0x00},
	{0x3f04, 0x00},
	{0x3f05, 0x00},
	{0x3f08, 0x40},

	{0x4002, 0x04},
	{0x4003, 0x08},
	{0x4306, 0x00},

	/* PCLK Period */
	{0x4837, 0x3f},

	/* EXPO */
	{0x3501, 0x40},
	{0x3502, 0xe0},

	/* Stream On */
	{0x0100, 0x01},
};

static struct regval_list ov16825_10bit_1200p_config[] = {
	/* PLL control */
	{0x0300, 0x02},
	{0x0302, 0x74},
	{0x0305, 0x05},
	{0x0306, 0x00},
	{0x030b, 0x03},
	{0x030c, 0x13},
	{0x030e, 0x01},
	{0x030f, 0x02},
	{0x0313, 0x02},
	{0x0314, 0x12},
	{0x031f, 0x00},
	{0x3018, 0x72},
	{0x3022, 0x01},
	{0x3607, 0x2b},
	{0x360b, 0x82},

	/* System control */
	{0x3031, 0x0a},
	{0x3032, 0x80},

	/* Analog control */
	{0x3601, 0xf8},
	{0x3602, 0x00},
	{0x3603, 0x00},
	{0x3604, 0x00},
	{0x3605, 0x50},
	{0x3606, 0x00},
	{0x3608, 0x16},
	{0x3609, 0x00},
	{0x360a, 0x00},
	{0x360c, 0x1a},
	{0x360d, 0x00},
	{0x360e, 0x99},
	{0x360f, 0x75},
	{0x3610, 0x69},
	{0x3611, 0x59},
	{0x3612, 0x40},
	{0x3613, 0x89},
	{0x3614, 0x77},
	{0x3615, 0x64},
	{0x3616, 0x30},
	{0x3617, 0x00},
	{0x3618, 0x20},
	{0x3619, 0x00},
	{0x361a, 0x10},
	{0x361c, 0x10},
	{0x361d, 0x00},
	{0x361e, 0x00},
	{0x3631, 0x60},
	{0x3638, 0x00},
	{0x3640, 0x15},
	{0x3641, 0x54},
	{0x3642, 0x63},
	{0x3643, 0x32},
	{0x3644, 0x03},
	{0x3645, 0x04},
	{0x3646, 0x85},
	{0x364a, 0x07},

	/* Sensor timing control */
	{0x3700, 0x30},
	{0x3701, 0x08},
	{0x3702, 0x11},
	{0x3703, 0x20},
	{0x3704, 0x08},
	{0x3705, 0x00},
	{0x3706, 0x9a},
	{0x3708, 0x20},
	{0x3709, 0x3c},
	{0x370a, 0x01},
	{0x370b, 0x6f},
	{0x370c, 0x03},
	{0x370e, 0x20},
	{0x370f, 0x05},
	{0x3710, 0x20},
	{0x3711, 0x20},
	{0x3714, 0x31},
	{0x3719, 0x13},
	{0x371b, 0x03},
	{0x371d, 0x03},
	{0x371e, 0x09},
	{0x371f, 0x17},
	{0x3720, 0x0b},
	{0x3721, 0x18},
	{0x3722, 0x0b},
	{0x3723, 0x18},
	{0x3724, 0x04},
	{0x3725, 0x04},
	{0x3726, 0x02},
	{0x3727, 0x02},
	{0x3728, 0x02},
	{0x3729, 0x02},
	{0x372a, 0x25},
	{0x372b, 0x65},
	{0x372c, 0x55},
	{0x372d, 0x65},
	{0x372e, 0x53},
	{0x372f, 0x33},
	{0x3730, 0x33},
	{0x3731, 0x33},
	{0x3732, 0x03},
	{0x3734, 0x90},
	{0x3739, 0x03},
	{0x373a, 0x20},
	{0x373b, 0x0c},
	{0x373c, 0x1c},
	{0x373e, 0x0b},
	{0x373f, 0x80},

	/* System timing control */
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x12},
	{0x3805, 0x3f},
	{0x3806, 0x0d},
	{0x3807, 0x97},
	{0x3808, 0x06},
	{0x3809, 0x40},
	{0x380a, 0x04},
	{0x380b, 0xb0},
	{0x380c, 0x03},
	{0x380d, 0xf7},
	{0x380e, 0x06},
	{0x380f, 0xd0},
	{0x3811, 0x17},
	{0x3813, 0x02},
	{0x3814, 0x03},
	{0x3815, 0x01},
	{0x3820, 0x01},
	{0x3821, 0x07},
	{0x3823, 0x08},
	{0x3827, 0x02},
	{0x3828, 0x00},
	{0x3829, 0x02},
	{0x382a, 0x03},
	{0x382b, 0x01},
	{0x3830, 0x08},
	{0x3832, 0x00},
	{0x3833, 0x00},
	{0x3834, 0x00},

	/* OTP control */
	{0x3d85, 0x17},
	{0x3d8c, 0x70},
	{0x3d8d, 0xa0},

	/* ??? */
	{0x3f00, 0x02},

	/* BLC control */
	{0x4000, 0xe1},
	{0x4001, 0x83},

	/* ??? */
	{0x400e, 0x00},
	{0x4011, 0x00},
	{0x4012, 0x00},

	/* Frame control */
	{0x4200, 0x08},

	/* Clipping */
	{0x4302, 0x7f},
	{0x4303, 0xff},
	{0x4304, 0x00},
	{0x4305, 0x00},

	/* ??? */
	{0x4501, 0x30},

	/* VFIFO control */
	{0x4603, 0x60},

	/* LVDS control */
	{0x4b00, 0x22},

	/* ISP frame control */
	{0x4903, 0x00},

	/* DSP general control */
	{0x5000, 0xff},
	{0x5001, 0x01},
	{0x5004, 0x00},

	/* ??? */
	{0x5013, 0x20},
	{0x5051, 0x00},

	/* OTP cluster correction control */
	{0x5500, 0x01},
	{0x5501, 0x00},
	{0x5502, 0x07},
	{0x5503, 0xff},
	{0x5505, 0x6c},
	{0x5509, 0x02},

	/* Defective pixel cancellation */
	{0x5780, 0xfc},
	{0x5781, 0xff},
	{0x5787, 0x40},
	{0x5788, 0x08},
	{0x578a, 0x02},
	{0x578b, 0x01},
	{0x578c, 0x01},
	{0x578e, 0x02},
	{0x578f, 0x01},
	{0x5790, 0x01},
	{0x5792, 0x00},

	/* Windowing and scaling control */
	{0x5980, 0x00},
	{0x5981, 0x21},
	{0x5982, 0x00},
	{0x5983, 0x00},
	{0x5984, 0x00},
	{0x5985, 0x00},
	{0x5986, 0x00},
	{0x5987, 0x00},
	{0x5988, 0x00},

	/* ??? */
	{0x3201, 0x15},
	{0x3202, 0x2a},
	{0x3f00, 0x02},
	{0x3f02, 0x00},
	{0x3f04, 0x00},
	{0x3f05, 0x00},
	{0x3f08, 0x40},

	{0x4002, 0x04},
	{0x4003, 0x08},
	{0x4306, 0x00},

	/* PCLK Period */
	{0x4837, 0x3f},

	/* EXPO */
	{0x3501, 0x40},
	{0x3502, 0xe0},

	/* Stream On */
	{0x0100, 0x01},
};

static struct ov16825_config ov16825_configs[] = {
#define MAKE_CONFIG(w, h, l, c) { .width = (w), .height = (h),		\
				  .line_duration_us = (l),		\
				  .regs = (c), .regs_len = ARRAY_SIZE(c), }
	// The first config in this table will be used as default
	MAKE_CONFIG(4608, 3456, 48, ov16825_10bit_fullres_config),
	MAKE_CONFIG(4000, 3000, 37, ov16825_10bit_12mp_config),
	MAKE_CONFIG(2304, 1728, 33, ov16825_10bit_bining_config),
	MAKE_CONFIG(1920, 1080, 33, ov16825_10bit_1080p_config),
	MAKE_CONFIG(1600, 1200, 33, ov16825_10bit_1200p_config),
};

#endif /*__OV16825_CONFS__H__*/
