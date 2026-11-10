/**
 * File: signal_sigaction.c
 * Modified by: korvan nameni
 * 
 * Brief summary of program: wait until sigusr1 signal received, print sender pid
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void handler(int sig, siginfo_t* info, void* context){
    printf("signal received. sender pid is %d\n", info->si_pid);
    kill(getpid(), SIGTERM);
}
int main(void){
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask); //clear all signals
    sa.sa_flags = SA_SIGINFO; // 3 args in the handler instead of 1
    sigaction(SIGUSR1, &sa, NULL); //register user1 signal
    printf("pid is %d\nwaiting.\n", getpid());

    while(1){
    }
// to receive a SIGUSR1:(in a new terminal) kill -SIGUSR1 <pid>

}

