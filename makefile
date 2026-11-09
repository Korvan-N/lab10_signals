CC=gcc
CFLAGS=-Wall -g

SOURCES=signal_handler.c signal_alarm.c signal_segfault.c
EXECUTABLES=signal_handler signal_alarm signal_segfault

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)