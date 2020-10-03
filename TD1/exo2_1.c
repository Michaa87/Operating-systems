#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
 
 if (argc<2) {
  printf("Pas assez d'arguements pour le programme\n");
  exit(1);
 }
 
 execvp( argv[1] , &argv[1]);
 return 0;

}
