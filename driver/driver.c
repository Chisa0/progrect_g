#include "d_driver.h"

int main(){
	static Command cmds[] = { 
                { 'w', doPenDir },
                { 'a', doPenDir },
                { 'd', doPenDir },
                { 's', doPenDir }
        };  
	
	turtle(cmds);
	
	return 0;
}
