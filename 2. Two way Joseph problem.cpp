#include<cstdlib>
#include<iostream>
#include<algorithm> 
struct DuLNode{
	int data;
	struct DuLNode *perior;
	struct DuLNode *next;
};
int main()
{
	int n,k,m;
	scanf("%d,%d,%d",&n,&k,&m);
	if(!(n&&k&&m))
	{
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	if(k>n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}
	struct DuLNode head;
	struct DuLNode *p,*l,*r,*q;
	p=(&head);
	head.next=(&head);
	head.perior=(&head);
	
	for(int i=1;i<=n;i++)
	{
		q=(DuLNode*)malloc(sizeof(DuLNode));
		
		q->data=i;
		q->next=p->next;
		p->next=q;
		q->perior=p;
		head.perior=q;
		
		p=q;//移到当前位置 
	}
	
	
	p=(&head);
	for(int i=0;i<k;i++)//找到第一个k
	{
		p=p->next;
	}
	 
	l=p;
	r=p;
	
	while((head.next)!=(&head)){
	for(int i=0;i<m-1;i++)//往两边走，找m-1次 
	{
		l=l->perior;
		r=r->next;
		
		if(l==(&head))
		{
			l=l->perior;
		}
		if(r==(&head))
		{
			r=r->next;
		}
	}
		if(l==r)
	{
		printf("%d,",r->data);
		p=l->perior;
		p->next=l->next;
		p->next->perior=p;
		
		free(l);
		
		l=p;
		r=p->next;
		if(l==(&head))
		{
			l=l->perior;
		}
		if(r==(&head))
		{
			r=r->next;
		}
	}
	else
	{
		printf("%d-%d,",r->data,l->data);
		p=l->perior;
		p->next=l->next;
		p->next->perior=p;
		
		free(l);
		
		l=p;
		
		p=r->perior;
		p->next=r->next;
		p->next->perior=p;
		
		free(r);
		
		r=p->next;
		if(l==(&head))
		{
			l=l->perior;
		}
		if(r==(&head))
		{
			r=r->next;
		}
	}
	}/**/
	printf("\n");
}
