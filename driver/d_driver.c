/* turtle.c -- 一个简单的绘图系统，由字母和数字组成，命令中间用空格隔开 */
#include <stdio.h>
#include <string.h>

#define ARG    1
#define NO_ARG 0

typedef struct {
	char cmd;			//命令参数
	int hasArg;			//带参数码
	void (*func)(int, int);		//调用例程
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

//主程序，读取一行，查找命令，获取参数，然后调用处理函数
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

//对表执行线性搜索，返回匹配的条目或NULL
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

//读取数值参数
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
                find = strchr(st,'\n');                 //查找换行符
                if (find)    
                        *find = '\0';
                else
                        while (getchar() != '\n')
                                continue;               //清理输入行
        }   
	return ret_val;
}      
