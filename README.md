# pebble-binary

This is a [pebble](http://getpebble.com) watchface which displays binary versions of the month, day, hour, minute, and second.

## How to get

[Download to your phone](http://pebble-binary.s3-website-us-east-1.amazonaws.com/build/binary.pbw)

## How to build

This watchface was compiled with Android SDK release 1. Make sure you setup the SDK according to [pebble's instructions](http://developer.getpebble.com). Then clone this repo (or your fork) into the watches directory. Then add the symlinks.

```
cd ~/pebble-dev/pebble-sdk-release-001/watches
git clone http://github.com/yanatan16/pebble-binary binary
../tools/create_pebble_project.py --symlink-only ../sdk binary
```

## Screenshot

![Binary Watchface Screenshot](http://jeisen.github.com/pebble-binary/img/binary_screenshot.jpg)

## License

Copyright (c) 2013 Jon Eisen

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
