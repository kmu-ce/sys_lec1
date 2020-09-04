# A simple makefile for building a program composed of C source files.

PROGRAMS = num mem

all:: $(PROGRAMS)

CC = gcc
CFLAGS = -g -O0 -std=gnu99 -fno-stack-protector -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
