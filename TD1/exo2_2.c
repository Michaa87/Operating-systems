#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

// le programme multido
int main(int argc, char *argv[]) {


 int status;

 if (argc<2) {
  printf ("Pas assez d'arguments pour le programme\n");
  exit(0);
 }
 
 for (int i=0; i<5; i++) {
  switch (fork()) {
   // on crée un processus séparé 
   case -1: fprintf (stderr, "Erreur dans %d\n", getpid());
            perror ("fork");
            exit(1);
   case 0:   

	    execvp ( argv[1], &argv[1]);
 
  default : 
	    if (wait(&status)>0) {
	    // si un des fils a changé de status
	printf("status: %d %d %d\n", status, WIFEXITED(status), WEXITSTATUS(status));
	if (WIFEXITED(status)!=0 && WEXITSTATUS(status)!=0) {
		printf("child returned an error");
		exit(1);
        }
}
 
 }
}
return 0;
}

