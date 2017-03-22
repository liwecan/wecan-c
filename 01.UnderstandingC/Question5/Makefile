CC=gcc
STRIP =
CFLAGS = -Wall -g
OPFLAGS = -O3 -Wall -g

.PHONY: all
all:
	$(CC) $(CFLAGS) -o test5-1 test5-1.c
	$(CC) $(OPFLAGS) -o test5-1_O3 test5-1.c
	$(CC) $(CFLAGS) -o test5-2 test5-2.c
	$(CC) $(OPFLAGS) -o test5-2_O3 test5-2.c
	$(CC) $(CFLAGS) -o test5-3 test5-3.c
	$(CC) $(OPFLAGS) -o test5-3_O3 test5-3.c

.PHONY: clean
clean:
	rm -rf test5-1 test5-1_O3 test5-2 test5-2_O3 test5-3 test5-3_O3

 # ulimit -s
 # sudo cat /proc/1/maps | grep stack
 # ps aux | grep init
