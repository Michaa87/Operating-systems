// TP1, EXO1, Q2

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void chaine (int n) {
 printf ("Au départ le pid est %d et celui du père est %d\n", getpid(), getppid());

 for (int i=0; i<n; i++) {
  if (fork()== 0) {
   // on est dans le fils
	printf ("Le pid du fils est %d\n", getpid());
	printf("Le pid du père est %d\n", getppid());
	exit(0);
  }
  else {
   // si l'on est dans le père, il faut lui demander d'attendre les fils
	wait(NULL);
  }
 }
}

void arbre(int n) {
 printf ("au début le pid du fils est %d et celui du père est %d\n", getpid(), getppid());

 for (int i=0; i<n; i++) {
  if (fork()) {
   // fils
   printf("le pid du fils est %d\n", getpid());
   printf("le pid du père est %d\n", getppid());
  }	
  else {
   //père
   // PAs de wait(NULL) sinon les pères quittent pas assez vite
   exit(0);
  }
 }
}


int main(int argc, char *argv[]) {
 int n=3;
 if (argc<2) {
  printf ("Pas assez de paramètres pour lancer le programme\n");
  exit(1);
 }

 switch (atoi(argv[1])) {
  case 1: arbre(atoi(argv[2])); break;
  case 2: chaine(atoi(argv[2])); break;
 }
 
 return 0;

}
