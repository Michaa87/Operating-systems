#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<unistd.h>
#include <sys/wait.h>

int main() {

 int i,j;

 
 for (i =0; i<10; i++) {
  switch (fork()) {
	case -1: fprintf (stderr, "Erreur dans %d\n", getpid());
		 perror ("fork") ;
		 exit(1);

	case 0:
// on est dans le fils
		
		for (j=0; j<10; j++) {
			printf ("je suis le fils numero %d\n",i);
		fflush (stdout);	
}
		exit(0);
  default: ;//on est dans le père
  }
  }

 for (i=0;i<10; i++){ wait(NULL); }
 
 exit(0); 
}
