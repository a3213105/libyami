/*
 * Copyright 2016 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//
// The unittest header must be included before va_x11.h (which might be included
// indirectly).  The va_x11.h includes Xlib.h and X.h.  And the X headers
// define 'Bool' and 'None' preprocessor types.  Gtest uses the same names
// to define some struct placeholders.  Thus, this creates a compile conflict
// if X defines them before gtest.  Hence, the include order requirement here
// is the only fix for this right now.
//
// See bug filed on gtest at https://github.com/google/googletest/issues/371
// for more details.
//
#include "common/factory_unittest.h"

// primary header
#include "vaapidecoder_h264.h"

// system headers
#include <tr1/array>

namespace YamiMediaCodec {

const static std::tr1::array<uint8_t, 998> g_SimpleH264 = {
  0x00, 0x00, 0x00, 0x01, 0x67, 0x4d, 0x40, 0x28, 0xab, 0x40, 0xb0, 0x4a,
  0x42, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x79, 0x08,
  0x00, 0x00, 0x00, 0x01, 0x68, 0xee, 0x03, 0x9c, 0x30, 0x00, 0x00, 0x00,
  0x01, 0x65, 0xb8, 0x20, 0x19, 0x09, 0xf4, 0xa0, 0x97, 0x12, 0x5b, 0xaa,
  0x1d, 0x1d, 0x71, 0x2f, 0x30, 0xfe, 0xa0, 0x80, 0x7d, 0x32, 0xf6, 0xae,
  0x7f, 0x6d, 0xd2, 0x1c, 0x59, 0xfe, 0xc7, 0x15, 0x7c, 0x08, 0xa4, 0xa2,
  0x80, 0xed, 0x28, 0xfc, 0xcf, 0x73, 0x1c, 0x36, 0x1f, 0x33, 0x7e, 0x3a,
  0xd2, 0xcf, 0x46, 0xa8, 0x29, 0x79, 0x10, 0x7e, 0x14, 0x49, 0x63, 0xc5,
  0x93, 0x30, 0x16, 0x4b, 0x55, 0xef, 0x8f, 0x2b, 0x77, 0xb6, 0x62, 0x20,
  0x54, 0x1c, 0x49, 0x22, 0xda, 0xe8, 0xfd, 0x9c, 0xad, 0x5b, 0x3b, 0xaa,
  0x1f, 0x2f, 0xff, 0x30, 0xe0, 0x76, 0x49, 0xa7, 0x3f, 0x45, 0xd8, 0x9d,
  0x43, 0x41, 0xda, 0xd8, 0x8b, 0x7a, 0xa4, 0x77, 0x74, 0x83, 0xe5, 0x51,
  0x2c, 0x2e, 0x60, 0xfa, 0xcc, 0x35, 0x8f, 0x65, 0x7b, 0xa0, 0xd8, 0xfc,
  0xcd, 0x11, 0xa8, 0x6e, 0xae, 0xc8, 0x89, 0xe3, 0xdc, 0x2f, 0xa3, 0x4d,
  0x0d, 0x7a, 0xdd, 0xdd, 0x02, 0x59, 0xc4, 0xc3, 0xde, 0xda, 0x74, 0x2a,
  0xea, 0xbc, 0x85, 0x40, 0x97, 0x9f, 0x2f, 0x4d, 0x12, 0x74, 0x5d, 0x0f,
  0x29, 0xed, 0x23, 0xf6, 0x65, 0x3e, 0xd6, 0x35, 0x40, 0xea, 0xce, 0x2a,
  0xf6, 0x74, 0xbb, 0x88, 0x13, 0xb7, 0xa7, 0x04, 0xdd, 0x0f, 0x47, 0x52,
  0xbd, 0xef, 0xe0, 0xd2, 0x26, 0x8c, 0x56, 0xf3, 0x3f, 0xe7, 0x53, 0xba,
  0x4e, 0xc0, 0x62, 0xec, 0xbc, 0x56, 0x1c, 0x1c, 0xce, 0xf1, 0x01, 0x62,
  0x53, 0xdd, 0x1f, 0x55, 0x18, 0x32, 0xfb, 0x22, 0x40, 0xc9, 0xdf, 0x1e,
  0x77, 0x82, 0x80, 0x62, 0xec, 0x08, 0xc8, 0xc6, 0x64, 0x85, 0xb1, 0x38,
  0x48, 0x59, 0x76, 0xc3, 0x1e, 0x6a, 0x19, 0x11, 0xfd, 0x83, 0x4e, 0x0b,
  0xd1, 0xb0, 0x17, 0x2d, 0xde, 0x76, 0x9c, 0x90, 0x59, 0xa3, 0xe4, 0xe8,
  0x30, 0x88, 0x5c, 0x8c, 0x85, 0x47, 0xfe, 0x07, 0x88, 0x68, 0x1b, 0xbd,
  0x8a, 0x99, 0xc1, 0x5f, 0x6b, 0x0c, 0xfd, 0xbd, 0x33, 0x1a, 0x3f, 0xc1,
  0x7b, 0x97, 0xbb, 0x8a, 0xf2, 0x49, 0xda, 0x3e, 0xb8, 0x5e, 0xae, 0xbc,
  0xe2, 0x64, 0xc5, 0xfa, 0xa2, 0xeb, 0xc9, 0xcb, 0x7f, 0xf6, 0x78, 0xa3,
  0xa0, 0x8f, 0xae, 0xb0, 0x63, 0x09, 0x1b, 0x25, 0x49, 0x13, 0xdf, 0x65,
  0x4e, 0x73, 0xfc, 0xf0, 0xed, 0xd0, 0x42, 0x84, 0xc7, 0x78, 0xc0, 0xe7,
  0xe5, 0x15, 0x97, 0xc3, 0x13, 0xe9, 0x6f, 0xd2, 0xe3, 0x46, 0xa3, 0x84,
  0x9a, 0x51, 0xe5, 0x27, 0x5e, 0x00, 0x37, 0x5e, 0x8e, 0x1b, 0xd0, 0xdf,
  0xe0, 0xa2, 0x90, 0x1b, 0x96, 0x74, 0xca, 0xae, 0x7e, 0x61, 0x79, 0xe7,
  0x9f, 0x7a, 0x5a, 0x52, 0xe9, 0x60, 0x24, 0x07, 0x56, 0x07, 0x06, 0xb7,
  0xaa, 0x55, 0x48, 0xf3, 0x5b, 0x3c, 0x18, 0xce, 0x78, 0xf4, 0x36, 0x69,
  0xf3, 0xb0, 0x89, 0x6e, 0x96, 0x42, 0x47, 0x12, 0xef, 0x30, 0x1e, 0xff,
  0xb8, 0xfc, 0x94, 0x02, 0x8d, 0xa6, 0x5d, 0x01, 0xc4, 0xa0, 0xbe, 0xe7,
  0x6d, 0x21, 0xc5, 0xe1, 0x4d, 0xf7, 0x8b, 0x23, 0xd5, 0xac, 0x1a, 0xe4,
  0xba, 0xb1, 0x1e, 0x0c, 0x60, 0xe0, 0xcd, 0x60, 0xe1, 0x13, 0xa7, 0x35,
  0x12, 0x50, 0x40, 0x33, 0x81, 0x80, 0x05, 0x6e, 0xc4, 0xc6, 0xd6, 0xb5,
  0x38, 0xa2, 0x96, 0xee, 0x94, 0x37, 0xcf, 0x70, 0xdb, 0xec, 0x27, 0x6e,
  0x8e, 0x9b, 0xaa, 0x38, 0x85, 0x15, 0x09, 0x10, 0x01, 0xba, 0x7e, 0x18,
  0xb8, 0x05, 0xba, 0x4b, 0x76, 0x7e, 0x78, 0x8f, 0xaa, 0xaa, 0xaf, 0x5f,
  0xad, 0x42, 0x62, 0x76, 0x1f, 0x0f, 0xfe, 0x8d, 0x74, 0x24, 0xc8, 0x48,
  0x55, 0x54, 0xcf, 0x5b, 0x97, 0xf7, 0x10, 0x6f, 0x9a, 0xe2, 0xb4, 0xfa,
  0x53, 0x2d, 0x37, 0x2b, 0xd0, 0x50, 0x5a, 0x29, 0x99, 0xd6, 0x37, 0xdb,
  0xa7, 0x45, 0x33, 0x42, 0x34, 0x91, 0xad, 0xa2, 0x87, 0xf8, 0xa3, 0x6a,
  0xb2, 0x52, 0xe4, 0x37, 0x37, 0x92, 0x8b, 0xd2, 0xad, 0x91, 0xa5, 0xbd,
  0xcb, 0x0e, 0x32, 0x3b, 0xf9, 0x47, 0x2f, 0xd8, 0xc0, 0x50, 0x7e, 0x24,
  0xb7, 0xe6, 0x0b, 0xc2, 0x55, 0xb7, 0x11, 0x11, 0x04, 0x6a, 0x39, 0x54,
  0x66, 0xb1, 0x97, 0x94, 0x40, 0x98, 0xac, 0xf1, 0x07, 0x90, 0x74, 0xf7,
  0xab, 0x58, 0x05, 0x3d, 0x1a, 0xa5, 0x50, 0x48, 0x3f, 0x6f, 0xb1, 0x87,
  0x78, 0xf9, 0x7e, 0xbc, 0x0e, 0xdf, 0x05, 0x70, 0xa1, 0xd1, 0x55, 0xe9,
  0x76, 0x2f, 0xd5, 0x58, 0x31, 0x5d, 0x57, 0x17, 0x5e, 0xf0, 0xaa, 0xa7,
  0x3a, 0xe1, 0x72, 0xaf, 0x6f, 0x9c, 0x8f, 0xff, 0x34, 0x24, 0x2e, 0xed,
  0x46, 0x6e, 0xad, 0xd0, 0xfb, 0xcf, 0x28, 0xdd, 0xc9, 0x2e, 0x53, 0x3e,
  0xa5, 0xc0, 0xda, 0xcb, 0x32, 0x95, 0x13, 0xd6, 0x89, 0x6d, 0x3f, 0xa6,
  0x81, 0xc7, 0xa5, 0x47, 0x43, 0x7f, 0xe5, 0xd4, 0x82, 0xfa, 0x0d, 0xd1,
  0x93, 0x27, 0x06, 0xb5, 0x55, 0x37, 0x60, 0x20, 0xe1, 0x12, 0xf5, 0xf1,
  0xa6, 0x5e, 0x51, 0x79, 0x5e, 0x3d, 0xee, 0xab, 0xf1, 0xf7, 0x7d, 0x72,
  0x95, 0x59, 0xbb, 0x29, 0xba, 0x24, 0x85, 0xa9, 0xba, 0x52, 0x59, 0x64,
  0xee, 0x90, 0x19, 0x7c, 0x91, 0x4e, 0x1a, 0x4f, 0xd4, 0xed, 0x54, 0x01,
  0x86, 0x33, 0x78, 0xfe, 0x71, 0xdb, 0xd6, 0x36, 0x3b, 0xba, 0x5e, 0xd4,
  0x2c, 0x28, 0xa4, 0x97, 0x19, 0xb8, 0xf5, 0x6b, 0x30, 0x60, 0x4a, 0xf8,
  0xb7, 0x6d, 0x54, 0x2a, 0x52, 0x36, 0xae, 0xb1, 0x65, 0x26, 0xe6, 0xf5,
  0x2b, 0x12, 0x1c, 0x3b, 0x80, 0x0a, 0x4e, 0xf4, 0x9c, 0xd4, 0x28, 0x32,
  0x8e, 0x7c, 0x3f, 0x4d, 0xee, 0x54, 0xd8, 0x5e, 0xe9, 0x2d, 0xf3, 0x1d,
  0x20, 0xb3, 0x7b, 0x31, 0xcf, 0x4b, 0x76, 0x81, 0x39, 0xe8, 0xb2, 0x94,
  0x07, 0x3c, 0x7f, 0x38, 0xfa, 0x13, 0x25, 0x9f, 0xe7, 0x8d, 0xfb, 0xea,
  0x76, 0xe4, 0x2c, 0x14, 0x9e, 0x37, 0x32, 0x54, 0x62, 0xd2, 0x1e, 0xca,
  0x4d, 0xb7, 0x7c, 0x92, 0x52, 0x04, 0x67, 0xfa, 0x87, 0x86, 0x3f, 0xf2,
  0xdf, 0xaf, 0xac, 0x86, 0x10, 0x20, 0x68, 0x8f, 0xbe, 0xc4, 0x01, 0x6d,
  0x22, 0xe5, 0x0d, 0x37, 0x19, 0xb2, 0x83, 0x08, 0x75, 0xc3, 0x5a, 0xc1,
  0xc4, 0x9c, 0x44, 0xba, 0x18, 0x0f, 0x76, 0xdc, 0xc9, 0x3c, 0xd6, 0x59,
  0x67, 0x5d, 0xa0, 0x3b, 0x0b, 0x7d, 0xb0, 0x18, 0xff, 0xf6, 0x84, 0x43,
  0x81, 0xee, 0x5f, 0x4d, 0x58, 0x22, 0x29, 0x00, 0x78, 0x53, 0xb4, 0x61,
  0x0a, 0x38, 0x8d, 0x1a, 0xf5, 0xa1, 0x1b, 0x6c, 0x65, 0x75, 0x2a, 0xa2,
  0xe6, 0x30, 0xc3, 0x8d, 0x00, 0xd4, 0xe5, 0x7c, 0x14, 0x5c, 0x94, 0xb2,
  0xe8, 0x90, 0x4e, 0x38, 0xf1, 0x5a, 0x80, 0x5e, 0xa7, 0xae, 0xce, 0x3a,
  0x8c, 0x14, 0x44, 0x4b, 0x8e, 0x00, 0x8a, 0x37, 0x1d, 0x55, 0xe3, 0xa1,
  0x8f, 0x38, 0x33, 0x96, 0xcd, 0xf5, 0x9a, 0x00, 0x0a, 0xe5, 0x3d, 0xa0,
  0x59, 0x56, 0xfe, 0xf4, 0x74, 0x85, 0x58, 0x76, 0x38, 0x7c, 0xaf, 0x93,
  0x97, 0x4a, 0x41, 0x15, 0x7e, 0xfe, 0x8a, 0x5e, 0x34, 0x95, 0x06, 0xd6,
  0x64, 0xa0
};

class VaapiDecoderH264Test
    : public FactoryTest<IVideoDecoder, VaapiDecoderH264>
{
protected:
    /* invoked by gtest before the test */
    virtual void SetUp() {
        return;
    }

    /* invoked by gtest after the test */
    virtual void TearDown() {
        return;
    }
};

#define VAAPIDECODER_H264_TEST(name) \
    TEST_F(VaapiDecoderH264Test, name)

VAAPIDECODER_H264_TEST(Factory) {
    FactoryKeys mimeTypes;
    mimeTypes.push_back(YAMI_MIME_AVC);
    mimeTypes.push_back(YAMI_MIME_H264);
    doFactoryTest(mimeTypes);
}

VAAPIDECODER_H264_TEST(Decode_Simple)
{

    VaapiDecoderH264 decoder;
    VideoConfigBuffer configBuffer;
    VideoDecodeBuffer buffer;

    memset(&configBuffer,0,sizeof(VideoConfigBuffer));
    configBuffer.profile = VAProfileNone;

    buffer.data = const_cast<uint8_t*>(g_SimpleH264.data());
    buffer.size = g_SimpleH264.size();
    buffer.timeStamp = 0;

    ASSERT_EQ(YAMI_SUCCESS, decoder.start(&configBuffer));
    ASSERT_EQ(YAMI_DECODE_FORMAT_CHANGE, decoder.decode(&buffer));
    ASSERT_EQ(YAMI_SUCCESS, decoder.decode(&buffer));
    /* pass a NULL buffer to flush output */
    ASSERT_EQ(YAMI_SUCCESS, decoder.decode(NULL));

    EXPECT_TRUE(decoder.getOutput());
}

}
