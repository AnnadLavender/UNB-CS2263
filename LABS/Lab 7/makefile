GCC = gcc
TARGETS = sortTest sortTest2
OBJS = Point2D.o Strings.o
HDRS = Point2D.h Strings.h
CFLAGS = -lm

all: $(TARGETS)

sortTest:
	$(GCC) $@.c -o $@

sortTest2: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) $@.c -o $@

%.o: %.c
	$(GCC) -c $*.c

clean:
	rm -f $(TARGETS) *.o
