#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
 for (int i=0; i<2; i++) {
	if (fork() ==0) { exit(0); }
	wait(NULL);
	exit(0);
 }

}
