/**
 * File: signal_alarm.c
 * Modified by: korvan nameni
 * 
 * Brief summary of program: wait 5 seconds, receive an alarm signal, kill program.
 */
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
void handle_alarm(){
    printf("ALARM\n");
    kill(getpid(), SIGTERM);
}
int main(void){
    alarm(5);
    signal(SIGALRM, handle_alarm);
    while(1){
        puts("sleep");
        sleep(1);
    }
}