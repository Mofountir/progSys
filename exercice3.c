#include <stdio.h>
#include <stdlib.h>

void afficherBinaire(int n) {
    if (n > 1) {
        afficherBinaire(n / 2);
    }
    printf("%d", n % 2);
}

int main(int argc, char *argv[]){
    int n = 7;
    printf("Représentation binaire de %d est : ", n);
    afficherBinaire(n);
    printf("\n");
    return 0;
}