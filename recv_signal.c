/**
 * File: recv_signal.c
 * Modified by: korvan nameni
 * 
 * Brief summary of program: receive a SIGUSR1 signal and print its si_value.sival_int
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void handler(int sig, siginfo_t* info, void* context){
    printf("signal received. sival_int is %d\n", info->si_value.sival_int);
    kill(getpid(), SIGTERM);
}
int main(void){
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    printf("pid is %d\nwaiting.\n", getpid());

    while(1){
    }
}

