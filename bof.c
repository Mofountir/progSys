/*
Fichier "bof.c" : Simplification du use case de
https://zestedesavoir.com/articles/100/introduction-aux-buffer-overflows/
et à compiler avec la commande : gcc bof.c -fno-stack-protector */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 12
/*======================*/
int main(int argc, char *argv[]){    
  int access_granted = 0;
  char password[BUFSIZE] = "hello"; /* Le vrai mot de passe */
  char proposal[BUFSIZE];                  /* Mot de passe propose */

  printf("Enter the password to get the access granted! ");
  scanf("%s", proposal);

  if (strcmp(proposal,password) == 0)
    access_granted = 1;

  printf("%p\n",&access_granted);
  printf("%p\n",proposal);
  printf("%p\n",&proposal[strlen(proposal)]);
    
  printf("%d\n",access_granted);
  /* => Core dumped en cas de stack smashing detected */
  if(access_granted) { /* Si l'autorisation est donnée */ 
    char *newargv[] = {NULL};
    char *newenviron[] = {NULL};  
    printf("Access granted ! \n"); /* On execute un nouveau Shell */
    execve("/bin/sh", newargv, newenviron);
  } else { printf("ACCESS DENIED !\n");
  }
  exit(EXIT_SUCCESS);
}
