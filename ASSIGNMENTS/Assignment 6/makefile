GCC = gcc
TARGETS = playStack playQueue
OBJS = Point2D.o
HDRS = Point2D.h
CFLAGS = -lm

all: $(TARGETS)

playStack: stack.o $(OBJS) stack.h $(HDRS)
	$(GCC) $(CFLAGS) stack.o $(OBJS) $@.c -o $@

playQueue: queue.o $(OBJS) queue.h $(HDRS)
	$(GCC) $(CFLAGS) queue.o $(OBJS) $@.c -o $@

%.o: %.c
	$(GCC) -c $*.c

clean:
	rm -f $(TARGETS) *.o
