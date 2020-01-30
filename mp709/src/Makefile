# build executable on typing make
all: mp709

%.o: %.c
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c -I. -Iinclude -o $@ $^

mp709: mp709m.o
	$(CC) $(LDFLAGS) -lusb-1.0 -o $@ $^ -L.

clean:
	rm -f *.o mp709
