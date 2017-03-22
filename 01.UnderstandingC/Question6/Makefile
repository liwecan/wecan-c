CC=gcc
STRIP =
CFLAGS =
LDFLAGS = -lrt
DEBUG = yes

PROG = test6
OBJS = test6.o

ifeq ($(DEBUG),yes)
	CFLAGS += -Wall -g
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(PROG) $(OBJS)
