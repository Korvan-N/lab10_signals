# lab10_signals
This repo is designed to demonstrate the use of the different POSIX signals

`SIGNAL_HANDLER`
Program runs indefinitely. When a SIGINT is sent, the program prints out a notification. Run with: `./signal_handler`

`SIGNAL_ALARM`
Program waits for an alarm signal and exits on receive. signal sent after 5 seconds. Run with `./signal_alarm`

`SIGNAL_SEGFAULT`
Program handles a segfault signal by printing a custom message and ending the program. Run with `./signal_segfault`

`SEND_SIGNAL/RECEIVE_SIGNAL`
Demonstration of sending signals across active programs using PIDs. Program transmits a random integer. To run, execute `./recv_signal` in 1 terminal and execute `./send_signal` in another.