#include <stdio.h>

int main(){
	char c;
	for(;system("stty -echo"), c = getchar();){
		system("stty echo");
		printf("You have inputed: %c\n",c);
	}
	return 0;
}
