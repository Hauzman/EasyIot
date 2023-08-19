#include <Arduino.h>
unsigned char styles_min_css PROGMEM[] = {
  0x1f, 0x8b, 0x08, 0x08, 0x8f, 0xea, 0xe0, 0x64, 0x00, 0x03, 0x73, 0x74,
  0x79, 0x6c, 0x65, 0x73, 0x2e, 0x6d, 0x69, 0x6e, 0x2e, 0x63, 0x73, 0x73,
  0x00, 0xad, 0x56, 0xdb, 0x8e, 0xa4, 0x36, 0x10, 0x7d, 0xcf, 0x57, 0x90,
  0x19, 0x8d, 0xb4, 0x1b, 0x35, 0x88, 0x7b, 0x77, 0x83, 0x32, 0x4a, 0xde,
  0xf2, 0x94, 0x1f, 0x88, 0xf6, 0xc1, 0x60, 0xd3, 0x58, 0x63, 0x6c, 0x64,
  0xcc, 0x74, 0xf7, 0xa2, 0xfe, 0xf7, 0xd8, 0xc6, 0xdc, 0xe9, 0x55, 0x56,
  0x4a, 0xa3, 0xd1, 0x98, 0x2a, 0xbb, 0x28, 0x9f, 0x53, 0x2e, 0x9f, 0x8c,
  0xc1, 0x7b, 0x57, 0x30, 0x2a, 0xec, 0x2b, 0xc2, 0x97, 0x52, 0x24, 0xa1,
  0xeb, 0xa6, 0xfa, 0xbd, 0x00, 0x15, 0x26, 0xf7, 0xe4, 0xe5, 0x2f, 0x44,
  0x3e, 0x91, 0xc0, 0x39, 0xb0, 0xfe, 0x46, 0x2d, 0x7a, 0x39, 0x8c, 0xef,
  0x87, 0x3f, 0x39, 0x06, 0xe4, 0xd0, 0x00, 0xda, 0xd8, 0x0d, 0xe2, 0xb8,
  0xe8, 0xd7, 0x35, 0xf8, 0x3b, 0x4a, 0xbc, 0xb0, 0xbe, 0xa5, 0x04, 0x53,
  0x64, 0x97, 0x7d, 0x58, 0xcf, 0x09, 0xfd, 0x53, 0x74, 0xf4, 0xc2, 0x20,
  0xcd, 0x19, 0x61, 0x3c, 0x79, 0x0d, 0x82, 0x20, 0xcd, 0x40, 0xfe, 0x71,
  0xe1, 0xac, 0xa5, 0xd0, 0x36, 0x56, 0x2f, 0x53, 0x8f, 0xf5, 0x2b, 0xae,
  0x6a, 0xc6, 0x05, 0xa0, 0xe2, 0xe1, 0x34, 0x02, 0x88, 0xc6, 0xae, 0x01,
  0x45, 0xa4, 0x83, 0xb8, 0xa9, 0x09, 0xb8, 0x27, 0x05, 0x41, 0xb7, 0xb4,
  0x06, 0x10, 0x62, 0x7a, 0x49, 0x3c, 0xb7, 0xbe, 0x3d, 0x1c, 0x46, 0x59,
  0xc1, 0x91, 0x5d, 0x30, 0x26, 0x10, 0xef, 0xa6, 0xc8, 0xc9, 0xab, 0xef,
  0xfb, 0xd3, 0xdc, 0x48, 0x26, 0x66, 0xbe, 0x55, 0x14, 0x45, 0x9a, 0x31,
  0x0e, 0x11, 0xb7, 0x05, 0xab, 0x13, 0xaf, 0xbe, 0x59, 0x0d, 0x23, 0x18,
  0x5a, 0xaf, 0xd0, 0x87, 0x31, 0x44, 0x0f, 0x27, 0x63, 0x37, 0x3b, 0x93,
  0x08, 0x25, 0xa0, 0x50, 0x41, 0x73, 0x82, 0x00, 0x4f, 0x32, 0x26, 0xca,
  0xb5, 0xeb, 0x30, 0xbd, 0x67, 0xa8, 0x60, 0x1c, 0x75, 0xb9, 0xc4, 0x02,
  0x51, 0x91, 0xbc, 0x58, 0x2f, 0xe9, 0x90, 0xb5, 0x00, 0x19, 0x91, 0x51,
  0x8d, 0xab, 0xab, 0x30, 0x1d, 0xe0, 0xf1, 0x23, 0xb9, 0x87, 0x65, 0x92,
  0x15, 0xe0, 0x17, 0x39, 0x81, 0x6b, 0x3f, 0x68, 0x05, 0x1b, 0x2c, 0x04,
  0x15, 0xbd, 0x61, 0xdc, 0x73, 0x85, 0x68, 0xdb, 0x11, 0xdc, 0x48, 0xf0,
  0xc5, 0x9d, 0xa0, 0x84, 0x32, 0x8a, 0xcc, 0xec, 0xc4, 0x1d, 0xa3, 0xba,
  0x8b, 0xf9, 0xef, 0x04, 0x77, 0xdb, 0x29, 0x63, 0xaa, 0x98, 0x6a, 0xf6,
  0x32, 0xc2, 0xf2, 0x8f, 0xf5, 0xba, 0x77, 0xd0, 0x8d, 0x99, 0xfa, 0x12,
  0x34, 0x99, 0xad, 0xa5, 0x07, 0x3a, 0xef, 0x21, 0x82, 0x59, 0x2a, 0x71,
  0xe9, 0x0c, 0xc8, 0x1c, 0x40, 0xdc, 0x36, 0x49, 0x20, 0x27, 0xcd, 0xe9,
  0x59, 0xd1, 0x10, 0xac, 0x69, 0x18, 0xf6, 0x2d, 0x71, 0x17, 0xac, 0x4a,
  0x7c, 0x85, 0xd4, 0x15, 0x43, 0x51, 0x4a, 0xe2, 0xdd, 0xb7, 0x9e, 0x89,
  0x12, 0x01, 0xa8, 0x08, 0xea, 0x89, 0x0d, 0xc3, 0x70, 0x99, 0xc6, 0xaa,
  0x54, 0xa6, 0x15, 0x96, 0x1e, 0x0b, 0x2c, 0x08, 0x3a, 0xcc, 0xcc, 0xef,
  0x4e, 0x01, 0x96, 0xef, 0x17, 0x72, 0xaf, 0x4b, 0x2c, 0x99, 0x5b, 0x9a,
  0x31, 0xa3, 0xdd, 0x1e, 0x64, 0xf3, 0xa3, 0x70, 0x1a, 0xc9, 0x94, 0xf8,
  0x2e, 0xce, 0xc4, 0x54, 0x45, 0xdd, 0x36, 0xc1, 0xa1, 0x90, 0x77, 0x0b,
  0xb4, 0x08, 0xd5, 0xb3, 0xd8, 0xd6, 0xce, 0x61, 0x92, 0xc8, 0x3e, 0x7e,
  0x3b, 0x98, 0x0a, 0x35, 0x85, 0x79, 0xc0, 0xb4, 0x6e, 0xc5, 0x3f, 0xe2,
  0x5e, 0xa3, 0xdf, 0xf3, 0x12, 0xe5, 0x1f, 0xf2, 0x5b, 0xdf, 0xe6, 0x46,
  0xc5, 0x12, 0xfb, 0xd6, 0xc9, 0x7e, 0x90, 0x7d, 0x60, 0x61, 0xab, 0x54,
  0xe4, 0x3e, 0xd4, 0x57, 0x4c, 0x2a, 0xd2, 0x92, 0xda, 0x15, 0xfb, 0xbe,
  0xef, 0x52, 0xe5, 0x4d, 0xec, 0x5b, 0x63, 0x7b, 0x5e, 0xd7, 0xb3, 0x74,
  0xf6, 0x9c, 0xb8, 0xff, 0x1d, 0xdf, 0x26, 0xaf, 0x6b, 0xbc, 0xa7, 0xc0,
  0x09, 0xcc, 0x6f, 0xf2, 0x9e, 0x8d, 0xf3, 0x18, 0x4d, 0xb6, 0x93, 0xb1,
  0xc5, 0xf1, 0x4e, 0xb8, 0xa3, 0x71, 0x46, 0xa7, 0x9d, 0x68, 0xf1, 0xe0,
  0x74, 0x27, 0x5b, 0x64, 0x6c, 0xe1, 0x5e, 0x72, 0xa1, 0x71, 0x06, 0x7b,
  0xb9, 0x05, 0xc6, 0xe9, 0xcf, 0x72, 0xf3, 0x8d, 0xcd, 0xdb, 0xcb, 0x6d,
  0xc0, 0x61, 0x9e, 0xda, 0x1f, 0x15, 0x82, 0x18, 0x7c, 0x51, 0x1d, 0xc0,
  0x80, 0x74, 0x96, 0x07, 0xe8, 0x6b, 0xa7, 0x7b, 0x03, 0x90, 0x35, 0xc2,
  0x07, 0xf0, 0x8e, 0xba, 0x20, 0x54, 0xa8, 0x0a, 0xda, 0xde, 0x61, 0x1c,
  0xb9, 0xd3, 0x70, 0x66, 0xf5, 0xc7, 0xe1, 0x34, 0x0a, 0xc6, 0x51, 0x38,
  0x8e, 0xa2, 0x71, 0x14, 0x8f, 0xa3, 0xe3, 0x38, 0x3a, 0x8d, 0xa3, 0x73,
  0x57, 0x10, 0x06, 0x44, 0xa2, 0x7a, 0xce, 0x94, 0xc5, 0xb8, 0x5d, 0x77,
  0x40, 0x54, 0xa7, 0xf1, 0x94, 0x6f, 0x9d, 0xef, 0x53, 0xbe, 0xf5, 0x67,
  0x56, 0x7c, 0xab, 0x24, 0x9e, 0xf2, 0xad, 0x72, 0x7d, 0xca, 0xb7, 0xda,
  0xd2, 0x9a, 0x6f, 0xb5, 0xe1, 0xa7, 0x7c, 0x2b, 0x5c, 0x9e, 0xf2, 0xad,
  0xe0, 0x5b, 0xf3, 0xad, 0xc0, 0x7d, 0xca, 0xb7, 0xda, 0xea, 0x0e, 0xdf,
  0x8f, 0x02, 0x23, 0x02, 0x1b, 0x24, 0xba, 0xa9, 0xd5, 0xf6, 0x67, 0x46,
  0x0e, 0xa6, 0x2a, 0x70, 0xc7, 0x46, 0xf1, 0x70, 0xe4, 0x61, 0xad, 0x6c,
  0x55, 0x0e, 0x9c, 0x91, 0xee, 0xa7, 0x6e, 0xd6, 0x28, 0x8a, 0x56, 0xed,
  0xcf, 0xa0, 0x1b, 0xbf, 0xa5, 0x66, 0x51, 0x10, 0xce, 0xae, 0x9b, 0xd8,
  0xf4, 0xef, 0x21, 0xa3, 0x59, 0x9f, 0xc9, 0xf3, 0x3c, 0x5d, 0x76, 0x6f,
  0xb5, 0x70, 0xd1, 0x1b, 0x4a, 0x00, 0xd9, 0x55, 0x36, 0x3f, 0xb9, 0x39,
  0xcb, 0xb5, 0xd4, 0x5a, 0xf5, 0xc7, 0x2f, 0x19, 0xf8, 0xe2, 0x1e, 0xd4,
  0xe3, 0xb8, 0xc7, 0xe8, 0x6b, 0xfa, 0x33, 0x73, 0x87, 0xf8, 0x82, 0x4b,
  0x6d, 0x81, 0x85, 0x6c, 0xb2, 0x43, 0x83, 0xd1, 0x3b, 0xb4, 0x1c, 0x2f,
  0x6a, 0x2c, 0x04, 0x1a, 0x64, 0x4b, 0xe4, 0x58, 0x2b, 0x0e, 0xdb, 0x84,
  0x36, 0x73, 0x52, 0x9b, 0xfd, 0xf7, 0x78, 0x3f, 0x8a, 0xf3, 0x7f, 0x04,
  0x31, 0xec, 0xaa, 0x6e, 0x5d, 0x77, 0xcb, 0xeb, 0xcd, 0x5c, 0x00, 0x82,
  0x76, 0x1b, 0x7a, 0x96, 0x13, 0xdd, 0xb5, 0xdc, 0x5a, 0xab, 0x38, 0x81,
  0x6e, 0xc2, 0x06, 0x04, 0x5f, 0x68, 0x92, 0x4b, 0xb9, 0x81, 0x78, 0x7a,
  0x2d, 0xb1, 0x40, 0x76, 0x53, 0x83, 0x5c, 0x69, 0x84, 0x2b, 0x07, 0xb5,
  0x6c, 0xe4, 0x8d, 0xbc, 0x5b, 0xda, 0xbc, 0xb4, 0x41, 0xae, 0xf7, 0x54,
  0x01, 0x8a, 0xeb, 0x96, 0x00, 0xf5, 0x92, 0x3e, 0xf7, 0x0c, 0x88, 0xb7,
  0x52, 0xf9, 0x49, 0xf5, 0x47, 0x50, 0x2e, 0x7a, 0xd9, 0xa1, 0x6f, 0x86,
  0x1d, 0x6b, 0xb3, 0x35, 0x6e, 0x0c, 0x9b, 0xfa, 0xd3, 0x58, 0xd7, 0x80,
  0xcb, 0xf4, 0xb7, 0x65, 0xa8, 0x51, 0xb2, 0x6b, 0x8e, 0x25, 0x2e, 0xf7,
  0xe1, 0xea, 0xd7, 0x62, 0x62, 0x73, 0x11, 0x06, 0x28, 0xcc, 0xe4, 0xf9,
  0x98, 0xf3, 0x25, 0x65, 0x61, 0xac, 0x9e, 0x07, 0x18, 0x96, 0x9e, 0x4e,
  0x59, 0x71, 0xce, 0x7b, 0xd8, 0x20, 0xca, 0x19, 0xd7, 0x3b, 0xd5, 0x99,
  0xf5, 0x9f, 0xba, 0x02, 0x4e, 0x25, 0x21, 0x3f, 0xfe, 0x54, 0xe1, 0x02,
  0x18, 0xa2, 0xd5, 0xa7, 0x10, 0x02, 0x7e, 0x10, 0xf7, 0x51, 0x20, 0xa0,
  0x97, 0x49, 0xaa, 0xec, 0x07, 0x81, 0xe7, 0x28, 0x08, 0x8b, 0x55, 0x10,
  0x18, 0x06, 0x45, 0x00, 0x54, 0x10, 0x62, 0x37, 0xe0, 0x13, 0x49, 0x6e,
  0x49, 0x57, 0x33, 0x53, 0x8b, 0x20, 0x93, 0x90, 0xb5, 0x02, 0xa5, 0x4a,
  0x29, 0xb8, 0x69, 0x2f, 0x1b, 0xdd, 0x41, 0x28, 0x69, 0xd1, 0x64, 0x7a,
  0x8b, 0x17, 0x2b, 0xec, 0x2a, 0xa0, 0xd5, 0x67, 0x2f, 0x82, 0x28, 0xf8,
  0xcc, 0x80, 0x14, 0xb1, 0x73, 0x23, 0xc1, 0x8e, 0x26, 0xc8, 0x48, 0xab,
  0x6d, 0x92, 0xa7, 0x38, 0x83, 0x67, 0xb0, 0x16, 0x87, 0xce, 0x4a, 0x8a,
  0x65, 0x71, 0x18, 0x17, 0x0b, 0xbd, 0xd7, 0x4b, 0xfc, 0x1d, 0x51, 0x69,
  0xb6, 0xab, 0xf5, 0x6d, 0xb0, 0x5b, 0x03, 0x33, 0xd0, 0xf6, 0x69, 0x5a,
  0xe5, 0xa2, 0x2a, 0xf7, 0x13, 0xbd, 0x4b, 0x2d, 0xb7, 0x72, 0xa8, 0xff,
  0x36, 0xab, 0x11, 0xdd, 0xfa, 0x92, 0x92, 0x7d, 0x4a, 0x69, 0x07, 0x16,
  0x0c, 0x0d, 0xf2, 0xa6, 0x57, 0xa0, 0x53, 0x7f, 0x74, 0x87, 0x73, 0xb6,
  0xce, 0xe4, 0x97, 0x7f, 0x01, 0x45, 0xc1, 0x02, 0x58, 0x59, 0x0d, 0x00,
  0x00
};
unsigned int styles_min_css_len = 1189;
