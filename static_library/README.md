<h1>Library</h1>
Library is a collection of predefined functions. Library cosists of precompiled code in the form of object files

<h2>Static Library</h2>
Static libraries is the result of the linker making the copy of all used library function definitions to the executable file. static linking creates larger size executable files, and need more space on disk and main memeory. Another name for static library iis "archive files". The extension of static library is .a .' One major advntage of static libraries is speed.

<b>static Linking:</b> 

steps to create static library:

you should create object files for libray functions source code of object files sum.o -- code mul.o -- code print.o -- code

the follwing command will create static library with name libabc.a using sum.o, mul.o, print.o object files

<b>ar -rcsv libabc.a sum.o mul.o print.o</b>

r: it replaces the objects in the library with new ones in command line. if library doesn't contain any objects, this will add them to the library. 
c: do not warn if library is newly created. v: means verbose, which tells ar to keep you informed about what it's doing. 
s: it tells ar to create a symbol table, which is somthing extra that gcc needs when using a library.
v:means verbose,which tells ar to keep you informed about what it's doing.

To list out the object files in given library the follwing command is used
ar -t libabc.a

To compile with your own static library use the library of cc command precedded by source filename

gcc -static main.c libstatic.a -o main

here mainis executable file 
