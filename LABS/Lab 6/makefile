GCC = gcc
TARGETS = genIntBin sortInMemoryIntBin
CFLAGS = -lm

all: $(TARGETS)

genIntBin:
	$(GCC) $@.c -o $@

sortInMemoryIntBin:
	$(GCC) $(CFLAGS) $@.c -o $@

%.o: %.c
	$(GCC) -c $*.c

clean:
	rm -f $(TARGETS) *.o
