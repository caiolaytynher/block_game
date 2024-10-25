@echo off

if not exist build mkdir build
if not exist build\debug mkdir build\debug

cl /Zi /DGLFW_INCLUDE_NONE ^
    /Ivendor\src ^
    /Ivendor\glfw\include ^
    /Ivendor\glad\include ^
    /Ivendor\cglm\include ^
    /Febuild\debug\block_game.exe ^
    /Fdbuild\debug\ ^
    /Fobuild\debug\ ^
    src\*.c ^
    vendor\glad\src\glad.c ^
    User32.lib Gdi32.lib Shell32.lib opengl32.lib ^
    vendor\glfw\lib\debug\glfw3.lib ^