#!/bin/sh

# For MSYS2 mingw32/64

pacman -S --needed --noconfirm mingw-w64-i686-toolchain
#pacman -S --needed --noconfirm mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain

# rm -rf i686/*.o i686/*.exe
mkdir i686

# rm -rf x86_64/*.o x86_64/*.exe
mkdir x86_64

windres oexplore.rc --target=pe-i386 -Ii686/ i686/oexplore.o
/mingw32/bin/i686-w64-mingw32-gcc -Os -mwindows -static-libgcc -nostdlib -s -o i686/oexplore.exe oexplore.c i686/oexplore.o -lkernel32 -luser32 -lole32 -loleaut32 -luuid -lshell32

# windres oexplore.rc --target=pe-x86-64 -Ix86_64/ x86_64/oexplore.o
# /mingw64/bin/x86_64-w64-mingw32-gcc -Os -mwindows -static-libgcc -nostdlib -s -o x86_64/oexplore.exe oexplore.c x86_64/oexplore.o -lkernel32 -luser32 -lole32 -loleaut32 -luuid -lshell32
