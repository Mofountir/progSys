#include <stdlib.h>
#include <stdio.h>
int main (int argc, char *argv[]){
    extern char** environ;
    int i;
    printf("Environement: \n");
    while (environ[i] != NULL){
        printf("%d (%p): %s\n", i, (void*) environ[i], environ[i]);
        i++;
    }
    exit(0);
}