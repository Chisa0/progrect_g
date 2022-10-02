#include <curses.h>
#include "../driver/my_driver.h"
//#include <sys/time.h>

void InitQueue(LINKQUEUE *);
int EnQueue(LINKQUEUE *, char *);
char PopQueue(LINKQUEUE *);
int  IsEmptyQueue(LINKQUEUE *);
int IsFullQueue(LINKQUEUE *);
char * s_gets(char *st, int n);

int main(){
	initscr();
	char ch;
	LINKQUEUE link;
	InitQueue(&link);
	puts("初始队列");
	printf("是空队列? %d status=%d 队头元素=%c 队尾元素=%c\n\n",IsEmptyQueue(&link),link.status,link.ch[0],link.ch[1]);

	puts("按任意键开始");
	//s_gets(&ch, 2);
	getch();
	puts("");

	puts("插入元素");	
	//s_gets(&ch, 2);	
	ch = getch();
	EnQueue(&link,&ch);
	printf("是空队列? %d status=%d 队头元素=%c 队尾元素=%c\n\n",IsEmptyQueue(&link),link.status,link.ch[0],link.ch[1]);
	
	puts("插入元素");	
	//s_gets(&ch, 2);
	ch = getch();
	EnQueue(&link, &ch);
	printf("是满队列? %d status=%d 队头元素=%c 队尾元素=%c\n\n",IsFullQueue(&link),link.status,link.ch[0],link.ch[1]);

	printf("输出并删除队首=%c\n",PopQueue(&link));	
	printf("是满队列? %d status=%d 队头元素=%c 队尾元素=%c\n\n",IsFullQueue(&link),link.status,link.ch[0],link.ch[1]);

	return 0;
}

