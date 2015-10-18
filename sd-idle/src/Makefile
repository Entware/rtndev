# build executable on typing make
all: sd-idle-2.6

%.o: %.c
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c -I. -Iinclude -o $@ $^

sd-idle-2.6: sd-idle-2.6.o
	$(CC) $(LDFLAGS) -o $@ $^ -L.

clean:
	rm -f *.o sd-idle-2.6
