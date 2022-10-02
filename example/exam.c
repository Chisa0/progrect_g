#include <stdio.h>

typedef struct {
	char ch;
}elem;

void ch_char(elem *);

int main (){
	elem el;
	el.ch = 'c';
	ch_char(&el);
	printf("%c", el.ch);
	return 0;
}

void ch_char(elem * el){
	el->ch +=1;
}
