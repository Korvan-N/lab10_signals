/**
 * File: signal_sigaction.c
 * Modified by: korvan nameni
 * 
 * Brief summary of program: 
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void handler(int sig){
    printf("signal received. sender pid is %d\n", getpid());
    kill(getpid(), SIGTERM);
}
int main(void){
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGUSR1, &sa, NULL);
    printf("pid is %d\nwaiting.\n", getpid());

    while(1){
    }
// to receive a SIGUSR1:(in a new terminal) kill -SIGUSR1 <pid>

}

