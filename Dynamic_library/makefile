CC = gcc
CFLAGS = -c -fpic

all: sum main libabc.so

%.o : %.c
       $(CC) $(CFLAGS)$^

clean:
	rm -rf *.o sum main

