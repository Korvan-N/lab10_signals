/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: korvan nameni
 * 
 * Brief summary of modifications: seg fault handler added, print a message then exit
 * NOTE: if the program does not end on the signal receive then the handler runs indefinitely.
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void seg_handler(){
    printf("segmentation fault!!\n");
    kill(getpid(), SIGTERM);
}
int main (int argc, char* argv[]) {
    signal(SIGSEGV, seg_handler);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}