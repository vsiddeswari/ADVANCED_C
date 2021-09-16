<h1>DYNAMIC_LIBRARY</h1>

Dynamic libraries help in dynamic linking. Another name for dynamic library is "shared object" or "DLL files" in windows. The extension for dynamic library files is .so

When linker is dynamically linking with dynamic libraries, required function definitions are not copied into executable file. Thus executable size is less.

Shared libraries serve a great advantage of sharing a single copy of library amoung multiple programs, hence they are called shared libraries

<b>Steps to create dynamic libraries</b>

step 1: Compile the source files using -fpic option
gcc -c -fpic filename.c

step2: create shared library using follwing command
gcc -shared -o libxyz.so filename.o

step3: link the shared library to program
gcc filename.c ./library.so -o filename


