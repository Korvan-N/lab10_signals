CC=gcc
CFLAGS=-Wall -g

SOURCES=signal_handler.c signal_alarm.c signal_segfault.c signal_sigaction.c recv_signal.c send_signal.c
EXECUTABLES=signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)