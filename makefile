CC=gcc
CFLAGS=-Wall -g

SOURCES=signal_handler.c signal_alarm.c
EXECUTABLES=signal_handler signal_alarm

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)