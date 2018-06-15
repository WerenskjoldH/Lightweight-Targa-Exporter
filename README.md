# Lightweight-Targa-Exporter
I have needed to export Targa files a surpisingly amount of times over the past year. So, in short, I made a VERY lightweight Targa file exporter with no requirements.

# What is this?
This is a very lightweight Targa file exporter with the aim of simply plugging it into a program and exporting a targa file with ease.

# How To Use
Aight, so I made this as easy to implement as I possibly could, just follow these two steps:

  1. Add the file to your project
  2. Add <code>#include "InputManager.h"</code> to the top of your file
  3. Initialize the targaInfo struct
  4. Edit the pixel information via the public <code>pixel* data;</code> variable
  5. Call the <code>outputImage(char* fileName)</code> method
  6. Writes the .tga file to the programs directory
  
# Important Info
* Okay so the Targa image format is very simple, but can sometimes trip people up, thus I took care of most of the file header. If you want to edit the file header you can easily adjust the <code>targaInfo</code> struct initializer's parameters.

* Targa is a bottom up image format! This means the first pixel, <code>[targaInfo]->data[0]</code>, is the bottom left corner of the image. <code>[targaInfo]->data[1]</code> is the pixel in the bottom row of the image in the 2nd column.

* Targa pixels are read blue, green, red, and then alpha. It is common to think rgba, but don't let this trip you up.


## License

I do not claim to have any rights to the Targa file format.

MIT License

Copyright (c) 2018 Hunter Werenskjold

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

## Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
