GCC := gcc
CFLAGS := -Wall -I .

SRCS := $(wildcard *.c)
PROGS := $(patsubst %.c,%,$(SRCS))

.PHONY: all clean

all: $(PROGS)

# rule: build executable 'name' from 'name.c'
%: %.c
	$(GCC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
