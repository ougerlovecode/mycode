#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack> 
#define N 5
using namespace std;
struct node
{
	int h,r;
	struct node *perior;
	struct node *next;
	int time,l,R;
};
int r,l,_h;
long long t;
stack<node*> sta,sta_l;
node *q,*p,*de,*deepest;
node *head;
//����˫�������� 

int main()
{
	int n,deep=1000001,hmax=0;
	scanf("%d",&n);
	
	head = (node *)malloc( sizeof(node) );
	head->next = NULL;
	head->r = 0;
	p=head;
	
	for(int i=0;i<n;i++)//����
	{
		int w;
		q = (node *)malloc( sizeof(node) );
		q->time = 0;
		scanf("%d %d",&w,&q->h);
		q->r=(p->r)+w;
		hmax = max(hmax,q->h);
		if( deep > q->h )
		{
			deep=q->h;
			de=q;
		}
		
		q->next=p->next;
		p->next=q;
		q->perior=p;
		
		p=q;//�Ƶ���ǰλ��
	}//���� 
	q = (node *)malloc( sizeof(node) );
	q->next=p->next;
	p->next=q;
	q->perior=p;
	q->h = hmax+1;
	head->h = hmax+1;
	head->next->l = 0;
	deepest=de;
	de->l = de->perior->r;
	
	for(p=head->next;p->next!=NULL;p=p->next) 
	{
		if(p->h >= p->next->h)//�����ѹջ
		{
			if(p->h>p->next->h)
				p->next->l = p->r;
			else
				p->next->l = p->l;
			sta.push(p);
		} 
		else
		{
			p->R = p->r;
			if(!sta.empty()&&sta.top()->h <= p->next->h)
			{
				q = sta.top();
				while(!sta.empty()&&sta.top()->h < p->next->h)//ջ��Ϊ�θ� 
				{
				q = sta.top();
				q->R = p->r;
				sta.pop();
				}
				if(q->h == p->next->h)
				p->next->l = q->l;
				else
				{
					p->next->l = p->l;
				}
			}
			else
			{
				p->next->l = p->l;
			}
		}
		//ջΪ�գ��ұ߸ߡ�
	}
	//��de��������//
	deepest=de;
	for(q=de->perior,p=de->next;p!=NULL&&q!=NULL;) 
	{
		if(deepest->h >= p->h)//�����ѹջ
		{
			sta.push(deepest);
			deepest=p;
			p = p->next;
			continue;
		} 	
		while((!sta.empty()&&p!=NULL)&&deepest->h <= p->h)//ջ��Ϊ�գ�
		{	
			r = deepest->R;l = deepest->l; 
			if(sta.top()->h <= p->h )//ջ��Ϊ�θߣ���ûջ���� 
			{
				_h = sta.top()->h - deepest->h;
				deepest->time = t + r-l;
				t += _h*(r-l);
				deepest = sta.top();
				sta.pop();
			 }
			else//��û�ұ� 
			{
				_h = p->h - deepest->h;
				deepest->time = t + r-l;
				t += _h*(r-l);
				deepest = p;
				if(p->next) 
				p = p->next;
			}
		}
		if(q->h <= deepest->h)//�����ѹջ
		{
			sta_l.push(deepest);
			deepest = q;
			q = q->perior;
			continue;
		}
		while((!sta_l.empty()&&q!=NULL)&&q->h >= deepest->h)//ջ��Ϊ�գ�
		{
			r = deepest->R;l = deepest->l;
			if(sta_l.top()->h < q->h )//ջ��Ϊ�θ�
			{
				_h = sta_l.top()->h - deepest->h;
				deepest->time = t + r-l;
				t += _h*(r-l);
				deepest = sta_l.top();
				sta_l.pop();
			 }
			else//
			{
				_h = q->h - deepest->h;
				deepest->time = t + r-l;
				t += _h*(r-l);
				deepest = q;
				if(q->perior)
				q = q->perior;
			}	
		}
		if((q->h > deepest->h )&&(deepest->h < p->h ))//��δ��� 
		{
		r = deepest->R;l = deepest->l;
		if(q->h <= p->h)//��û��� 
		{
			_h = q->h - deepest->h;
			deepest->time = t + (r-l); 
			t += (r-l)*_h;
			deepest = q;
			q = q->perior;
		}
		else if(q->h > p->h)//��û�ұ� 
		{
			_h = p->h - deepest->h;
			deepest->time = t + (r-l);
			t += (r-l)*_h;
			deepest = p;
			p = p->next;
		}
		continue;
		}//��δ��� 	
	}
	if(sta.empty())//ջ��
	{
		if(q==head)//��ߵ�����ջ�� 
	{
		while(p != NULL) 
		{
			r = deepest->R;l = deepest->l;
			_h = p->h - deepest->h;
			deepest->time = t + (r-l); 
			t += (r-l)*_h;
			deepest = p;
			p = p->next;
		}
	}
	else if(p==NULL)//�ұߵ���,ջ�� 
	{
		while(q!=NULL)
		{
			r = deepest->R;l = deepest->l;
			_h = q->h - deepest->h;
			deepest->time = t + (r-l); 
			t += (r-l)*_h;
			deepest = q;
			q = q->perior;
		}
	}
	}
	else
	{
		while(!sta.empty())//ջ��Ϊ�գ�
		{
			r = deepest->R;l = deepest->l;
			_h = sta.top()->h - deepest->h;
			deepest->time = t + r-l;
			t += _h*(r-l);
			deepest = sta.top();
			sta.pop(); 
		} 
		while(!sta_l.empty()&&q!=head)//ջ��Ϊ�գ�
		{	
			r = deepest->R;l = deepest->l;
			_h = sta_l.top()->h - deepest->h;	
			deepest->time = t + r-l;
			t += _h*(r-l);	
			deepest = sta_l.top();
			sta_l.pop(); 
		}
	 } 
	//���������//
	for(p = head->next;p->next!=NULL;p=p->next)
	{
		printf("%lld\n",p->time);
	} 
}	
