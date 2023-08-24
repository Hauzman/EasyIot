#include <Arduino.h>
unsigned char index_html[] PROGMEM = {
  0x1f, 0x8b, 0x08, 0x08, 0xa7, 0xa2, 0xe6, 0x64, 0x00, 0x03, 0x69, 0x6e,
  0x64, 0x65, 0x78, 0x2e, 0x6d, 0x69, 0x6e, 0x2e, 0x68, 0x74, 0x6d, 0x6c,
  0x00, 0x7d, 0x54, 0xdd, 0x6e, 0xd3, 0x30, 0x14, 0x7e, 0x15, 0xe3, 0x09,
  0x09, 0x24, 0xdc, 0x94, 0x5d, 0x75, 0x23, 0x0d, 0x68, 0x63, 0x63, 0x5c,
  0xec, 0x07, 0x51, 0x40, 0x5c, 0x21, 0x27, 0x3e, 0x49, 0xbc, 0xb9, 0x76,
  0xb1, 0x4f, 0x3a, 0x2a, 0x71, 0xcf, 0x03, 0x20, 0x9e, 0x80, 0x47, 0xe9,
  0x8b, 0x71, 0x1c, 0x37, 0x1d, 0xac, 0x13, 0x17, 0x49, 0x6c, 0x7f, 0x5f,
  0xbe, 0xef, 0x9c, 0xe3, 0x63, 0xe7, 0x8f, 0x5e, 0x5f, 0x1e, 0xcf, 0x3e,
  0x5f, 0x9d, 0xb0, 0x16, 0xe7, 0xa6, 0xc8, 0xe3, 0x9b, 0x19, 0x69, 0x9b,
  0x29, 0x5f, 0x20, 0xa7, 0x39, 0x48, 0x55, 0xe4, 0x73, 0x40, 0xc9, 0xaa,
  0x56, 0xfa, 0x00, 0x38, 0xe5, 0x1d, 0xd6, 0x62, 0x42, 0x18, 0x6a, 0x34,
  0x50, 0x1c, 0x9d, 0xb1, 0x4b, 0xeb, 0x4e, 0x3d, 0xe4, 0x59, 0x5a, 0xc8,
  0x8d, 0xb6, 0x37, 0xcc, 0x83, 0x99, 0x72, 0x5d, 0x39, 0xcb, 0x59, 0xeb,
  0xa1, 0x9e, 0x72, 0x25, 0x51, 0x1e, 0x3e, 0xe3, 0x7f, 0xc3, 0x01, 0x57,
  0x06, 0x42, 0x0b, 0x80, 0x03, 0xa9, 0x0a, 0x21, 0x4b, 0xab, 0x23, 0x1a,
  0xbe, 0x3c, 0x18, 0x8d, 0xc7, 0xf4, 0x47, 0x96, 0xa2, 0x28, 0x9d, 0x5a,
  0x15, 0xb9, 0xd2, 0xcb, 0x14, 0x16, 0xf8, 0x22, 0xb7, 0x72, 0xc9, 0x2a,
  0x23, 0x43, 0x98, 0x72, 0x1a, 0x96, 0xd2, 0x73, 0xe6, 0x9d, 0x81, 0x7e,
  0xa6, 0x1b, 0x89, 0x9a, 0xfc, 0x8b, 0xbc, 0x33, 0x03, 0xc9, 0x59, 0x57,
  0x7b, 0x10, 0x73, 0xb0, 0x1d, 0x67, 0x31, 0x22, 0x71, 0xab, 0x55, 0x13,
  0x93, 0x42, 0x0f, 0xd0, 0x07, 0x37, 0x50, 0x69, 0x22, 0x37, 0x51, 0xed,
  0x71, 0xa6, 0x15, 0x69, 0x3a, 0x05, 0xa2, 0x44, 0xca, 0x68, 0x43, 0x89,
  0x32, 0x42, 0x23, 0xcc, 0x89, 0x1b, 0x16, 0xd2, 0x0e, 0xeb, 0xb1, 0x7e,
  0x22, 0xb2, 0x79, 0x71, 0xb1, 0xfe, 0x99, 0x67, 0x11, 0xa3, 0x2c, 0x24,
  0x3d, 0x46, 0x47, 0x8f, 0x1d, 0xe9, 0x1a, 0x24, 0x76, 0x1e, 0x42, 0x2f,
  0xff, 0x80, 0xd8, 0x80, 0xf3, 0xe2, 0xf4, 0xc3, 0xc5, 0xfa, 0xc7, 0xfa,
  0xd7, 0xc9, 0xfb, 0x1d, 0xd9, 0xac, 0xa3, 0xfd, 0x2b, 0x3b, 0x44, 0x67,
  0x19, 0xae, 0x16, 0x54, 0x84, 0x34, 0xe1, 0xcc, 0xd9, 0xca, 0xe8, 0xea,
  0x86, 0x0a, 0x2e, 0x97, 0x70, 0xec, 0x6c, 0xad, 0x9b, 0x27, 0x4f, 0xb7,
  0x59, 0x90, 0x25, 0xa3, 0x47, 0x2c, 0xbc, 0x9e, 0x4b, 0xbf, 0xa2, 0xb1,
  0x11, 0x91, 0x28, 0xa4, 0x31, 0x0f, 0xc5, 0x12, 0x31, 0x5e, 0xbc, 0xe9,
  0xa4, 0x57, 0xd2, 0xb3, 0x59, 0xa7, 0xdc, 0x36, 0x94, 0x64, 0x48, 0x03,
  0x2a, 0xff, 0x66, 0xdb, 0xe2, 0x2e, 0xd1, 0x96, 0x0d, 0x0a, 0x01, 0x25,
  0x06, 0x41, 0x6c, 0x88, 0xda, 0x46, 0x96, 0x60, 0x36, 0x16, 0xfd, 0xb6,
  0x53, 0x07, 0x38, 0xe3, 0xfc, 0xe1, 0xde, 0x64, 0x52, 0xd6, 0x07, 0xd5,
  0x0b, 0x5e, 0x7c, 0xd2, 0xe2, 0x54, 0xb3, 0xc1, 0xa1, 0x67, 0xc6, 0x82,
  0x85, 0xa0, 0xd5, 0x17, 0x53, 0x46, 0x91, 0x04, 0xb1, 0x3b, 0xec, 0x56,
  0xd7, 0x5a, 0x04, 0xdd, 0x58, 0x49, 0xf0, 0xf8, 0xf1, 0x36, 0xba, 0xe4,
  0xc6, 0xfe, 0x6b, 0xf7, 0x9d, 0x9d, 0xbf, 0x9b, 0xcd, 0x76, 0xfd, 0xe6,
  0x5f, 0x11, 0xff, 0xf1, 0xbb, 0x07, 0xc5, 0xbc, 0x60, 0x5b, 0x52, 0x03,
  0xea, 0x8e, 0x98, 0xf5, 0x1d, 0xdb, 0xbf, 0x02, 0x54, 0xb1, 0x25, 0x07,
  0x1a, 0x9d, 0x0e, 0x04, 0x8b, 0x2c, 0x7e, 0xa5, 0xb6, 0xe0, 0x45, 0x6d,
  0x3a, 0xad, 0xa8, 0x31, 0x43, 0x5b, 0x3a, 0xaa, 0xaf, 0xd8, 0x22, 0xbd,
  0x5c, 0xfa, 0x7b, 0x50, 0xac, 0x9d, 0x43, 0xf0, 0xf7, 0x3a, 0x3b, 0x2d,
  0x3e, 0xb4, 0x6d, 0x4b, 0xf0, 0xa1, 0x3f, 0x0e, 0x1f, 0x69, 0xb0, 0xfe,
  0xed, 0x76, 0x73, 0xdc, 0x30, 0x52, 0x9a, 0x62, 0x80, 0x53, 0xe0, 0xe8,
  0x9d, 0x6d, 0xd2, 0x59, 0xbf, 0x24, 0x1f, 0x26, 0xd8, 0x95, 0xbb, 0x05,
  0x0f, 0x8a, 0x95, 0x2b, 0xb6, 0xed, 0xe6, 0x16, 0x71, 0x11, 0x0e, 0xb3,
  0xac, 0xd1, 0xd8, 0x76, 0xe5, 0xa8, 0x72, 0xf3, 0xac, 0xf4, 0x9d, 0x75,
  0xad, 0xf3, 0x28, 0x27, 0xfb, 0xd9, 0xd1, 0x99, 0x38, 0x91, 0x61, 0x25,
  0xde, 0x3a, 0xba, 0x5b, 0x8e, 0x22, 0xc2, 0xce, 0x22, 0x14, 0x9b, 0x98,
  0xbd, 0x62, 0xfb, 0xe3, 0xe7, 0x13, 0xa6, 0x2d, 0x49, 0x7b, 0xec, 0x1a,
  0x69, 0x28, 0x84, 0xe4, 0xbb, 0xc9, 0x38, 0x4b, 0xd9, 0x0d, 0xd3, 0x50,
  0x79, 0xbd, 0x40, 0x16, 0x7c, 0x35, 0xe5, 0xd7, 0x21, 0xd3, 0x56, 0xc1,
  0xb7, 0xd1, 0xf5, 0xdd, 0xad, 0x91, 0xf0, 0xd8, 0x96, 0xfd, 0xc5, 0x91,
  0xf5, 0x37, 0xdc, 0x1f, 0x51, 0x2b, 0xd8, 0x72, 0xf1, 0x04, 0x00, 0x00
};
unsigned int index_html_len = 672;
