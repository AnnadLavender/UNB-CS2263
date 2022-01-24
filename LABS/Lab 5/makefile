GCC = gcc
CFLAGS = -g -Wall -Wshadow
TARGETS = stringTest1 stringTest0 stringListTest
OBJS = Strings.o
HDRS = Strings.h
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --verbose --log-file=

all: $(TARGETS)

stringListTest: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

stringTest1: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

stringTest0: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(TARGETS) *.o
