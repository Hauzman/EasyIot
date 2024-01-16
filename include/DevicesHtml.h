#include <Arduino.h>
unsigned char devices_html[] PROGMEM = {
  0x1f, 0x8b, 0x08, 0x08, 0xba, 0xff, 0xa6, 0x65, 0x00, 0x03, 0x64, 0x65,
  0x76, 0x69, 0x63, 0x65, 0x73, 0x2e, 0x6d, 0x69, 0x6e, 0x2e, 0x68, 0x74,
  0x6d, 0x6c, 0x00, 0xcd, 0x57, 0xdd, 0x6e, 0xdb, 0x36, 0x14, 0x7e, 0x15,
  0x82, 0x17, 0x43, 0x02, 0x54, 0xb5, 0x2c, 0xa7, 0x68, 0x9b, 0x38, 0x02,
  0xd2, 0x24, 0xdd, 0xba, 0x9f, 0x2c, 0x48, 0xd2, 0x62, 0x77, 0x03, 0x2d,
  0xb1, 0x12, 0x11, 0x8a, 0xd4, 0x48, 0xca, 0x76, 0xfa, 0x3a, 0xbb, 0xd8,
  0x13, 0xec, 0x09, 0xfa, 0x62, 0x3b, 0x24, 0x25, 0xc5, 0xb2, 0xa4, 0xd8,
  0xed, 0x56, 0x60, 0x40, 0xa0, 0x80, 0xe4, 0xf9, 0xfb, 0x0e, 0xcf, 0xe1,
  0xf9, 0x3c, 0x4f, 0xd9, 0x12, 0x25, 0x9c, 0x68, 0x7d, 0x8a, 0x17, 0x72,
  0x1d, 0xe4, 0x94, 0xa4, 0x54, 0xe1, 0x78, 0x9e, 0x47, 0xf1, 0x5c, 0x1b,
  0x25, 0x45, 0x16, 0xbf, 0xad, 0xc4, 0xe7, 0xbf, 0x3e, 0xff, 0x4d, 0xf5,
  0x7c, 0x52, 0xef, 0xcc, 0x27, 0xf6, 0x78, 0x02, 0xba, 0xf1, 0xdc, 0x1a,
  0x60, 0xe9, 0x29, 0x5e, 0xb1, 0x4f, 0x44, 0xa5, 0xb8, 0x31, 0x56, 0x2f,
  0xfd, 0xf9, 0x86, 0x83, 0x85, 0x4c, 0x1f, 0xba, 0xbb, 0x1f, 0xa5, 0x2a,
  0x82, 0x4c, 0xc9, 0xaa, 0x84, 0x7d, 0x4e, 0x16, 0x94, 0x23, 0xd8, 0x82,
  0xfd, 0x40, 0x04, 0x82, 0x14, 0x14, 0x76, 0x75, 0x49, 0x44, 0x23, 0xce,
  0x89, 0xc8, 0xea, 0xfd, 0x2b, 0x59, 0x50, 0x88, 0x09, 0x0e, 0x21, 0x18,
  0xa7, 0x19, 0xa3, 0x39, 0x13, 0x65, 0x65, 0x5a, 0xdb, 0x4e, 0x12, 0x39,
  0x17, 0x89, 0x14, 0x10, 0x3d, 0xc7, 0x48, 0x9b, 0x07, 0x4e, 0x6d, 0x84,
  0xa9, 0xc9, 0x8f, 0x51, 0x14, 0x86, 0xe5, 0x1a, 0xa3, 0x82, 0xac, 0x39,
  0x15, 0x99, 0xc9, 0x4f, 0xf1, 0x2c, 0xc4, 0xc8, 0x3c, 0x94, 0x20, 0x62,
  0xe8, 0xda, 0x60, 0x64, 0x4d, 0x34, 0xa6, 0xb0, 0xc3, 0xda, 0x86, 0x86,
  0x4a, 0x4e, 0x12, 0x9a, 0x4b, 0x0e, 0x49, 0x3b, 0xc5, 0x74, 0x7d, 0x8c,
  0xee, 0x99, 0x49, 0x72, 0x2a, 0x30, 0x52, 0xf4, 0x8f, 0x8a, 0x29, 0x9a,
  0x6e, 0xe6, 0x69, 0x0f, 0xc4, 0xa9, 0x62, 0x4b, 0x77, 0x01, 0x3d, 0xcc,
  0xcd, 0xc9, 0x85, 0xfb, 0xdf, 0xc3, 0xad, 0x29, 0xa7, 0x89, 0x41, 0x52,
  0x24, 0x39, 0x48, 0x43, 0xc0, 0x5e, 0xfe, 0xd6, 0x6d, 0x1f, 0x98, 0x9c,
  0xe9, 0xc3, 0x06, 0x4a, 0xc9, 0x84, 0xee, 0xa5, 0x21, 0x3a, 0xb2, 0x69,
  0xd8, 0x8c, 0xb0, 0x4d, 0x58, 0x03, 0xb9, 0x8d, 0x4d, 0x96, 0x86, 0x49,
  0x81, 0x96, 0x84, 0x57, 0x60, 0xe1, 0x25, 0x8e, 0xdf, 0xf1, 0xaa, 0x60,
  0x82, 0x40, 0x99, 0xfc, 0x29, 0xd1, 0x75, 0xc5, 0x35, 0x49, 0xa5, 0x42,
  0x1f, 0x98, 0x32, 0x15, 0xe1, 0xf3, 0x89, 0x97, 0xdf, 0xd6, 0x7b, 0xb5,
  0xa5, 0x77, 0x05, 0x4e, 0x09, 0xdf, 0xa5, 0x75, 0x84, 0xe3, 0x4b, 0x6d,
  0xa4, 0xa2, 0x8f, 0x7e, 0x2e, 0xaa, 0x92, 0xcb, 0x5d, 0x7a, 0x2f, 0x5a,
  0xbd, 0xda, 0xcf, 0x5e, 0x5a, 0x53, 0x88, 0x51, 0x18, 0xaa, 0x54, 0x55,
  0x82, 0xee, 0xde, 0xd0, 0xa2, 0xae, 0xda, 0x7e, 0xc8, 0x66, 0x7d, 0x64,
  0x3b, 0x34, 0x5e, 0xe3, 0xf8, 0x7b, 0xa2, 0x48, 0x46, 0x8b, 0x9d, 0x38,
  0xa6, 0x80, 0xe4, 0xe2, 0x87, 0x3b, 0x34, 0x9d, 0x8e, 0x8a, 0x44, 0xb5,
  0x48, 0xf4, 0x84, 0x48, 0x54, 0x8b, 0x44, 0xa3, 0x21, 0x85, 0x20, 0x71,
  0x3b, 0x7d, 0xf5, 0x26, 0x0a, 0x47, 0xef, 0x1d, 0x80, 0xde, 0x52, 0xa1,
  0x01, 0xdf, 0x79, 0x5e, 0x2d, 0xc9, 0xa8, 0x5c, 0xd4, 0xca, 0xfd, 0x22,
  0x97, 0xac, 0xa0, 0xc2, 0x40, 0x71, 0xbd, 0xbb, 0x19, 0x95, 0x3f, 0x6a,
  0xe5, 0xaf, 0xa5, 0x32, 0xe3, 0x76, 0x5f, 0xb4, 0x72, 0x3f, 0x12, 0x41,
  0xf9, 0xa8, 0xe0, 0x4b, 0x48, 0xc8, 0xf5, 0x27, 0x5a, 0x04, 0x61, 0x78,
  0x74, 0x87, 0x3e, 0xcc, 0x1e, 0xe5, 0x26, 0xbe, 0xdb, 0xf6, 0xeb, 0x6d,
  0xdb, 0x3e, 0xd0, 0x72, 0x41, 0x55, 0x06, 0xd0, 0x4c, 0x6d, 0xa7, 0xdb,
  0xad, 0xe9, 0x50, 0xa3, 0x7b, 0x59, 0x70, 0xcd, 0x84, 0x44, 0x97, 0xd0,
  0x83, 0x24, 0x25, 0x63, 0xed, 0x3e, 0xde, 0xd0, 0xaf, 0xc2, 0x9d, 0xfd,
  0xdc, 0x44, 0x30, 0x80, 0x66, 0x53, 0x24, 0x0a, 0x32, 0xdc, 0x87, 0x87,
  0x72, 0x96, 0xd2, 0x1e, 0xc6, 0x54, 0xae, 0x44, 0x0f, 0x65, 0x34, 0x86,
  0xd2, 0x4a, 0x7b, 0x9c, 0xdf, 0x0c, 0x5f, 0xd4, 0xc7, 0xb7, 0xa8, 0x8c,
  0x81, 0x4b, 0xf6, 0x4f, 0xbc, 0x5f, 0x60, 0xfb, 0x6e, 0x72, 0x96, 0xdc,
  0x9f, 0xe2, 0x44, 0x51, 0x62, 0xe8, 0xc1, 0x61, 0x6b, 0x7b, 0x61, 0xec,
  0x75, 0xa4, 0xb0, 0xe9, 0x2d, 0xdb, 0xb5, 0x17, 0x1a, 0x82, 0xa5, 0xc9,
  0x12, 0xf6, 0xcf, 0x6f, 0xde, 0x9d, 0xdd, 0xb4, 0x98, 0xbc, 0x8f, 0xc6,
  0xbd, 0xff, 0xe6, 0xaa, 0xc1, 0x93, 0x53, 0x96, 0xe5, 0xe6, 0x38, 0x2a,
  0xd7, 0x27, 0x0b, 0xa9, 0x60, 0x90, 0x04, 0x1e, 0x61, 0x78, 0x92, 0x48,
  0x2e, 0xd5, 0x71, 0xa6, 0xc8, 0xc3, 0xc9, 0x82, 0x24, 0xf7, 0x36, 0xed,
  0x22, 0x0d, 0xfc, 0xae, 0xca, 0x16, 0x07, 0xb3, 0xa3, 0x67, 0x68, 0x3a,
  0x7b, 0xfd, 0x0c, 0xcd, 0x8e, 0x0e, 0xf7, 0x9a, 0xb4, 0x10, 0x74, 0xa5,
  0xa8, 0xf6, 0x38, 0x52, 0xba, 0x64, 0x09, 0xd5, 0xbf, 0x43, 0xda, 0x3e,
  0xb2, 0x0c, 0x24, 0x0d, 0x2d, 0x60, 0x9c, 0x19, 0xea, 0x4e, 0xcf, 0xce,
  0xef, 0xde, 0x9f, 0xdd, 0xfd, 0x7a, 0xe3, 0x2d, 0x00, 0xd0, 0x65, 0x86,
  0x5c, 0x5c, 0x76, 0x3e, 0xda, 0xcc, 0xfb, 0xb0, 0x9b, 0xd5, 0xba, 0xe0,
  0x02, 0x3c, 0xe4, 0xc6, 0x94, 0xc7, 0x93, 0xc9, 0x6a, 0xb5, 0x7a, 0xbe,
  0x9a, 0x3d, 0x97, 0x2a, 0x9b, 0xc0, 0x78, 0x0d, 0x27, 0xa0, 0x8c, 0xd1,
  0x92, 0xd1, 0xd5, 0x1b, 0xb9, 0x3e, 0xc5, 0x21, 0x0a, 0xd1, 0xcc, 0xfe,
  0xb9, 0xab, 0x59, 0x66, 0x43, 0x31, 0x42, 0xf4, 0xeb, 0xc1, 0xe0, 0x83,
  0x94, 0x1a, 0xc2, 0xb8, 0x6e, 0x2a, 0xaf, 0x7b, 0x05, 0x8d, 0x50, 0xcd,
  0x1b, 0xb6, 0x8b, 0xca, 0xd7, 0x6a, 0x2d, 0xab, 0x57, 0x76, 0x54, 0x83,
  0x94, 0x67, 0x0c, 0x8f, 0x83, 0xd3, 0xc8, 0x2c, 0xe3, 0xf4, 0xd6, 0x1d,
  0x37, 0x83, 0xd3, 0x17, 0x0b, 0x4c, 0xf6, 0xe4, 0xde, 0x45, 0x86, 0x3a,
  0x6e, 0x35, 0x87, 0x5e, 0x50, 0xc8, 0xdd, 0xcf, 0x80, 0xdb, 0x6d, 0x07,
  0x3a, 0x87, 0x82, 0xa0, 0xea, 0x9a, 0xaa, 0x04, 0xde, 0x34, 0x78, 0xbe,
  0x1b, 0x2f, 0x8d, 0x39, 0x7f, 0x1e, 0x78, 0xb3, 0xc0, 0x4d, 0x98, 0x80,
  0xac, 0x39, 0x8e, 0x02, 0x6f, 0x70, 0xd8, 0xd2, 0x13, 0x65, 0xcd, 0xe1,
  0x81, 0x47, 0x28, 0x2b, 0x99, 0x0c, 0x94, 0x5c, 0xe1, 0x6e, 0xcd, 0xd5,
  0xdf, 0xe6, 0x9e, 0xb7, 0x6e, 0xfc, 0xf6, 0xf2, 0xea, 0xb6, 0x7b, 0xdf,
  0xff, 0x97, 0x1b, 0x1b, 0xd6, 0x70, 0x8f, 0x74, 0x4f, 0xe5, 0xeb, 0x93,
  0xb1, 0xb9, 0xdd, 0x3c, 0x81, 0x85, 0x4c, 0x09, 0x6f, 0xef, 0xc5, 0xaf,
  0x3a, 0xc6, 0xdd, 0x96, 0x7b, 0x79, 0xe0, 0x26, 0x87, 0x8e, 0x5a, 0x42,
  0xbd, 0x09, 0x21, 0xe1, 0x52, 0x43, 0xe8, 0xdf, 0x19, 0x18, 0x6a, 0xfa,
  0xa4, 0x41, 0x90, 0xcf, 0xba, 0xb4, 0xd5, 0x06, 0x9c, 0xcf, 0x06, 0x10,
  0x79, 0xcb, 0xf6, 0xcd, 0xeb, 0xf1, 0xc7, 0x6f, 0xc1, 0x97, 0xbf, 0x94,
  0x1a, 0xff, 0x0b, 0x62, 0x1c, 0x90, 0x04, 0xf5, 0xd1, 0xc5, 0x77, 0xac,
  0x94, 0x28, 0xa5, 0x68, 0x83, 0x53, 0xb5, 0xf7, 0x3d, 0x98, 0x97, 0xfa,
  0xbe, 0x9d, 0x7d, 0x0f, 0xb0, 0xe9, 0x98, 0x94, 0xc9, 0x26, 0x50, 0x98,
  0x0e, 0xa0, 0x41, 0x83, 0xb2, 0xd2, 0xf9, 0x23, 0x94, 0x7a, 0x17, 0x37,
  0x24, 0x20, 0xc4, 0xed, 0xc3, 0xd1, 0x57, 0x0b, 0xf8, 0xe2, 0x71, 0xd8,
  0x75, 0xec, 0xc5, 0x0d, 0x87, 0xeb, 0x17, 0xe6, 0x1e, 0x21, 0x41, 0x45,
  0x26, 0x4f, 0xc4, 0x34, 0x1d, 0x8b, 0xc9, 0xe9, 0x0d, 0x06, 0xe5, 0x2d,
  0xc6, 0x9e, 0x89, 0x0e, 0x34, 0x8b, 0xb7, 0xe3, 0x30, 0x19, 0xbc, 0x67,
  0xd2, 0x02, 0xff, 0x52, 0x8e, 0xc7, 0x19, 0x3d, 0x99, 0x3b, 0xaf, 0x3d,
  0x9a, 0xc2, 0xc6, 0xfa, 0x58, 0x26, 0x87, 0xfa, 0xf5, 0x63, 0x90, 0x10,
  0xce, 0x16, 0x8a, 0x58, 0x9a, 0x86, 0x3b, 0x65, 0x65, 0xe9, 0xca, 0x50,
  0x6d, 0x9d, 0x7b, 0x05, 0xf7, 0x13, 0xe4, 0xeb, 0x8a, 0x4a, 0x54, 0xc5,
  0xc2, 0x3e, 0xd3, 0x3e, 0x00, 0x60, 0x6e, 0x03, 0xa5, 0xd3, 0x36, 0x23,
  0x2c, 0x82, 0x9c, 0x99, 0x16, 0xb1, 0x25, 0x7a, 0x9a, 0x66, 0x30, 0x38,
  0xa4, 0x46, 0x25, 0x90, 0x79, 0xa4, 0xab, 0x05, 0xdb, 0x59, 0x35, 0x5d,
  0x9f, 0x8e, 0x47, 0x0d, 0x14, 0xc7, 0xa8, 0x57, 0x4f, 0xbc, 0xba, 0x7e,
  0x53, 0xaa, 0x13, 0xba, 0x5f, 0x92, 0xef, 0xc5, 0x1a, 0xf7, 0xf3, 0xd3,
  0x61, 0x84, 0xf1, 0x4f, 0x57, 0xbf, 0xfd, 0x17, 0xe9, 0x24, 0xc0, 0xb4,
  0x36, 0x13, 0xba, 0x5f, 0x42, 0x38, 0x13, 0xf4, 0xcb, 0xb5, 0x0a, 0xea,
  0x57, 0x3d, 0xbd, 0xed, 0x2c, 0x6c, 0x61, 0x91, 0xc6, 0xbd, 0xf0, 0x4f,
  0xf3, 0xca, 0x14, 0x38, 0xa8, 0xa1, 0x6f, 0xfd, 0xf0, 0xda, 0x1a, 0xf8,
  0x96, 0x52, 0xfa, 0xf3, 0x47, 0x8a, 0x59, 0xaf, 0xe3, 0x8b, 0xcb, 0x9f,
  0x2f, 0xef, 0x2e, 0x5b, 0x12, 0x89, 0x76, 0xb8, 0x21, 0x65, 0xc9, 0x1f,
  0x6a, 0x2f, 0xe7, 0x8e, 0x6f, 0xe8, 0x01, 0x67, 0xdb, 0x7c, 0xb6, 0x5e,
  0x8f, 0xf2, 0xd9, 0xf7, 0xd7, 0x17, 0x67, 0x36, 0x88, 0x27, 0x08, 0xad,
  0xfb, 0xfe, 0x03, 0xac, 0xdd, 0xd9, 0x57, 0x4f, 0x12, 0x00, 0x00
};
unsigned int devices_html_len = 1319;
