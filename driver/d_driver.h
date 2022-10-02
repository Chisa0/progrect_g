/* turtle.c -- 一个简单的绘图系统，由字母和数字组成，命令中间用空格隔开 */
#include <stdio.h>
#include <string.h>

#define NUM    2

typedef struct {
	char cmd;			//命令参数
	void (*func)(int);		//调用例程
}Command;

Command *findCommand(const Command cmds[], int n, int cmd);
void turtle(const Command cmds[]);
void doPenDir(int);
char * s_gets(char *st, int n);


//主程序，读取一行，查找命令，获取参数，然后调用处理函数
void turtle(const Command cmds[]){
	char cmd_[NUM];
	while (s_gets(cmd_, NUM) != NULL){ 
	        int count = 0;
                Command *cmd = findCommand(cmds, 4, *cmd_);

                if(cmd) {
			cmd->func(cmd_[0]);	
			if (count %7)
				puts("");
                }
		else
			puts("Please enter w a d or s. ");   
        }
}

//对表执行线性搜索，返回匹配的条目或NULL
Command *findCommand(const Command cmds[], int n, int cmd){
	int i = 0;
	Command *p = (Command *)cmds;

	for (i=0;i<n;i++){
		if (cmds[i].cmd == cmd || cmds[i].cmd == cmd + 32)
			return p + i;
	}

	fprintf(stderr, "Unknown command '%c'\n",cmd);
	return 0;
}



void doPenDir(int d){
	printf("%c\n",d);
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

char * s_getchar(char *st){
	
}
