/**
 * File: send_signal.c
 * Modified by:korvan nameni
 * 
 * Brief summary of program: send a signal with sival_int
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand(time(NULL)); //randomize seed

    union sigval val;
    val.sival_int = rand()%100; //set sival_int

    FILE* fp = popen("pidof recv_signal", "r"); //get executable pid
    if(fp == NULL){
        printf("null pointer.\n");
        exit(0);
    }
    pid_t pid;
    if(fscanf(fp, "%d", &pid) != 1){ //parse pid
        printf("executable not running.\n");
        exit(0);
    }

    while(1){
        printf("sending random int %d to %d...\n", val.sival_int, pid);
        sleep(1);
        sigqueue(pid, SIGUSR1, val); //send sigusr1 with its value
        exit(0);
    }
}

