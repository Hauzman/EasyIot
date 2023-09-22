#include <Arduino.h>

  0x1f, 0x8b, 0x08, 0x08, 0x6c, 0x8f, 0x0d, 0x65, 0x00, 0x03, 0x69, 0x6e,
  0x64, 0x65, 0x78, 0x2e, 0x6d, 0x69, 0x6e, 0x2e, 0x68, 0x74, 0x6d, 0x6c,
  0x00, 0xbd, 0x55, 0x4b, 0x52, 0xdc, 0x30, 0x10, 0xbd, 0x8a, 0x62, 0x2a,
  0x3b, 0x34, 0x1e, 0x48, 0xa5, 0x6a, 0x18, 0x6c, 0x48, 0x20, 0x50, 0xb0,
  0x08, 0x90, 0x0a, 0xe4, 0xb3, 0x4a, 0xc9, 0x56, 0xdb, 0x16, 0xc8, 0x92,
  0x91, 0xe4, 0xf9, 0x9c, 0x20, 0x07, 0x48, 0xe5, 0x04, 0x39, 0xca, 0x5c,
  0x2c, 0x2d, 0xcb, 0x9e, 0xf0, 0x99, 0x54, 0x65, 0x95, 0xc5, 0x78, 0xac,
  0x7e, 0xdd, 0xea, 0xee, 0xd7, 0x1f, 0x27, 0x2f, 0xde, 0x5d, 0x1e, 0x5f,
  0x7f, 0xbd, 0x3a, 0x21, 0x95, 0xab, 0xe5, 0x41, 0xd2, 0x3f, 0x81, 0xf1,
  0x83, 0xa4, 0x06, 0xc7, 0x48, 0x5e, 0x31, 0x63, 0xc1, 0xa5, 0x51, 0xeb,
  0x0a, 0x3a, 0x89, 0x7a, 0x69, 0xe5, 0x5c, 0x43, 0xe1, 0xbe, 0x15, 0xb3,
  0x34, 0xfa, 0x42, 0x6f, 0xde, 0xd2, 0x63, 0x5d, 0x37, 0xcc, 0x89, 0x4c,
  0x42, 0x44, 0x72, 0xad, 0x1c, 0x28, 0x34, 0x39, 0x3f, 0x49, 0x81, 0x97,
  0x80, 0x46, 0x4e, 0x38, 0x09, 0x07, 0x47, 0x67, 0xe4, 0x52, 0xe9, 0x53,
  0x03, 0x49, 0x1c, 0x04, 0x89, 0x14, 0xea, 0x8e, 0x18, 0x90, 0x69, 0x24,
  0xd0, 0x2a, 0x22, 0x95, 0x81, 0x22, 0x8d, 0x38, 0x73, 0x6c, 0xba, 0x3d,
  0xf8, 0x5a, 0x5f, 0x37, 0x17, 0xdc, 0x55, 0x29, 0x87, 0x99, 0xc8, 0x81,
  0x76, 0x87, 0x6d, 0xa1, 0x84, 0x13, 0x4c, 0x52, 0x9b, 0x33, 0x09, 0xe9,
  0xce, 0x76, 0xcd, 0x16, 0xa2, 0x6e, 0xeb, 0xf5, 0xb9, 0xb5, 0x60, 0xba,
  0x03, 0xc3, 0xc8, 0x52, 0xa5, 0x23, 0xa2, 0x58, 0x0d, 0x69, 0x34, 0x13,
  0x30, 0x6f, 0xb4, 0x71, 0xd1, 0xc3, 0x10, 0xac, 0x5b, 0x4a, 0xb0, 0x15,
  0x80, 0x1b, 0x02, 0xc9, 0xad, 0x8d, 0x83, 0x74, 0x84, 0xaf, 0x87, 0x7b,
  0xa3, 0xf1, 0x18, 0x2d, 0xe2, 0x40, 0x4f, 0xa6, 0xf9, 0x92, 0xe4, 0x92,
  0x59, 0x8b, 0xa6, 0x77, 0x42, 0xd1, 0x4c, 0xb6, 0x40, 0xac, 0xe0, 0x90,
  0x31, 0x43, 0x6b, 0x0c, 0x0d, 0x75, 0xb9, 0x98, 0x05, 0x3a, 0xc1, 0x0c,
  0xba, 0x35, 0x43, 0xdd, 0x20, 0x42, 0x05, 0xc5, 0x66, 0x03, 0x80, 0xaf,
  0x68, 0x49, 0xc2, 0x1f, 0xb5, 0x0e, 0xf9, 0xcc, 0xa9, 0xd3, 0x4d, 0x44,
  0x8c, 0xc6, 0xe8, 0x3d, 0x2e, 0x4a, 0x14, 0x22, 0x51, 0x07, 0x49, 0x2b,
  0xd7, 0xbe, 0x07, 0x8f, 0xa0, 0xda, 0x88, 0x78, 0xee, 0x3c, 0x39, 0xa5,
  0xaf, 0x99, 0x33, 0x00, 0x5d, 0x8a, 0x83, 0x2e, 0x1e, 0x58, 0x9f, 0xdb,
  0x56, 0xb4, 0x0e, 0x08, 0x0d, 0xa9, 0x70, 0x50, 0xf7, 0xd6, 0xfe, 0x8c,
  0xde, 0x34, 0xf7, 0xb6, 0xb6, 0x61, 0x6a, 0x50, 0x94, 0x4c, 0x95, 0x34,
  0xc8, 0x2f, 0x56, 0x3f, 0x92, 0xd8, 0x63, 0x48, 0x07, 0xc3, 0x9f, 0x14,
  0xde, 0xcd, 0xbf, 0xdf, 0x1e, 0xaa, 0x68, 0x37, 0x39, 0x28, 0x80, 0xb9,
  0xd6, 0x78, 0xec, 0xf4, 0xe6, 0x62, 0xf5, 0x7d, 0xf5, 0xf3, 0xe4, 0xe3,
  0x33, 0x57, 0x71, 0x8b, 0x5d, 0x1a, 0x23, 0x21, 0x7d, 0x35, 0xc0, 0x74,
  0x54, 0x0f, 0xf7, 0x74, 0x65, 0x47, 0x0b, 0x90, 0xd1, 0x23, 0x79, 0xd3,
  0x4a, 0x49, 0x25, 0x14, 0x58, 0xe0, 0xae, 0xac, 0x58, 0x61, 0x2d, 0xb5,
  0x99, 0x92, 0x79, 0x85, 0x11, 0xee, 0x93, 0x0a, 0x44, 0x59, 0xb9, 0x29,
  0xd9, 0x19, 0x37, 0x8b, 0xfd, 0xde, 0xb4, 0x57, 0x6c, 0x18, 0xe7, 0x42,
  0x95, 0x53, 0xf2, 0x3a, 0x40, 0x5d, 0xd8, 0x8f, 0x2e, 0xd9, 0x9a, 0x4c,
  0xb2, 0x62, 0x2f, 0x47, 0xf0, 0xb3, 0xa0, 0xa7, 0x62, 0x4a, 0x86, 0xa8,
  0x3b, 0x55, 0xc1, 0xb1, 0x52, 0x58, 0xaa, 0x6f, 0x32, 0xf3, 0x41, 0x05,
  0x88, 0xfc, 0xc1, 0xe6, 0xa2, 0x10, 0xd4, 0x8a, 0x52, 0x31, 0x84, 0xc7,
  0x2f, 0xd7, 0x19, 0x77, 0x0d, 0x14, 0x9e, 0xff, 0x3f, 0x91, 0xf7, 0x1f,
  0xae, 0xaf, 0x37, 0xe4, 0x51, 0xdf, 0x3b, 0xf7, 0xb7, 0x3c, 0x3c, 0xd6,
  0xf5, 0x2e, 0x36, 0x09, 0x07, 0x2b, 0xb1, 0x63, 0xb9, 0xde, 0x94, 0xcd,
  0xb3, 0x9c, 0xfa, 0x39, 0xa7, 0x73, 0xc3, 0x9a, 0xa6, 0x9b, 0x0d, 0x0b,
  0xb9, 0xef, 0xf6, 0x27, 0x0a, 0xdd, 0x42, 0xc0, 0x19, 0xc2, 0x12, 0x17,
  0xb2, 0x15, 0x1c, 0xdb, 0xca, 0x56, 0x99, 0x66, 0x86, 0xd3, 0x35, 0xd2,
  0x45, 0x16, 0xac, 0x07, 0x4f, 0x85, 0xd6, 0xee, 0xc9, 0x10, 0x06, 0xd1,
  0x86, 0x16, 0x31, 0x9e, 0x3d, 0x52, 0x09, 0xce, 0x41, 0xd1, 0xc5, 0xc6,
  0x2e, 0x9d, 0x81, 0xb1, 0xdd, 0x24, 0x7e, 0xc2, 0x97, 0xd5, 0x2f, 0xfd,
  0x9c, 0xa5, 0x5e, 0x23, 0x10, 0x45, 0x1f, 0x53, 0x60, 0x9d, 0xd1, 0xaa,
  0x0c, 0x0b, 0xf1, 0xb2, 0x30, 0x40, 0x28, 0xb9, 0xd2, 0x73, 0x30, 0xc0,
  0x49, 0xb6, 0x24, 0xeb, 0x29, 0xf2, 0x6b, 0xd6, 0x4e, 0xe3, 0xb8, 0x14,
  0xae, 0x6a, 0xb3, 0x51, 0xae, 0xeb, 0x38, 0x33, 0xad, 0xd2, 0x15, 0xae,
  0x2e, 0x36, 0xd9, 0x8d, 0x8f, 0xce, 0xe8, 0x09, 0xb3, 0x4b, 0x7a, 0xae,
  0x71, 0x93, 0x1d, 0x79, 0x84, 0x9c, 0x79, 0xc8, 0x0f, 0x0a, 0x79, 0x43,
  0x76, 0xc7, 0x3b, 0x13, 0x22, 0x14, 0x5e, 0x6d, 0x5c, 0x5b, 0x32, 0x89,
  0x31, 0x04, 0xbf, 0x49, 0x1c, 0x52, 0x5f, 0x87, 0x93, 0x1b, 0xd1, 0x38,
  0x62, 0x4d, 0x9e, 0x46, 0xb7, 0x36, 0xbe, 0xbd, 0x6f, 0xc1, 0x2c, 0x47,
  0xb8, 0xc2, 0x46, 0xb7, 0xb6, 0xa3, 0xb2, 0xc3, 0x9f, 0xe9, 0x09, 0xc5,
  0x61, 0x81, 0x2a, 0x87, 0x93, 0xd1, 0xab, 0xf1, 0xce, 0x43, 0xc5, 0xd8,
  0x2f, 0x47, 0x3f, 0x9b, 0xfe, 0x73, 0xf2, 0x1b, 0x91, 0x03, 0x93, 0x36,
  0x64, 0x06, 0x00, 0x00
};
unsigned int index_html_len = 784;