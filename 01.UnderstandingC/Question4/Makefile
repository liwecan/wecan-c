CC=gcc
STRIP =
CFLAGS = -std=c99
LDFLAGS = -shared -ldl -fPIC
DEF_FLAGS = -D_GNU_SOURCE
DEBUG = yes

SHARED_LIB = test4.so
SOURCE = test4.c

ifeq ($(DEBUG),yes)
	CFLAGS += -Wall -g
else
	CFLAGS += -O3
endif

.PHONY: all
all:
	$(CC) $(DEF_FLAGS) $(LDFLAGS) -o $(SHARED_LIB) $(SOURCE)

.PHONY: test
test:
	LD_PRELOAD=./$(SHARED_LIB) ls

.PHONY: clean
clean:
	rm -rf $(SHARED_LIB)
