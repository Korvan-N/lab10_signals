CC=gcc
CFLAGS=-Wall -g

SOURCES=signal_handler.c signal_alarm.c signal_segfault.c signal_sigaction.c
EXECUTABLES=signal_handler signal_alarm signal_segfault signal_sigaction

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)