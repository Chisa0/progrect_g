/* init.c */
#include <curses.h>
#include <signal.h>

void show(){
	signal(SIGALRM,show);
	refresh();
}

void my_init_screen(){
	initscr();
	signal(SIGALRM,show);
}
