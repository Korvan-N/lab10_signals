CC=gcc
CFLAGS=-Wall -g

SOURCES=signal_handler.c
EXECUTABLES=signal_handler

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)