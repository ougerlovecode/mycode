#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
struct student
{
	int data;//学号 
	char name[20];
	int note;
	student *next;
  } ;
int main()  
{  
	int n1;//表一 
	scanf("%d",&n1);
	
	struct student *q,*p,*head;
	head = (student *)malloc( sizeof(student) );
	head->next=NULL;
	p=head;
	
	for(int i=1;i<=n1;i++)
	{
		q = (student *)malloc( sizeof(student) );
		scanf("%d %s",&q->data,&q->name);
		
		q->next=p->next;
		p->next=q;
		
		p=q;
	}//表一 
	
	int n2;//表二 
	scanf("%d",&n2);
	if(n2==0)
	{
		printf("the LIST2 is NULL.\n");
		return 0;
	}
	
	struct student *q2,*p2,*head2;
	head2 = (student *)malloc( sizeof(student) );
	head2->next=NULL;
	p2=head2;
	
	for(int i=1;i<=n2;i++)
	{
		q2 = (student *)malloc( sizeof(student) );
		scanf("%d %s",&q2->data,&q2->name);
		
		q2->next=p2->next;
		p2->next=q2;
		
		p2=q2;
	}//表二 
	//printf("%s%s",head->next->name,head2->next->name);
	int tot=0;
	for(q2=head2->next;q2!=NULL;q2=q2->next)
	{
		for(q=head->next;q!=NULL;q=q->next)
		{
			if((q->data==q2->data)&&(strcmp(q->name,q2->name)==0))
			{
				tot++;
				q2->note=1;
				break;
			}
		}
	}
	
	if(tot==n2)
	{
		printf("the records of LIST2 are all in the LIST1.\n");
		return 0;
	}
	
	else
	{
		for(q2=head2->next;q2!=NULL;q2=q2->next)
		{
			if(q2->note!=1)
			{
				printf("%d %s is not in LIST1.\n",q2->data,q2->name);
			}
		}
	}
}  

