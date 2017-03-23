CC=gcc
STRIP =
CFLAGS = -std=c99
DEBUG = yes

PROG = user
OBJS = user.o array.o

ifeq ($(DEBUG),yes)
	CFLAGS += -Wall -g
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(PROG) $(OBJS)
