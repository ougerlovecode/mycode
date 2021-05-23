#include <iostream>  
#include <cstdlib>  
using namespace std;
struct node{
    long long s,t;
    node *next;
};
void print(node *head)
{
	node *p = head;
	for(p=head->next;p;p=p->next)
	{
		cout<<p->s<<" "<<p->t<<endl;
	}
}
int main()
{
    int n;
    cin >> n;
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;head->s = 0;head->t = 0;
    node *q,*p_q = head;
    for(int i=0;i<n;i++)
    {
        q = (node*)malloc(sizeof(node));
        q->next = NULL;
        cin>>q->s>>q->t;
        node *p = NULL;
        p_q=head;
        for(p = head->next;p!=NULL&& q->t > p->t ; p=p->next)
        {
        	p_q = p; 
		}
		q->next = p;
        p_q->next = q;
    }
   // print(head);
    long long t0=0;
    int ans=0;
    int tot=0;
    while(tot<n)
    {
        t0 =0 ;
        for( q = head->next,p_q=head;q;q=q->next)
        {
            if(q->s >= t0)
            {
                t0 = q->t;
                p_q->next = q->next;
                free(q);
                tot++;
                q = p_q;
            }
            p_q = q;
        }
        ans++;
    }
    cout<<ans-1<<endl;
   return 0;
}
