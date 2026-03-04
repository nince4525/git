prefix = auxf
source = $(prefix).c
header = $(prefix).h
target = lib$(prefix).so

CC = gcc
CCFLAG = -Wall -fsanitize=address
INCLUDES = -I$(DSHOME)/include

all:
	$(CC) -fpic -c $(source) $(CCFLAG) $(INCLUDES) -o $(target)
	
install:
	cp -f $(target) $(DSHOME)/lib
	cp -f $(header) $(DSHOME)/include

clean:
	rm -f $(target)
