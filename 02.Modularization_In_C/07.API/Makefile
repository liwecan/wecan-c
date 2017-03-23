CC=gcc
STRIP =
CFLAGS = -std=c99
DEBUG = yes
REL_INC = ./include
REL_LIB = ./lib/array.so

CFLAGS += -I$(REL_INC)

PROG = user
OBJS = user.o

ifeq ($(DEBUG),yes)
	CFLAGS += -Wall -g
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(REL_LIB) -o $(PROG) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(PROG) $(OBJS)
