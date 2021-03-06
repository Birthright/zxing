// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __MAGICK_BITMAP_SOURCE_H_
#define __MAGICK_BITMAP_SOURCE_H_
/*
 *  Copyright 2010-2011 ZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Magick++.h>
#include <zxing/LuminanceSource.h>

namespace zxing {

class MagickBitmapSource : public LuminanceSource {
private:
  typedef LuminanceSource Super;
  Magick::Image image_;

public:
  MagickBitmapSource(Magick::Image& image);

  ~MagickBitmapSource();

  ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
  ArrayRef<char> getMatrix() const;

  bool isCropSupported() const;
  Ref<LuminanceSource> crop(int left, int top, int width, int height);
  bool isRotateSupported() const;
  Ref<LuminanceSource> rotateCounterClockwise();
};

}

#endif /* MAGICKMONOCHROMEBITMAPSOURCE_H_ */
