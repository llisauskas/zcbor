/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include "pet_decode.h"
#include "serial/serial_recovery_decode.h"
#include "zcbor_debug.h" // Enables use of print functions when debugging tests.

uint8_t serial_rec_input1[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0xdc, 0x37, 0x00,

	/* 280 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, /* "image" */ 0x65, 0x69, 0x6d, 0x61, 0x67, 0x65,
	0x00, /* "len" */ 0x63, 0x6c, 0x65, 0x6e, 0x19, 0x3b, 0x2c,
	/* "off" */ 0x63, 0x6f, 0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68,
	0x61, 0x58, 0x20, 0x12, 0x87, 0x4f, 0xfe, 0x60,
	0x5b, 0xe0, 0x63, 0x1a, 0x03, 0x5a, 0xa2, 0x11,
	0xb4, 0x3e, 0x0f, 0xb0, 0x20, 0x42, 0x0f, 0xc4,
	0x31, 0xa7, 0xf1, 0x1a, 0x6a, 0xd3, 0x44, 0x4c,
	0x71, 0x99, 0x75
};


uint8_t serial_rec_input2[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x90, 0x2c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,

	/* 11 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,

	/* 265 0xffs */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff,

	/* "image" */
	0x65, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, /* "len" */ 0x63,
	0x6c, 0x65, 0x6e, 0x19, 0x2f, 0xe0, /* "off" */ 0x63, 0x6f,
	0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68, 0x61, 0x58,
	0x20, 0x1d, 0x4f, 0x47, 0xe6, 0xdf, 0x78, 0xad,
	0x34, 0xe2, 0xd2, 0x8f, 0xc6, 0x7b, 0x3f, 0x26,
	0xff, 0x3c, 0x73, 0x44, 0x93, 0x13, 0x32, 0x7b,
	0x27, 0x15, 0xfa, 0x1d, 0x6e, 0x21, 0x82, 0xcb,
	0xfb
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector0[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x41, 0xe6, 0x42, 0x81, 0x01,
	0x4a, 0x8f, 0x7a, 0xd4, 0xf4, 0xd4, 0xd4, 0xd4, 0x7f, 0xff, 0xff, 0xff,
	0x01, 0x01, 0x01
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector1[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x49, 0xaa, 0x7a, 0x20, 0x98,
	0x44, 0xec, 0x38, 0x98, 0x5d, 0x21, 0x42, 0x81, 0x00, 0x00, 0x00, 0x00,
	0x04, 0x8f, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector2[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x49, 0xaa, 0xff, 0x7f, 0x01,
	0x5a, 0x85, 0xff, 0xa1, 0x5d, 0x21, 0x23, 0x81, 0x00, 0x00, 0xa1, 0x5d,
	0x21, 0x23, 0x81, 0x00, 0x00, 0x00, 0x04, 0x8f, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector3[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x49, 0xa2, 0x01, 0x5a, 0x00,
	0x5a, 0xa1, 0x19, 0x98, 0x5d, 0xd8, 0x30, 0xa2, 0x01, 0x48, 0x21, 0x42,
	0x81, 0x00, 0x00, 0x00, 0x00, 0x04, 0x8f, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector4[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x44, 0xaa, 0x98, 0x20, 0x01,
	0x4a, 0x8f, 0x98, 0x98, 0x7a, 0x98, 0x98, 0x98, 0x95, 0x98, 0x98, 0xff,
	0x01, 0x03, 0x01
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector5[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x92, 0x51, 0xaa, 0x9e, 0x9e, 0x9e,
	0x9a, 0x9e, 0x9e, 0x9e, 0x85, 0x92, 0x5a, 0xac, 0x98, 0x20, 0x98, 0x44,
	0x9e, 0x9e, 0x9e, 0x9e, 0x56, 0x56, 0x9e, 0x9e, 0x92, 0x51, 0xaa, 0x98,
	0x20, 0x98, 0x44, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e,
	0x9e, 0x9e, 0x9e, 0x9a, 0x9e, 0x9e, 0x9e, 0x9e, 0x9e, 0x00, 0x00, 0x00,
	0xff, 0x00, 0x00, 0x00, 0x04, 0x8f, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector6[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x41, 0xc6, 0x42, 0x8e, 0x01,
	0x4e, 0x8f, 0xd8, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0x7f, 0x7a, 0xff, 0xff,
	0xfe, 0xfe, 0x01
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector7[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x51, 0x98, 0x98, 0x98, 0x98,
	0x7a, 0x67, 0xa9, 0x98, 0x98, 0x98, 0x98, 0x98, 0xf0, 0x00, 0x00, 0x00,
	0x92, 0x30, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector8[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x94, 0x52, 0xe6, 0x42, 0x81, 0x01,
	0x48, 0x8f, 0x87, 0x5a, 0x98, 0xff, 0xff, 0xff, 0xe7, 0xd4, 0xd4, 0x9b,
	0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0xaa, 0x00, 0x20, 0x9f, 0xb7,
	0xec, 0x38, 0x98, 0xfe, 0x81, 0x42, 0x63, 0xf0, 0x00, 0x00, 0x00, 0x7f,
	0x30, 0xf3
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector9[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x6c, 0xc9, 0x02, 0xf6,
	0x39, 0xa8, 0x55, 0xec, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x58, 0x4a,
	0xb2, 0x82, 0x43, 0xa1, 0x01, 0x26, 0xa0, 0xf6, 0x7a, 0x40, 0xa1, 0xa5,
	0x03, 0x58, 0x6f, 0xa2, 0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58, 0x56,
	0x89, 0x14, 0xa4, 0x01, 0x50, 0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f,
	0xdf, 0xdd, 0x9d, 0xe6, 0x63, 0xe4, 0xd4, 0x1f, 0xfe, 0x02, 0x00, 0x04,
	0x00, 0x00, 0x14, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b, 0x2d, 0x51,
	0xf2, 0xab, 0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0xfe, 0xff, 0x11,
	0x22, 0x33, 0x44, 0x55
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector10[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xa1, 0x01, 0xf6, 0x58, 0x40, 0x8f, 0x95, 0x45, 0x8e,
	0x98, 0x98, 0x82, 0xa1, 0x9f, 0xd1, 0x0c, 0x3c, 0x17, 0xbe, 0xed, 0x32,
	0x1c, 0xec, 0xe7, 0x42, 0x3d, 0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0xf6,
	0xac, 0x83, 0x57, 0x7a, 0x3c, 0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x79,
	0x02, 0x37, 0x6b, 0x59, 0x54, 0x09, 0x20, 0xb6, 0xc5, 0xf5, 0x7b, 0xac,
	0x5f, 0xc8, 0x54, 0x3d, 0x8f, 0x5d, 0x3d, 0x97, 0x4f, 0xaa, 0x2e, 0x6d,
	0x03, 0xda, 0xa5, 0x34, 0x43, 0x82, 0x03, 0xb4, 0x43, 0xa7, 0x03, 0x58,
	0x71, 0xa5, 0x01, 0x01, 0x01, 0xfe, 0x03, 0x58, 0x5f, 0xa2, 0x02, 0x81,
	0x81, 0x41, 0x00, 0x04, 0x58, 0x56, 0x86, 0x14, 0xa4, 0x01, 0x50, 0xfa,
	0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe, 0x9d, 0xe6, 0x63, 0xe4,
	0xac, 0xd4, 0x1f, 0xfe, 0x02, 0x48, 0x8f, 0x87, 0x50, 0x14, 0x92, 0xaf,
	0x14, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b, 0x2d, 0x51, 0xf2, 0xab,
	0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0x20, 0x00, 0x11, 0x22, 0x33,
	0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
	0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe,
	0xdc, 0xba, 0xb6, 0x76, 0x54, 0x32, 0x10, 0x0e, 0x19, 0x87, 0x48, 0x8f,
	0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x43, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector11[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0x44, 0x55, 0x66, 0x77,
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f,
	0x87, 0x3b, 0x67, 0x89, 0xab, 0xcd, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xa1, 0x01, 0x26, 0xa0, 0xf6, 0x58, 0x24, 0xa1, 0x9f,
	0xd1, 0xf2, 0x3b, 0x17, 0xbe, 0x48, 0x48, 0x8f, 0x87, 0x48, 0x8f, 0x87,
	0x3a, 0x79, 0x02, 0x37, 0x6b, 0x59, 0x54, 0x09, 0x20, 0xb6, 0xc5, 0xf5,
	0x7b, 0xac, 0x5f, 0x21, 0x54, 0x3d, 0x8f, 0x5d, 0x3d, 0x97, 0x4f, 0xaa,
	0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a,
	0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a,
	0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x7a, 0x2e, 0x6d, 0x03, 0xda,
	0xa5, 0x34, 0xb4, 0x43, 0xa7, 0x03, 0x58, 0x48, 0x8f, 0x87, 0x01, 0x02,
	0x00, 0x03, 0x48, 0x5f, 0xa2, 0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58,
	0x56, 0x00, 0x00, 0x00, 0x80, 0x50, 0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad,
	0x5f, 0xdf, 0xbe, 0x9d, 0xe6, 0x72, 0xe4, 0xac, 0xd4, 0x1f, 0xfe, 0x02,
	0x48, 0x8f, 0x87, 0x50, 0x14, 0x97, 0xaf, 0x14, 0x25, 0x69, 0x48, 0x8f,
	0x87, 0x5e, 0x48, 0xbf, 0x42, 0x48, 0x8f, 0x87, 0xf2, 0xab, 0x45, 0x03,
	0x58, 0x24, 0x82, 0x02, 0x58, 0x20, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55,
	0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23,
	0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba,
	0x98, 0x76, 0x54, 0x32, 0x10, 0x0e, 0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02,
	0x0f, 0x00, 0x01, 0x00, 0x00, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector12[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xa1, 0x01, 0x26, 0xa0, 0xf6, 0x58, 0x40, 0xa1, 0x9f,
	0xd1, 0xf2, 0x3b, 0x17, 0xbe, 0xed, 0x32, 0x1c, 0xec, 0xe7, 0x42, 0x3d,
	0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0xf6, 0xac, 0x83, 0x57, 0x7a, 0x3c,
	0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x79, 0x02, 0x37, 0x6b, 0x59, 0x54,
	0x09, 0x20, 0xb6, 0xc5, 0xf5, 0x7b, 0xac, 0x5f, 0xc8, 0x54, 0x3d, 0x8f,
	0x5d, 0x3d, 0x97, 0x4f, 0xaa, 0x2e, 0x6d, 0x03, 0xda, 0xa5, 0x34, 0xb4,
	0x43, 0xa7, 0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58,
	0x5f, 0xa2, 0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58, 0x56, 0x86, 0x14,
	0xa4, 0x12, 0x50, 0x7a, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe,
	0x9d, 0xe6, 0x63, 0xe4, 0xac, 0xd4, 0x1f, 0xfe, 0x02, 0x48, 0x8f, 0x87,
	0x50, 0x14, 0x92, 0xaf, 0x14, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b,
	0x2d, 0x51, 0xf2, 0xab, 0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0x20,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
	0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89,
	0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x0e,
	0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x43, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector13[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x86, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x10,
	0x00, 0xe1, 0xe2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0x01, 0x99, 0x9b, 0x2d, 0x45, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xa1, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0xf6, 0xac, 0x83,
	0x34, 0x7a, 0x3c, 0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x58, 0x24, 0x82, 0x37,
	0x6b, 0x59, 0x54, 0x09, 0x58, 0x40, 0xa1, 0x9f, 0xd1, 0xf2, 0x3b, 0x17,
	0xbe, 0xed, 0x32, 0x1c, 0xec, 0xe7, 0x42, 0x3d, 0xde, 0x48, 0xc4, 0x57,
	0xb8, 0xf1, 0xf6, 0xac, 0x83, 0x34, 0x7a, 0x3c, 0x10, 0xc6, 0x77, 0x3f,
	0x6f, 0x58, 0x24, 0x82, 0x37, 0x6b, 0x59, 0x54, 0x09, 0x20, 0xb6, 0xc5,
	0xf5, 0x7b, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58, 0x5f, 0xa2,
	0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58, 0x56, 0x86, 0x14, 0xa4, 0x03,
	0x50, 0x33, 0x6b, 0xfe, 0x02, 0x48, 0x8f, 0x87, 0x50, 0x14, 0x92, 0xaf,
	0x14, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b, 0x2d, 0x51, 0xf2, 0xab,
	0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0x20, 0x00, 0x58, 0x98, 0x76,
	0x54, 0x32, 0x10, 0x0e, 0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a,
	0x43, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector14[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xa1, 0x01, 0x26, 0xa0, 0xf6, 0x58, 0x40, 0xa1, 0x9f,
	0xd1, 0xf2, 0x3b, 0x17, 0xbe, 0xed, 0x32, 0x1c, 0xec, 0xe7, 0x42, 0x3d,
	0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0xf6, 0xac, 0x83, 0x57, 0x7a, 0x3c,
	0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x79, 0x02, 0x37, 0x6b, 0x59, 0x54,
	0x09, 0x20, 0xb6, 0xc5, 0xf5, 0x7b, 0xac, 0x5f, 0xc8, 0x54, 0x3d, 0x8f,
	0x5d, 0x3d, 0x97, 0x4f, 0xaa, 0x2e, 0x6d, 0x03, 0xda, 0xa5, 0x34, 0xb4,
	0x43, 0xa7, 0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58,
	0x5f, 0xa2, 0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58, 0x56, 0x86, 0x14,
	0xa4, 0x01, 0x51, 0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe,
	0x9d, 0xe6, 0x63, 0xe4, 0xac, 0xd4, 0x1f, 0xfe, 0x12, 0x48, 0x7a, 0x87,
	0x50, 0x14, 0x92, 0xaf, 0x14, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b,
	0x2d, 0x51, 0xf2, 0xab, 0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0x20,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
	0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89,
	0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x0e,
	0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x43, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector15[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x00, 0x00, 0x7f,
	0xff, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x84, 0x43, 0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0xf6, 0xac, 0x83,
	0x3f, 0x7a, 0x3c, 0x10, 0xbd, 0x77, 0x3f, 0x6f, 0x3a, 0x79, 0x02, 0x37,
	0x6b, 0x59, 0x54, 0x09, 0x20, 0xb6, 0xc5, 0xf5, 0x7b, 0xac, 0x5f, 0xc8,
	0x54, 0x3d, 0x8f, 0x5d, 0x3d, 0x97, 0x4f, 0xaa, 0x2e, 0x6d, 0x03, 0xda,
	0xa5, 0x34, 0xb4, 0x43, 0xa7, 0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02,
	0x00, 0x03, 0x58, 0x5f, 0xff, 0x7f, 0x00, 0x00, 0x41, 0x00, 0x04, 0x58,
	0x56, 0x86, 0x14, 0xa4, 0x01, 0x50, 0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad,
	0x5f, 0xdf, 0xbe, 0x9d, 0x80, 0xff, 0xe4, 0xac, 0xd4, 0x1f, 0x18, 0x18,
	0x48, 0x8f, 0x87, 0x50, 0x14, 0x92, 0xaf, 0x14, 0x25, 0x69, 0x5e, 0x48,
	0xbf, 0x42, 0x9b, 0x2d, 0x51, 0xf2, 0xab, 0x00, 0x00, 0x58, 0x24, 0x82,
	0x02, 0x58, 0x80, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
	0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f, 0x87,
	0x3b, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54,
	0x32, 0x10, 0x0e, 0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x43,
	0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector16[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf1, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xb0, 0x84, 0x43, 0xa1, 0x01, 0x26, 0xa0, 0xf6, 0x52, 0x40, 0xa1, 0x9f,
	0xd1, 0xf2, 0x3b, 0x17, 0xbe, 0xed, 0x32, 0x1c, 0xec, 0xe7, 0x42, 0x3d,
	0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0x05, 0xff, 0xff, 0x05, 0x7a, 0x3c,
	0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x79, 0x02, 0x37, 0x6b, 0x59, 0x54,
	0x09, 0x20, 0xb6, 0xc5, 0xf5, 0x7b, 0xac, 0x5f, 0xc8, 0x54, 0x3d, 0x8f,
	0x5d, 0x3d, 0x97, 0x4f, 0xaa, 0x2e, 0x6d, 0x03, 0xda, 0xa5, 0x34, 0xb4,
	0x43, 0xa7, 0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58,
	0x5f, 0x00, 0x00, 0x00, 0x64, 0x41, 0x00, 0x08, 0x98, 0x56, 0x86, 0x14,
	0xa4, 0x01, 0x50, 0xfa, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe,
	0x9d, 0xe6, 0x63, 0xe4, 0xac, 0xd4, 0x1f, 0x0f, 0x03, 0x48, 0x8f, 0x87,
	0x50, 0x14, 0x92, 0xaf, 0x14, 0x55, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b,
	0x2d, 0x51, 0xf2, 0xab, 0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x58, 0x20,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x70, 0x99, 0xaa, 0xbb,
	0xcc, 0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89,
	0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x0e,
	0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x43, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector17[] = {
	0xd8, 0x30, 0xb8, 0xa2, 0x02, 0x58, 0x73, 0x82, 0x58, 0x24, 0x82, 0x02,
	0x58, 0x20, 0x5c, 0x01, 0x7e, 0xf6, 0x4b, 0xf3, 0xbb, 0x9b, 0x49, 0x4e,
	0x71, 0xe1, 0xf2, 0x41, 0x8e, 0xef, 0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d,
	0x5d, 0x9a, 0xf3, 0xe9, 0xed, 0xdb, 0x99, 0x9b, 0x2d, 0x51, 0x58, 0x4a,
	0xd2, 0x57, 0xb8, 0xf1, 0xf6, 0xac, 0x83, 0x3e, 0x7a, 0x3c, 0x10, 0xe8,
	0x77, 0x3f, 0x6f, 0x3a, 0x79, 0x02, 0x37, 0x6b, 0x4a, 0x53, 0xd5, 0xad,
	0x5f, 0xdf, 0xbe, 0x9d, 0xac, 0x5f, 0xda, 0xa5, 0x34, 0xb4, 0x43, 0xa7,
	0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58, 0x5f, 0xa2,
	0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x58, 0x56, 0x86, 0x14, 0xa4, 0x12,
	0x50, 0x82, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe, 0x9d, 0xe6,
	0x64, 0x1a, 0x00, 0x00, 0xfa, 0xfe, 0x02, 0x48, 0x8f, 0x87, 0x50, 0x14,
	0x92, 0xaf, 0x22, 0x25, 0x69, 0x5e, 0x48, 0xbf, 0x42, 0x9b, 0x2d, 0x51,
	0x94, 0x41, 0xe6, 0x42, 0x02, 0x58, 0x20, 0x00, 0x11, 0x22, 0x33, 0x44,
	0x55, 0x66, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
	0x82, 0x82, 0x81, 0xf3, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee,
	0xff, 0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89, 0xab, 0xcd, 0xef,
	0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x0e, 0x19, 0x87, 0xd0,
	0x01, 0x0f, 0x02, 0x0f, 0x0a, 0x46, 0x82, 0x03, 0x0f
};

/* Test vector discovered via fuzzing with AFL. */
uint8_t crash_vector18[] = {
	0xd8, 0x30, 0xa2, 0x01, 0x56, 0x85, 0x99, 0x41, 0xe6, 0x42, 0x81, 0x01,
	0x4a, 0xaf, 0xaf, 0x5d, 0x3d, 0x97, 0x5a, 0xff, 0xff, 0x01, 0x7e, 0xf6,
	0x77, 0xf3, 0xbb, 0x9b, 0x49, 0x10, 0x00, 0xe1, 0xf2, 0x41, 0x8e, 0xef,
	0x8d, 0x46, 0x5d, 0x5d, 0x5d, 0x5d, 0x5d, 0x9a, 0xd8, 0x30, 0xed, 0xdb,
	0x99, 0x9e, 0x2d, 0x51, 0x58, 0x4a, 0xd2, 0x84, 0x43, 0xa1, 0x0a, 0x26,
	0xa0, 0xf6, 0x58, 0x40, 0xa1, 0x9f, 0xd1, 0xf2, 0x3b, 0xff, 0xff, 0xed,
	0x32, 0x1c, 0xec, 0xe7, 0x42, 0x3d, 0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1,
	0x68, 0xac, 0x83, 0x57, 0x7a, 0x3c, 0x10, 0x1c, 0xec, 0xe7, 0x42, 0x3d,
	0xfb, 0x48, 0xc4, 0x57, 0xb8, 0xf1, 0x68, 0xac, 0x83, 0x57, 0x7a, 0x3c,
	0x10, 0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x71, 0x02, 0x37, 0x6b, 0x59, 0x54,
	0x02, 0x20, 0xb6, 0xc5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0x54, 0x3d, 0x8f,
	0xc6, 0x77, 0x3f, 0x6f, 0x3a, 0x71, 0x02, 0x37, 0x6b, 0x59, 0x54, 0x02,
	0x20, 0xb6, 0xc5, 0xf5, 0xff, 0xff, 0xff, 0xff, 0x54, 0x3d, 0x8f, 0x5d,
	0x3d, 0x97, 0x5a, 0xff, 0xff, 0x6d, 0x03, 0xda, 0xa5, 0x34, 0xb4, 0x43,
	0xa7, 0x03, 0x58, 0x71, 0xa5, 0x01, 0x01, 0x02, 0x00, 0x03, 0x58, 0x5f,
	0xa2, 0x02, 0x81, 0x81, 0x41, 0x00, 0x04, 0x7f, 0x56, 0x86, 0x14, 0xa4,
	0x03, 0x50, 0x33, 0x6b, 0x4a, 0x53, 0xd5, 0xad, 0x5f, 0xdf, 0xbe, 0x9d,
	0xe6, 0x63, 0xe4, 0x00, 0x00, 0x1f, 0xfe, 0x02, 0x18, 0x18, 0x05, 0x19,
	0x91, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x23,
	0x18, 0x18, 0x18, 0x45, 0x03, 0x58, 0x24, 0x82, 0x02, 0x49, 0x20, 0x00,
	0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc,
	0xdd, 0xee, 0xff, 0x01, 0x23, 0x48, 0x8f, 0x87, 0x3b, 0x67, 0x89, 0xab,
	0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0xa2, 0x7f, 0xff, 0x30, 0x8f,
	0x95, 0x64, 0x10, 0x00, 0x80, 0xff, 0xff, 0x81, 0xf3, 0x6f, 0x32, 0x10,
	0x0e, 0x19, 0x87, 0xd0, 0x01, 0x0f, 0x02, 0x0f, 0xf4, 0x43, 0x82, 0x03,
	0xb8
};


/* This test uses generated code to decode a 'Pet' instance. It constructs a
 * payload and runs the generated decoding function on the payload. It then
 * checks that the decoding was successful, and that the resulting struct is
 * populated correctly.
 */
void test_pet(void)
{
	struct Pet pet;
	size_t decode_len;
	uint8_t input[] = {
		0x83, 0x82, 0x63, 0x66, 0x6f, 0x6f, 0x63, 0x62, 0x61, 0x72,
		0x48, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
		0x02};
	zassert_equal(ZCBOR_SUCCESS, cbor_decode_Pet(input, sizeof(input), &pet, &decode_len), "");
	zassert_equal(sizeof(input), decode_len, NULL);

	uint8_t exp_birthday[] = {1,2,3,4,5,6,7,8};

	zassert_equal(2, pet.names_count, "Expect 2 names");
	zassert_mem_equal("foo", pet.names[0].value, 3, "Expect first name 'foo'");
	zassert_mem_equal("bar", pet.names[1].value, 3, "Expect first name 'bar'");
	zassert_equal(8, pet.birthday.len, "Expect len 8 birthday");
	zassert_mem_equal(exp_birthday, pet.birthday.value, 8, "Expect birthday");
	zassert_equal(_Pet_species_dog, pet.species_choice, "Expect dog");
}


bool fuzz_one_input(const uint8_t *data, size_t size);

#define FUZZ(x) fuzz_one_input(x, sizeof(x))

/* Run test cases discovered via fuzzing. */
void test_pet_regression(void)
{
	FUZZ(crash_vector0);
	FUZZ(crash_vector1);
	FUZZ(crash_vector2);
	FUZZ(crash_vector3);
	FUZZ(crash_vector4);
	FUZZ(crash_vector5);
	FUZZ(crash_vector6);
	FUZZ(crash_vector7);
	FUZZ(crash_vector8);
	FUZZ(crash_vector9);
	FUZZ(crash_vector10);
	FUZZ(crash_vector11);
	FUZZ(crash_vector12);
	FUZZ(crash_vector13);
	FUZZ(crash_vector14);
	FUZZ(crash_vector15);
	FUZZ(crash_vector16);
	FUZZ(crash_vector17);
	FUZZ(crash_vector18);
}

void test_serial1(void)
{
	struct Upload upload;
	size_t decode_len;
	bool ret = cbor_decode_Upload(serial_rec_input1,
			sizeof(serial_rec_input1), &upload, &decode_len);
	zassert_equal(ZCBOR_SUCCESS, ret, "decoding failed.");
	zassert_equal(sizeof(serial_rec_input1), decode_len, NULL);

	zassert_equal(5, upload.members_count,
		"expect 5 members");
	zassert_equal(_Member_data, upload.members[0].members
		.Member_choice, "expect data 1st");
	zassert_equal(_Member_image, upload.members[1].members
		.Member_choice, "expect image 2nd");
	zassert_equal(_Member_len, upload.members[2].members
		.Member_choice, "was %d\r\n", upload.members[2].members
		.Member_choice);
	zassert_equal(_Member_off, upload.members[3].members
		.Member_choice, "expect off 4th");
	zassert_equal(_Member_sha, upload.members[4].members
		.Member_choice, "expect sha 5th");
}

void test_serial2(void)
{
	struct Upload upload;
	size_t decode_len;
	bool ret = cbor_decode_Upload(serial_rec_input2,
			sizeof(serial_rec_input2), &upload, &decode_len);
	zassert_equal(ZCBOR_SUCCESS, ret, "decoding failed.");
	zassert_equal(sizeof(serial_rec_input2), decode_len, NULL);

	zassert_equal(5, upload.members_count,
		"expect 5 members");
	zassert_equal(_Member_data, upload.members[0].members
		.Member_choice, "expect data 1st");
	zassert_equal(_Member_image, upload.members[1].members
		.Member_choice, "expect image 2nd");
	zassert_equal(_Member_len, upload.members[2].members
		.Member_choice, "expect len 3rd");
	zassert_equal(_Member_off, upload.members[3].members
		.Member_choice, "expect off 4th");
	zassert_equal(_Member_sha, upload.members[4].members
		.Member_choice, "expect sha 5th");
}

void test_main(void)
{
	ztest_test_suite(cbor_decode_test3,
			 ztest_unit_test(test_pet),
			 ztest_unit_test(test_pet_regression),
			 ztest_unit_test(test_serial1),
			 ztest_unit_test(test_serial2)
	);
	ztest_run_test_suite(cbor_decode_test3);
}
