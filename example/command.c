#include "../driver/my_driver.h"

void my_driver(const command cmds[], int n, char ch);
void to_dir(char);
void InitQueue(LINKQUEUE * link);
int EnQueue(LINKQUEUE * link, char * ch);
char PopQueue(LINKQUEUE * link);

int main(){
	initscr();
	command cmds[] = 
	{
		{'a', to_dir},
		{'w', to_dir},
		{'d', to_dir},
		{'s', to_dir}
	};

	LINKQUEUE link;
	InitQueue(&link);  //初始化消息
	for (int i = 0;i < 5; i++) {
	char ch = getch();
	EnQueue(&link, &ch);	

	int n = (int) sizeof(cmds) / sizeof(cmds[0]);
	my_driver(cmds, n, PopQueue(&link));}

	endwin();
	
	return 0;
}
