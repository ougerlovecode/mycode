/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  
  
void multiplication( NODE *head1, NODE *head2 , NODE *head3 )
{
	NODE *p,*q,*r,*qr;
	if(head1->next->coef==0||head2->next->coef==0)
	{
		head3->next = ( NODE * ) malloc( sizeof(NODE) );  
		head3->next->coef = 0;
		head3->next->exp = 0;
		head3->next->next=NULL;
		return;
	}
	for(q=head1->next;q!=NULL;q=q->next)
	{
		qr = head3;
		for(r=head3->next;r!=NULL&&r->exp<(q->exp+head2->next->exp);r=r->next)
			qr=r;
		for(p=head2->next;p!=NULL;p=p->next)
		{
			int coef = q->coef*p->coef;
			int exp = q->exp+p->exp;
			for(;r!=NULL&&r->exp<exp;r=r->next)
				qr=r;
			if(r!=NULL&&r->exp==exp)
			{
				r->coef += q->coef*p->coef;
				//r->exp = q->exp+p->exp;
			}
			else
			{
				r = ( NODE * ) malloc( sizeof(NODE) );
				r->coef = q->coef*p->coef;
				r->exp = q->exp+p->exp;
				r->next = qr->next; 
				qr->next = r;
			}
		//	output(head3);
		}
	} 
	//output(head3);//n*n´Î£¬
	 for(r=head3;r->next!=NULL;r=r->next)
	 {
	 	if(r->next->coef == 0)
	 	{
	 		p = r->next;
	 		r->next = p->next;
	 		free(p);
		}
	 }
}
