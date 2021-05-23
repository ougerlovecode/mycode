#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100003
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char c,c1=0,c2=0;
	int flag=1;
	while((c=getchar())!=EOF){
		if(flag==1){
			if(c<='z'&&c>='a'){
				c-=32;
			}
			flag=0;
			putchar(c);
			continue;
		}
		if((c1=='.')||(c1=='?')||(c1=='!')){
			if(c<='z'&&c>='a'){
				c-=32;
			}
		}
		else{
			if(c<='Z'&&c>='A'){
				c+=32;
			}
		}
		putchar(c); 
		c1=c2;
		c2=c;
	}
	return 0;
}
