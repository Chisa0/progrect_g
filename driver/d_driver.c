/* turtle.c -- һ���򵥵Ļ�ͼϵͳ������ĸ��������ɣ������м��ÿո���� */
#include <stdio.h>
#include <string.h>

#define ARG    1
#define NO_ARG 0

typedef struct {
	char cmd;			//�������
	int hasArg;			//��������
	void (*func)(int, int);		//��������
}Command;

Command *findCommand(const Command cmds[], int n, int cmd);
void turtle();
int getArg(const char *buff, int *result);
void doSelectPen(int, int);
void doPenUp(int, int);
void doPenDown(int, int);
void doPenDir(int, int);
char * s_gets(char *st, int n);

static Command cmds[] = { 
                { 'P', ARG,    doSelectPen },
                { 'U', NO_ARG, doPenUp },
                { 'D', NO_ARG, doPenDown },
                { 'N', ARG,    doPenDir },
                { 'E', ARG,    doPenDir },
                { 'S', ARG,    doPenDir },
                { 'W', ARG,    doPenDir }
        };  

int main(){

	turtle();
	
	return 0;
}

//�����򣬶�ȡһ�У����������ȡ������Ȼ����ô�����
void turtle(){
	int num = 4;
	char cmd_[num];
	while (s_gets(cmd_, num) != NULL){ 
	
                Command *cmd = findCommand(cmds, 7, *cmd_);

                if(cmd) {
                        int arg = 0;
			if (cmd->hasArg && !getArg(cmd_ + 1, &arg)){
				fprintf(stderr, "'%c' needs an argument\n", cmd_[0]);
				continue;
			}
			cmd->func(cmd_[0], arg);	
                }
		else
			puts("Please enter P U D N E S or W, and needs an argument. ");   
        }
}

//�Ա�ִ����������������ƥ�����Ŀ��NULL
Command *findCommand(const Command cmds[], int n, int cmd){
	int i = 0;
	Command *p = (Command *)cmds;

	for (i=0;i<n;i++){
		if (cmds[i].cmd == cmd)
			return p + i;
	}

	fprintf(stderr, "Unknown command '%c'\n",cmd);
	return 0;
}

//��ȡ��ֵ����
int getArg(const char *buff, int *result){
	return sscanf(buff, "%d", result) == 1;
}

void doSelectPen(int d, int s){
	puts("pen");
}

void doPenUp(int d, int n){
	puts("pen up");
}

void doPenDown(int d, int n){
	puts("pen down");
}

void doPenDir(int d, int n){
	printf("%c %d\n",d,n);
}

char * s_gets(char *st, int n){ 
        char *ret_val;
        char *find;
    
        ret_val = fgets(st, n, stdin);
        if (ret_val){
                find = strchr(st,'\n');                 //���һ��з�
                if (find)    
                        *find = '\0';
                else
                        while (getchar() != '\n')
                                continue;               //����������
        }   
	return ret_val;
}      
