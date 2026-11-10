https://github.com/Korvan-N/lab10_signals
Korvan-N

# What is a signal disposition?
a signal disposition determines how a signal is handled.

# What is a signal handler? What is it used for?
if the signal disposition determines that the signal must be sent to a function, the signal handler is code run when a signal is received.

# Name and describe each of the five (5) default dispositions?
SIG_DFL - terminate process
SIG_IGN - ignore the signal
SIG_CORE - terminate process, write core dump (SIGSEGV)
SIG_STOP - stop the process
SIG_CONT - resume the process

# Name and describe one way to programmatically send a signal to a process. Be able to give an example (the code) to send a signal.
kill(SIGTERM, pid) and sigqueue(pid, SIGTERM, 10)

# Name and describe one way to send a signal to a process from the command line.
kill -SIGTERM pid

# Be able to give an example (the command, key combination, etc.) to send a signal.
ctrl+c (for sigterm), kill -SIGNAL pid

# Can the disposition be overridden by a signal handler? Why do you think this is the case?
no, handler dependent on the disposition.

Research the SIGSEGV signal - Modify signal_segfault.c to install a handler for SIGSEGV.
In your handler print a message that a segmentation fault was received, then return
without performing any other action. - Run the program and observe the results.
# What do you observe? Why is this happening?
if the program does not end on the signal receive then the handler runs indefinitely. because when a signal is sent the code resumes right where it left off.

# What if a process wants to send data along with a signal, for example when using one of the user signals (e.g. SIGUSR1)?
signal must be registered with a `sigaction` with flag `SA_SIGINFO`. data must be sent with a `sigval` struct through `sigqueue`.