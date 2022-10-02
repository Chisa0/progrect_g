/* my_driver.c */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>

//��Ϣ
typedef struct {
	int num;	//Ԫ������,��ʼֵΪ0
	int status;	//��Ϣ��
	char ch[2];	//0Ϊ��ͷ��1Ϊ��β
}LINKQUEUE;

//�������
typedef struct {
	char cmd;	  
	void (*func)(char);   //���ú���
}command;

int IsEmptyQueue(LINKQUEUE * link){
	return !link->num;
}

int IsFullQueue(LINKQUEUE * link){
	return 2 == link->num;
}

void InitQueue(LINKQUEUE * link){
	link->status = 1;
	link->ch[0] = link->ch[1] = 0;
	link->num = 0;
}

//�����ͷԪ�ز�ɾ��
char PopQueue(LINKQUEUE * link){
	char ch;
	ch = link->ch[0];
	link->ch[0] = link->ch[1];
	link->ch[1] = 0;
	link->num -=1;
	return ch;
}

//����Ԫ��
int EnQueue(LINKQUEUE * link, char * ch){
	if (link->num == 0){
		link->ch[0] = *ch;
		link->num +=1;
		return 1;
	}
	else if (link->num == 1){
		link->ch[1] = *ch;
		link->num +=1;
		return 1;
	}
	else 
		return 0;
}


//�Ա�ִ����������������ƥ�����Ŀ��NULL
command *findCommand(const command cmds[], int n, int cmd){
        int i = 0;
        command *p = (command *)cmds;

        for (i=0;i<n;i++){
                if (cmds[i].cmd == cmd || cmds[i].cmd == cmd + 32)
                        return p + i;
        }   

        fprintf(stderr, "Unknown command '%c'\n",cmd);
        return 0;
}

void my_driver(const command cmds[], int n, char ch){
	command *pcmd = findCommand(cmds, n, ch);
	if (pcmd){
		pcmd->func(pcmd->cmd);	
	}
} 

void to_dir(char ch){
	printf("%c", ch);
	puts(""); 
}
