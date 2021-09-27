<h1>DYNAMIC_LIBRARY</h1>

Dynamic libraries help in dynamic linking. Another name for dynamic library is "shared object" or "DLL files" in windows. The extension for dynamic library files is .so

When linker is dynamically linking with dynamic libraries, required function definitions are not copied into executable file. Thus executable size is less.

Shared libraries serve a great advantage of sharing a single copy of library amoung multiple programs, hence they are called shared libraries

<h2>Steps to create dynamic libraries</h2>

step 1: Compile the source files using -fpic option

gcc -c -fpic filename.c

step2: create shared library using follwing command

gcc -shared -o libxyz.so filename.o

step3: link the shared library to program

gcc filename.c ./library.so -o filename

<h1>LIBRARY_PATH</h1>
By default the linker search for libraries in standard path.if our libraries present in non standard path. the environment variable LD_LIBRARY_PATH tells the linker to search for libraries in path initilized to LD_LIBRARY_PATH.

<h3>step1:</h3> telling Gcc where to find the shared library
gcc -L/home/vsiddheswari -o main main.c -ldisplay 

<h3>step2:</h3> Making library available at runtime using LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/siddheswari

<h3>step3:</h3> run the program
./main
