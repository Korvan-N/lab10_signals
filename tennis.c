/**
 * File: tennis.c
 * Modified by: korvan nameni
 * 
 * Brief summary of program: tennis volley with a different instance executable
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
int score = 0;
int score2 = 0;
char* real_score[] = {"love", "15", "30", "40", "game"};
union sigval val;
void handler(int sig, siginfo_t* info, void* context){
    int volley = info->si_value.sival_int;
    if(volley == 2){ //line up command line output for first serve
        printf("\nlove - love\n");
    }
    usleep(1000*500); //sleep for half a second
    if(volley == 0){
        printf("my point\n");
        score += 1;
        printf("\n%s - %s\n", real_score[score], real_score[score2]);
        if(score >= 4){ //game won
            printf("I win!\n");
            kill(getpid(), SIGINT);
        }
    }
    srand(time(NULL));
    volley = rand()%100;
    if(volley<80){ //return the serve: 80% chance of returning it.
        val.sival_int = 1;
        printf("returned\n");
        sigqueue(info->si_pid, SIGUSR1, val);
    }
    else{ //failed to return the serve
        score2+=1;
        val.sival_int = 0;
        printf("failed to return\n");
        printf("\n%s - %s\n", real_score[score], real_score[score2]);
        sigqueue(info->si_pid, SIGUSR1, val);
        if(score2 >= 4){ //game lost
            printf("I lose!\n");
            kill(getpid(), SIGINT);
        }
    }
}
int main(void){
    srand(time(NULL));
    val.sival_int = 2; // set sival_int to serve

    struct sigaction sa;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask); //clear all signals
    sa.sa_flags = SA_SIGINFO; // 3 args in the handler instead of 1
    sigaction(SIGUSR1, &sa, NULL); //register user1 signal
    printf("your pid is %d\nenter other pid: ", getpid());

    char buf[20];
    fgets(buf, sizeof(buf), stdin); //ask for other pid
    if(strcmp(buf, "")){
        pid_t pid = atoi(buf);
        int ret = sigqueue(pid, SIGUSR1, val);
        if(ret == -1){ // input checking
            printf("enter a valid pid.\n");
            exit(0);
        }
        printf("love - love\n"); //print initial score
    }
    while(1){
    }

}

