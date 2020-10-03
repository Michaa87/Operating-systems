#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void Recuperation(int sig) {
  static int compt=0;
  if (++compt ==5) {
	printf("Wiating !\n");
  exit(0);
}
  else {
	printf("ok je recupere le signal\n");
}
}

int main() {
  struct sigaction nvt, old; //on crée deux objets de la classe sigaction, nouveau et ancien
  memset(&nvt, 0, sizeof(nvt));
  
  nvt.sa_handler = Recuperation;
  sigaction (SIGINT, &nvt, &old);
  printf("taper 5 ^C pour arreter le programme");
  while(1); 
  

}
