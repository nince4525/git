sources = *.c

CC = gcc
CCFLAG = -Wall

ifdef windir
ASAN=
DEL=del
else
ASAN=-fsanitize=address
DEL=rm
endif

HOME = $(DSHOME)

INCLUDES = -I$(HOME)/include -I$(HOME)/build
LIBS = -L$(HOME)/lib -lauxf -lm

all:
	$(CC) $(sources) $(CCFLAG) $(ASAN) -o $(target) $(INCLUDES) $(LIBS)

.PHONY: clean
	
clean:
	$(DEL) $(target)