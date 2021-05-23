/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE * );  
void change( int, int, NODE * );  
  
void output( NODE * head )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m;  
    NODE * head;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 
void change( int a, int b, NODE *head)
{
	int i=0;
	NODE *q,*p;
	p=head;
	while(a!=0&&i++<50)
	{
		q=(NODE*)malloc(sizeof(NODE));
		
		
		a*=10;
		
		q->data=a/b;
		p->next=q;
		q->next=NULL;
		p=q;
		
		a=a-(a/b)*b;
		
	}
}
