#include <Arduino.h>
unsigned char styles_min_css[] PROGMEM = {
  0x1f, 0x8b, 0x08, 0x08, 0xa7, 0xa2, 0xe6, 0x64, 0x00, 0x03, 0x73, 0x74,
  0x79, 0x6c, 0x65, 0x73, 0x2e, 0x6d, 0x69, 0x6e, 0x2e, 0x63, 0x73, 0x73,
  0x00, 0xad, 0x58, 0x5b, 0x6f, 0xf2, 0x36, 0x18, 0xbe, 0xdf, 0xaf, 0x60,
  0xad, 0x26, 0x7d, 0xdd, 0x08, 0x0a, 0x90, 0x50, 0x9a, 0x68, 0x95, 0x76,
  0xb7, 0xab, 0x5d, 0x6f, 0x9a, 0xbe, 0x0b, 0x27, 0xb1, 0xc1, 0xab, 0xb1,
  0x23, 0xdb, 0x29, 0xd0, 0x88, 0xff, 0x3e, 0x1f, 0x13, 0xe7, 0x40, 0xd5,
  0x49, 0x13, 0x6a, 0x1b, 0x1c, 0xfb, 0x3d, 0xbf, 0xcf, 0xf3, 0xba, 0x05,
  0xab, 0xae, 0x2d, 0x62, 0x54, 0x46, 0x67, 0x88, 0x0f, 0x47, 0x99, 0x25,
  0x71, 0x9c, 0x9b, 0xef, 0x08, 0x9c, 0x30, 0xb9, 0x66, 0x0f, 0xbf, 0x43,
  0xf2, 0x0e, 0x25, 0x2e, 0xc1, 0xe2, 0x0f, 0xd8, 0xc0, 0x87, 0x65, 0xf7,
  0x7d, 0xf9, 0x1b, 0xc7, 0x80, 0x2c, 0x05, 0xa0, 0x22, 0x12, 0x90, 0x63,
  0x64, 0xcf, 0x09, 0xfc, 0x01, 0xb3, 0x75, 0x52, 0x5f, 0xf2, 0x92, 0x11,
  0xc6, 0xb3, 0xc7, 0xb2, 0x2c, 0xf3, 0x02, 0x94, 0x6f, 0x07, 0xce, 0x1a,
  0x5a, 0x65, 0x8f, 0x9b, 0xcd, 0x26, 0x3f, 0x01, 0x7e, 0xc0, 0x34, 0x8b,
  0x6f, 0x2b, 0x46, 0x09, 0xa6, 0xb0, 0xed, 0x37, 0x44, 0xf6, 0x18, 0x62,
  0x1c, 0x0a, 0x79, 0xe0, 0x10, 0xd2, 0xc5, 0x8f, 0xf8, 0x54, 0x33, 0x2e,
  0x01, 0x95, 0xf9, 0x67, 0x2f, 0x6f, 0x2b, 0x02, 0xab, 0xf6, 0x68, 0xfd,
  0x58, 0x6f, 0x94, 0x05, 0x67, 0x5c, 0xc9, 0xa3, 0x7d, 0x2c, 0x18, 0xaf,
  0x20, 0xcf, 0xd6, 0x9d, 0x5d, 0x1c, 0x56, 0xb9, 0x56, 0x1d, 0xf9, 0x03,
  0x7a, 0xd3, 0xd8, 0x0a, 0xbd, 0xc9, 0x9e, 0x8c, 0x38, 0xa8, 0x70, 0x23,
  0xb2, 0x75, 0xac, 0xf6, 0x59, 0xf3, 0x23, 0xc9, 0xea, 0x4c, 0xc9, 0xbe,
  0xad, 0x28, 0x78, 0x2f, 0x00, 0x6f, 0x2b, 0x2c, 0x6a, 0x02, 0xae, 0x19,
  0x22, 0xf0, 0x92, 0xff, 0xd3, 0x08, 0x89, 0xd1, 0x55, 0x09, 0xa2, 0x12,
  0x52, 0x99, 0x89, 0x1a, 0x94, 0x30, 0x2a, 0xa0, 0x3c, 0x2b, 0xab, 0xa7,
  0x9a, 0x1e, 0xf7, 0xbb, 0xa2, 0x7a, 0x01, 0x79, 0xcd, 0x04, 0x96, 0x98,
  0xd1, 0x0c, 0xe1, 0x8b, 0x52, 0xee, 0x3c, 0x88, 0xe3, 0x9f, 0xf2, 0x8f,
  0x08, 0xd3, 0x0a, 0x5e, 0xb2, 0x97, 0x97, 0x17, 0x1d, 0x36, 0x86, 0x38,
  0x8c, 0x4e, 0x90, 0x36, 0xde, 0xe3, 0x64, 0xd7, 0x7b, 0xac, 0xf6, 0xdf,
  0x56, 0x08, 0x02, 0xd9, 0xa8, 0x40, 0x0d, 0xed, 0xd2, 0xbf, 0xa2, 0x0a,
  0x73, 0x58, 0x1a, 0x35, 0x9c, 0x9d, 0xed, 0xd2, 0x99, 0x83, 0x3a, 0xd3,
  0xbf, 0xf2, 0x83, 0x7a, 0xd0, 0x6e, 0x76, 0x12, 0x22, 0xac, 0x9c, 0x88,
  0x18, 0x42, 0x2d, 0xc2, 0x84, 0x64, 0x8f, 0x08, 0x21, 0xa7, 0x68, 0xab,
  0xa3, 0xe1, 0xf4, 0x9b, 0x67, 0x44, 0x18, 0x90, 0x19, 0x81, 0x48, 0x8e,
  0x4f, 0xd3, 0xee, 0x70, 0x81, 0xd6, 0xf7, 0xce, 0xf7, 0x87, 0x28, 0x38,
  0xc1, 0xd6, 0x86, 0xe6, 0x7c, 0xc4, 0x12, 0x0e, 0x72, 0x95, 0x04, 0x49,
  0xd0, 0xba, 0x6c, 0x56, 0x7a, 0xdd, 0x4e, 0xfa, 0xe6, 0x79, 0x20, 0xb2,
  0x60, 0x97, 0x69, 0x9d, 0x3d, 0x6e, 0xb7, 0x5b, 0x6f, 0xc1, 0x2e, 0xee,
  0x22, 0xa8, 0xda, 0xa0, 0x2b, 0x9a, 0x41, 0xea, 0xdd, 0x92, 0x3b, 0x9c,
  0x3c, 0x27, 0xbb, 0x64, 0xe7, 0x17, 0x85, 0xbc, 0x12, 0x98, 0x09, 0x46,
  0x70, 0x57, 0x35, 0x2e, 0x1f, 0xea, 0xe0, 0x20, 0x09, 0x35, 0xa8, 0x2a,
  0x4c, 0x0f, 0xb6, 0x34, 0x5d, 0x33, 0xd8, 0x90, 0xbf, 0x43, 0xae, 0x9b,
  0x8b, 0x44, 0xa5, 0x2a, 0x1a, 0xc8, 0x5b, 0xdf, 0x29, 0x7d, 0x61, 0x80,
  0x42, 0x69, 0x68, 0x54, 0x44, 0x74, 0xf9, 0xa5, 0xaa, 0x30, 0xa2, 0x93,
  0x88, 0x24, 0x57, 0x6d, 0xa8, 0xda, 0xe2, 0x94, 0x99, 0x27, 0x02, 0x24,
  0xfc, 0xeb, 0x5b, 0xa4, 0xde, 0x3e, 0xe5, 0xf7, 0x5f, 0x0d, 0xca, 0xe8,
  0x95, 0xe0, 0x57, 0xd0, 0x3a, 0xb3, 0x4d, 0x50, 0xb7, 0xf5, 0x65, 0x61,
  0x9c, 0x59, 0x98, 0x83, 0x35, 0xe0, 0xb0, 0xeb, 0x40, 0x53, 0x03, 0x61,
  0xe1, 0x49, 0x78, 0x91, 0x51, 0x05, 0x4b, 0xc6, 0x81, 0xb1, 0x92, 0x32,
  0x0a, 0xc7, 0xf2, 0x57, 0x40, 0xd5, 0xdc, 0x3b, 0x7c, 0x05, 0xcb, 0xf1,
  0x0b, 0xfd, 0x37, 0x62, 0x35, 0xa4, 0xd3, 0x77, 0xd9, 0x91, 0xa9, 0x98,
  0x28, 0xd3, 0x02, 0xc5, 0xce, 0xca, 0x82, 0x49, 0xc9, 0x4e, 0x59, 0xd2,
  0xd9, 0x69, 0x92, 0x39, 0x6f, 0x89, 0x90, 0x40, 0x8a, 0xa8, 0x06, 0x14,
  0x92, 0x76, 0x36, 0x15, 0xe9, 0xa0, 0x7b, 0xba, 0x26, 0x98, 0xeb, 0x97,
  0x51, 0x8f, 0x06, 0x68, 0x90, 0xa4, 0x73, 0x28, 0x62, 0xcc, 0x1a, 0xda,
  0xbc, 0xee, 0x6d, 0xd6, 0xf8, 0x38, 0xd7, 0xdb, 0x88, 0x31, 0x5d, 0x00,
  0x63, 0xe8, 0xec, 0x4a, 0x27, 0xed, 0x21, 0x36, 0x88, 0x89, 0xb6, 0x22,
  0x10, 0x5e, 0x6d, 0xaa, 0x5d, 0xa5, 0xdc, 0x77, 0x28, 0xd4, 0x9e, 0x94,
  0xa1, 0x2e, 0x6d, 0x9b, 0x54, 0xbb, 0x37, 0x10, 0xe7, 0x3c, 0xe1, 0xe6,
  0x3d, 0x68, 0x24, 0x1b, 0x34, 0x99, 0x59, 0x70, 0xfb, 0x8d, 0x1e, 0xdb,
  0x5e, 0x21, 0x14, 0x11, 0x2c, 0xa4, 0x6b, 0x03, 0x1d, 0xf6, 0xbc, 0xaf,
  0x5e, 0xa7, 0x26, 0x1e, 0xd7, 0x44, 0x3b, 0xdd, 0xd2, 0xb5, 0x0a, 0x36,
  0xdc, 0x10, 0x15, 0x84, 0x95, 0x6f, 0x33, 0xb5, 0x1a, 0x9a, 0x62, 0x1a,
  0xc9, 0x2f, 0xf4, 0x90, 0xe0, 0x57, 0xac, 0x47, 0x66, 0xc9, 0x0b, 0x77,
  0x52, 0x35, 0x28, 0x04, 0x09, 0xb4, 0x4d, 0xa8, 0x16, 0x55, 0x94, 0x80,
  0x8a, 0x67, 0x1b, 0x90, 0xd8, 0xf4, 0xa4, 0xcf, 0x51, 0x20, 0xc0, 0x04,
  0xd5, 0x94, 0x20, 0x20, 0xf8, 0xa0, 0xea, 0x45, 0x6b, 0x36, 0xd5, 0xb4,
  0x89, 0xc7, 0x28, 0x30, 0x2d, 0x2d, 0x2b, 0xb5, 0xd0, 0xa4, 0xdc, 0x25,
  0xe6, 0x0b, 0xc7, 0x7a, 0xf9, 0x43, 0x28, 0xbf, 0xfd, 0xbc, 0xcc, 0x00,
  0x52, 0x16, 0x2e, 0xb3, 0x02, 0x6a, 0xd2, 0x5c, 0x62, 0x5a, 0x37, 0xf2,
  0x6f, 0x79, 0xad, 0xe1, 0xaf, 0xe5, 0x11, 0x96, 0x6f, 0x4a, 0xdd, 0xf7,
  0x70, 0x51, 0x43, 0x1d, 0xfb, 0xde, 0xaa, 0x69, 0xa0, 0x78, 0xc3, 0x52,
  0x43, 0xa6, 0x26, 0x74, 0x6d, 0x47, 0x57, 0xbf, 0x17, 0x05, 0x38, 0xec,
  0x63, 0xfe, 0xd5, 0x0d, 0x61, 0x48, 0x2a, 0x01, 0x65, 0xdb, 0x67, 0xd3,
  0x31, 0x6f, 0x9c, 0xeb, 0xda, 0xb3, 0x1d, 0x16, 0x07, 0x03, 0x80, 0x46,
  0x26, 0x43, 0x92, 0x9c, 0x91, 0x76, 0x34, 0x41, 0x0c, 0xf8, 0x79, 0x95,
  0x6c, 0xf6, 0xe9, 0xf3, 0x3a, 0xd9, 0xce, 0x0f, 0x16, 0x61, 0xaf, 0x0d,
  0x32, 0xe5, 0xa9, 0xe6, 0x39, 0xed, 0xb9, 0x26, 0x09, 0x4b, 0x5f, 0xc1,
  0xd7, 0x22, 0x9c, 0x11, 0xe2, 0xb0, 0x33, 0x3f, 0x6d, 0xdb, 0x20, 0xef,
  0xfb, 0x09, 0x5d, 0x68, 0x07, 0x06, 0x71, 0x3c, 0x82, 0x8a, 0x9d, 0x55,
  0x51, 0xab, 0xf0, 0x2c, 0xe2, 0x85, 0x16, 0xa5, 0x7f, 0xf8, 0xa1, 0x00,
  0xdf, 0xe2, 0xa5, 0xfe, 0xac, 0xe2, 0xe7, 0xf4, 0x29, 0xff, 0x2f, 0x7b,
  0xbd, 0x7c, 0x03, 0xd0, 0x16, 0x93, 0x42, 0x82, 0x5a, 0xac, 0xd6, 0xa9,
  0x58, 0x40, 0x20, 0x14, 0x09, 0x2b, 0x0a, 0x6e, 0xe4, 0x72, 0x6a, 0xd0,
  0x64, 0x4f, 0x1e, 0xb1, 0xaf, 0xcb, 0xfb, 0x4c, 0xce, 0xff, 0x21, 0x44,
  0x21, 0xd7, 0x11, 0xd7, 0x77, 0x68, 0x3b, 0x1c, 0x0f, 0x3c, 0xa8, 0x05,
  0x38, 0xa0, 0x67, 0xb3, 0x85, 0x6e, 0x9f, 0x85, 0x7f, 0x18, 0x65, 0x28,
  0x35, 0xbd, 0x2e, 0x69, 0x3b, 0xa9, 0x04, 0x97, 0x58, 0x97, 0xf5, 0x78,
  0x3c, 0xd9, 0x8e, 0x07, 0xe6, 0xa0, 0xdf, 0x2d, 0x6d, 0xe7, 0xc6, 0xa8,
  0xc8, 0xcc, 0x7c, 0x0a, 0x09, 0xcd, 0x58, 0x65, 0x68, 0x9a, 0x35, 0xe5,
  0x31, 0x02, 0xb6, 0x71, 0x4f, 0x80, 0xe2, 0xba, 0x21, 0x86, 0xa5, 0xf2,
  0xfb, 0x6f, 0x7c, 0xca, 0x1a, 0xa1, 0x47, 0x0c, 0x48, 0x54, 0xdb, 0x5b,
  0x70, 0x35, 0x6d, 0x38, 0xb3, 0x2a, 0xa6, 0x8b, 0x93, 0x85, 0x7e, 0x1c,
  0x9e, 0xa1, 0xf8, 0x49, 0x1d, 0x9b, 0x28, 0x59, 0x22, 0x6e, 0x99, 0xf2,
  0x09, 0xcb, 0x6b, 0xb6, 0xd7, 0x23, 0xa6, 0x5a, 0x8e, 0x6a, 0x8e, 0x55,
  0xb8, 0xae, 0x03, 0x7e, 0x9e, 0xa6, 0x0b, 0x26, 0x45, 0xb2, 0x1d, 0x4d,
  0x4f, 0x9b, 0x9d, 0xfe, 0xdc, 0x3a, 0x6a, 0xdf, 0xef, 0x0b, 0xf4, 0x52,
  0xde, 0x21, 0x70, 0xad, 0xea, 0x0c, 0x38, 0x55, 0x79, 0xfa, 0x5c, 0x15,
  0x8a, 0x41, 0x95, 0xc0, 0x91, 0x2a, 0x08, 0xc1, 0x66, 0xbb, 0xb3, 0x52,
  0x2a, 0x40, 0x0f, 0x3d, 0xb2, 0xcf, 0x0b, 0xa9, 0x5e, 0xd2, 0x6d, 0x82,
  0x46, 0x42, 0xaa, 0x64, 0x8b, 0xb6, 0x40, 0x0b, 0x21, 0x91, 0x00, 0xef,
  0x50, 0xa5, 0x9c, 0xb4, 0xfe, 0x8e, 0xd1, 0x8f, 0xa4, 0x06, 0x0b, 0x06,
  0x54, 0xba, 0xde, 0xe9, 0x18, 0x8a, 0x33, 0x96, 0xe5, 0xb1, 0xed, 0xa6,
  0x07, 0x0e, 0x75, 0x86, 0xdf, 0xe1, 0x2c, 0xdf, 0x39, 0xd4, 0xda, 0x85,
  0x03, 0x72, 0xd2, 0x4b, 0x59, 0x18, 0xcc, 0xee, 0x92, 0x11, 0xe7, 0x1e,
  0x58, 0xdd, 0x5e, 0x05, 0xac, 0x42, 0xa5, 0x55, 0xb9, 0x39, 0x9d, 0x1b,
  0xcb, 0x86, 0x0b, 0xe5, 0x4e, 0xcd, 0xb0, 0x29, 0x55, 0x8d, 0x5e, 0x71,
  0x6e, 0x38, 0x33, 0xce, 0xad, 0xbd, 0x1a, 0xb4, 0x5d, 0xe5, 0x4f, 0x43,
  0xa3, 0x81, 0x6f, 0x06, 0x77, 0x56, 0x89, 0xc8, 0x87, 0x5f, 0xbd, 0x09,
  0x8e, 0x7b, 0xe6, 0x2c, 0x71, 0x77, 0xa3, 0x87, 0x87, 0xae, 0x7f, 0xfb,
  0x4b, 0x8c, 0x79, 0x34, 0x66, 0x25, 0xa6, 0x73, 0xfd, 0xac, 0x37, 0x35,
  0xc9, 0x22, 0xc0, 0xd7, 0x6c, 0x32, 0x71, 0xcb, 0x0c, 0xf7, 0xc1, 0xea,
  0x17, 0x1f, 0xa4, 0xa9, 0x97, 0x45, 0x0a, 0x41, 0xf9, 0xec, 0xb6, 0x23,
  0x56, 0x36, 0xa2, 0xdf, 0xdc, 0x03, 0x74, 0xec, 0xc0, 0x79, 0xb8, 0x7d,
  0x24, 0xdd, 0xfb, 0x3f, 0x30, 0x70, 0x38, 0x90, 0xff, 0xf9, 0x4d, 0x7b,
  0xfb, 0x74, 0x6f, 0x94, 0xf7, 0xaf, 0xef, 0xbf, 0xf2, 0xb1, 0x5e, 0x19,
  0x27, 0xda, 0x61, 0x07, 0xbb, 0xc2, 0x09, 0x36, 0x78, 0x93, 0x46, 0x78,
  0xa8, 0x5b, 0xfa, 0xc4, 0x2a, 0xd0, 0x8f, 0xc8, 0x06, 0x2c, 0x46, 0xf3,
  0xae, 0x1f, 0x56, 0xd7, 0xbe, 0x68, 0x6c, 0x05, 0x05, 0xc3, 0xb3, 0xa7,
  0x6c, 0xfd, 0xac, 0x41, 0x43, 0xdd, 0xcc, 0xce, 0x76, 0x7c, 0x9c, 0x06,
  0x3a, 0x8e, 0x67, 0x8a, 0x2c, 0x20, 0xba, 0x78, 0x95, 0x3c, 0x39, 0xab,
  0xfc, 0x5d, 0xfa, 0x0e, 0x1d, 0xb8, 0xee, 0xd3, 0xf7, 0xc8, 0x85, 0x51,
  0x16, 0x56, 0xc7, 0x04, 0xf0, 0x46, 0x77, 0xb7, 0xf0, 0x8e, 0xe7, 0xae,
  0x80, 0x76, 0x16, 0xb4, 0x9a, 0xdd, 0x34, 0xf8, 0x95, 0x39, 0x6c, 0x3d,
  0x77, 0x39, 0xf5, 0x72, 0x74, 0xf2, 0xe6, 0xef, 0x1f, 0x66, 0x00, 0x1f,
  0x89, 0x54, 0x0e, 0x34, 0x27, 0xda, 0x9f, 0x35, 0xc3, 0xe6, 0xdc, 0xe9,
  0xcf, 0x47, 0xde, 0x19, 0x43, 0x3f, 0xff, 0xef, 0xc4, 0x68, 0x20, 0x0e,
  0xef, 0x16, 0x26, 0x9a, 0x2e, 0x84, 0xeb, 0xe1, 0x40, 0xa5, 0xb8, 0x9a,
  0x30, 0x31, 0xbc, 0xb5, 0x07, 0x77, 0xf2, 0x21, 0x22, 0xa6, 0x9e, 0x46,
  0x0d, 0xab, 0x6e, 0xf6, 0xa3, 0x69, 0x2f, 0xed, 0xe5, 0x59, 0xde, 0x59,
  0xba, 0x2f, 0xa6, 0x15, 0xdb, 0x41, 0x93, 0xce, 0x12, 0xc6, 0x08, 0xe5,
  0x6e, 0x3f, 0xfc, 0x0b, 0x9b, 0x82, 0x6e, 0xc5, 0xea, 0x12, 0x00, 0x00
};
unsigned int styles_min_css_len = 1572;
