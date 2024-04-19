#include <stdio.h>

void process_chain(int n) {
	if (n == 0) {
		return;
	}
	else {
		printf("n = %d\n", n);
		fork();
	}
}


int main(int argc, char *argv[]) {
	process_chain(3);
	return 0;
}