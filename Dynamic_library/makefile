CC=gcc
CFLAGS =-c -fpic

all:sum  display mul libdynamic.so

%.o:%.c
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o sum  mul display

