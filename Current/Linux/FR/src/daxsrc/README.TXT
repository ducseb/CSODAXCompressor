The included Makefile should work in linux/cygwin.

Requirements: zlib (http://www.zlib.net)

By default, the built program won't show percentage progress if the target is not win32.
If you want percentage support, you'll have to implement three functions: getx(), gety() and
gotoxy(x, y), and then define WEHAVE_XY_FUNCTIONS