#include <stdio.h>
#include <unistd.h>

int main(){
	char buff[1024];
	setvbuf(stdout, buff, _IOFBF, 100);
	printf("print");
	while(1) sleep(1);
	return 0;
}
