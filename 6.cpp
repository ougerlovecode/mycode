#define _CRT_SECURE_NO_WARNINGS 1  
#include <iostream>  
#include <cstdlib>  
#include <algorithm>  
#include <cstring>   
#include <math.h>  
#define N 5  
using namespace std;  
struct node  
{  
   int orderid, stockid, quantity;float price;  
    char b_s;  
  struct node* next;  
};  
node* q, * p, * q_s, * q_b, * p_s, * p_b, * head_s, * head_b, * rq, * rp;  
int order = 1;  
void insert_s(node* q)//ÉýÐò£¬Í·×îÐ¡  
{  
    rp = head_s;  
   for (p = head_s->next;p != NULL && p->price <= q->price;p = p->next)  
        rp = p;  
  
   rp->next = q;  
   q->next = p;  
  
  
}  
void insert_b(node* q)//½µÐò  
{  
   rp = head_b;  
   for (p = head_b->next;p != NULL && p->price >= q->price;p = p->next)  
        rp = p;  
  
   rp->next = q;  
   q->next = p;  
  
}  
int deal_s(node* q)  
{  
   int _tot = q->quantity, t0 = q->quantity;  
    node* r = NULL, * rp = NULL, * p = NULL, * head = (node*)malloc(sizeof(node));  
 head->next = NULL;  
  node* qr = head;  
   if(head_b!=NULL)  
   for (p = head_b->next;p != NULL;p = p->next)  
 {  
      if ((p->stockid == q->stockid) && (p->price >= q->price))//  
     {  
          if (_tot >= p->quantity)  
         {  
              r = (node*)malloc(sizeof(node));  
               *r = *p;  
               r->next = qr->next;  
              qr->next = r;  
               qr = r;  
                _tot -= p->quantity;  
            }  
          else  
           {  
              r = (node*)malloc(sizeof(node));  
               *r = *p;  
               r->quantity = _tot;  
             r->next = qr->next;  
              qr->next = r;  
               qr = r;  
                _tot = 0;  
          }  
          if (_tot <= 0)  
              break;  
     }  
        
   }  
  int ok = 1;  
    if (_tot != 0)  
 {  
      ok = 0;  
        q->quantity = _tot;  
 }  
  for (p = head->next;p != NULL;p = p->next)  
   {  
      printf("deal--price:%6.1f  ", (p->price + q->price) / 2);  
      printf("quantity:%4d  ", p->quantity);  
      printf("sellorder:%04d  ", q->orderid);  
      printf("buyorder:%04d\n", p->orderid);  
    }  
  rp = head_b;  
   if(head_b!=NULL)  
   for (p = head_b->next, _tot = t0;p != NULL && _tot > 0;)///////////////////////////////   
 {  
      if ((p->stockid == q->stockid) && (p->price >= q->price))//  
     {  
          if (_tot >= p->quantity)  
         {  
              _tot -= p->quantity;  
                rp->next = p->next;  
              free(p);  
               p = rp->next;  
           }  
          else  
           {  
              p->quantity -= _tot;  
                break;  
         }  
                
       }  
      else  
       {  
          p = p->next;  
        }  
  }  
  return ok;  
}  
int deal_b(node* q)  
{  
 int _tot = q->quantity, t0 = q->quantity; 
    node* r = NULL, * rp = NULL, * p = NULL, * head = (node*)malloc(sizeof(node));  
 head->next = NULL;  
  node* qr = head;  
   if(head_s!=NULL)  
   for (p = head_s->next;p != NULL;p = p->next)  
 {  
      if ((p->stockid == q->stockid) && (p->price <= q->price))  
       {  
          if (_tot >= p->quantity)  
         {  
              r = (node*)malloc(sizeof(node));  
               *r = *p;  
               r->next = qr->next;  
              qr->next = r;  
               qr = r;  
                _tot -= p->quantity;  
            }  
          else  
           {  
              r = (node*)malloc(sizeof(node));  
               *r = *p;  
               r->quantity = _tot;  
             r->next = qr->next;  
              qr->next = r;  
               qr = r;  
                _tot = 0;  
          }  
          if (_tot <= 0)  
              break;  
     }  
        
   }  
  int ok = 1;  
    if (_tot != 0)  
 {  
      ok = 0;  
        q->quantity = _tot;  
 }  
  for (p = head->next;p != NULL;p = p->next)  
   {  
      printf("deal--price:%6.1f  ", (p->price + q->price) / 2);  
      printf("quantity:%4d  ", p->quantity);  
      printf("buyorder:%04d  ", q->orderid);  
      printf("sellorder:%04d\n", p->orderid);  
   }  
  rp = head_s;  
   if(head_s!=NULL)  
   for (p = head_s->next, _tot = t0;p != NULL && _tot > 0;)/////////////////////////////////   
   {  
      if ((p->stockid == q->stockid) && (p->price <= q->price))//  
     {  
          if (_tot >= p->quantity)  
         {  
              _tot -= p->quantity;  
                rp->next = p->next;  
              free(p);  
               p = rp->next;  
           }  
          else  
           {  
              p->quantity -= _tot;  
                break;  
         }  
      }  
      else  
       {  
          p = p->next;  
        }  
  }  
  return ok;  
}  
int main()  
{  
  int a = 1;  
 head_s = (node*)malloc(sizeof(node));  
  head_s->next = NULL;  
    p_s = head_s;  
  head_b = (node*)malloc(sizeof(node));  
  head_b->next = NULL;  
    p_b = head_b;  
  while (a != 0)  
 {  
      scanf("%d", &a);  
       switch (a) {  
       case 1:  
            q = (node*)malloc(sizeof(node));  
           q->orderid = order++;  
           printf("orderid: %04d\n", q->orderid);  
          scanf("%d %f %d %c", &q->stockid, &q->price, &q->quantity, &q->b_s);  
           if (q->b_s == 's')  
          {  
              if (deal_s(q))//_tot==0  
                    ;  
              else  
                   insert_s(q);  
           }  
          else//b  
            {  
              if (deal_b(q))  
                 ;  
              else  
                   insert_b(q);  
           }  
          break;  
     case 2:  
            int ta;  
            scanf("%d", &ta); 
          printf("buy orders:\n");  
           for (q = head_b->next;q != NULL;q = q->next)  
         {  
              if (q->stockid == ta)  
                   printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->stockid, q->price, q->quantity, q->b_s);  
           }  
          printf("sell orders:\n");  
          for (q = head_s->next;q != NULL;q = q->next)  
         {  
              if (q->stockid == ta)  
                   printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->stockid, q->price, q->quantity, q->b_s);  
           }  
          break;  
     case 3:  
         int ta_;  
            scanf("%d", &ta_);  
          for (q = head_s->next,rq=head_s;q != NULL && q->orderid != ta_;q = q->next)  
                rq = q;  
            for (p = head_b->next,rp=head_b;p != NULL && p->orderid != ta_;p = p->next)  
                rp = p;  
            if (!q && !p)//q==NULL&&p==NULL  
            {  
              printf("not found\n");  
             break;  
           }  
          else if (q)//q!=NULL  
               rq->next = q->next; 
          else  
           {  
              rp->next = p->next; 
              q = p;  
            }  
          printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q->orderid, q->stockid, q->price, q->quantity, q->b_s);  
         free(q);  
           break;  
     case 0:  
       exit(0); 
            break; 
     }  
  }  
}  
