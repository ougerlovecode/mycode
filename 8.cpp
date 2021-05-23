#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
long long T=0,num_;
char c,qc=0;
int Precede(char op1,char op2)
{
	if(op2=='_')
		return '_'; 
	if(qc==')'&&op2=='(')
		return 10000000;
	if(op2=='\n'&&op1=='(')
		return 10000000;
	if(op2=='\n'&&op1=='#')
		return '=';
	if(op2=='\n')
		return '>';
	if(op1=='#'&&op2==')')
		return 10000000;
	else if(op1=='#')
		return '<';
	if(op1==')'&&op2=='(')
		return 10000000;
	else if(op1==')')
		return '>';
	if(op1=='%'&&(op2=='('||op2=='^'))
		return '<';
	else if(op1=='%')
		return '>';
	if(op1=='('&&op2==')')
		return '=';
	else if(op1=='(')
		return '<';
	if(op1=='^'&&op2=='^')
		return '<';
	else if(op1=='^'&&op2=='(')
		return '<';
	else if(op1=='^')
		return '>';
	
	if(op2=='(')
		return '<';
	if(op2==')')
		return '>';
	
	if(op1=='+'||op1=='-')
		op1=1;
	else if(op1=='*'||op1=='/')
		op1=2;
	else if(op1=='%'||op1=='^')
		op1=3; 
	
	if(op2=='+'||op2=='-')
		op2=1;
	else if(op2=='*'||op2=='/')
		op2=2;
	else if(op2=='%'||op2=='^')
		op2=3; 
		
	if(op1>=op2)
		return '>';
	else if(op1<op2)
		return '<';
}
long long Operate(long long a,char theta,long long b)
{
	switch(theta){
		case'+':
			return a+b;
		case'-':
			return a-b;
		case'*':
			return a*b;
		case'/':
			if(b==0)
				return 1000000;//
			return a/b;
		case'%':
			if(b<0)
				return 10000000;
			return a%b;
		case'^':
			if(b<0)
				return 10000000;
			return pow(a,b);
	}
}
long long wowo()
{
	stack <char> ch;
	stack <long long> num;
	qc='#';
	int flag=0;
	ch.push('#');
	c = getchar();
	if(c=='\n')
		c=getchar();
		while(c!='\n'||ch.top()!='#')//cin
	{
		if(c>='0'&&c<='9')
		{
			num_=c-48;
			if(qc==')')
			{
				while(c!='\n')
				c=getchar();
				return 10000000;
			}
			if(qc>='0'&&qc<='9')
			{
				long long t=num.top();
				num.pop();
				num_ = t*10 + c-'0';
			}
			num.push(num_);
			qc=c;
			c=getchar();
		}
		else
		{
			
			if((qc<='9'&&qc>='0')&&c=='(')
			{
				while(c!='\n')
				c=getchar();
				return 10000000;
			}
			if((qc>'9'||qc<'0')&&c=='-')
			{
				c='_';
			}
			char theta;long long a,b;
			switch(Precede(ch.top(),c)){
				case 10000000:
					while(c!='\n')
						c=getchar();
					return 10000000;
				case'_':
				case'<':
					ch.push(c);
					qc=c;
					c=getchar();
					break;
				case'=':
					ch.pop();
					qc=c;
					c=getchar();
					break;
				case'>':
					theta = ch.top();ch.pop();
					if(!num.empty())
					{
						b = num.top();num.pop();
					}
					else
					{
						
						return 10000000;
					}
					if(theta=='_')
					{
						b=-b;
						
						num.push(b);continue;
					}
					if(!num.empty())
					{
						a = num.top();num.pop();
					}
					else
					{
						return 10000000;
					}
					long long ta=Operate(a,theta,b);
					if(ta==1000000)
					{
						while(c!='\n')
						c=getchar();
						return 1000000;
					}
					else if(ta==10000000)
					{
						while(c!='\n')
						c=getchar();
						return 10000000;
					}
					num.push(ta);
					break;
			}//switch
		}
	}//while
	return num.top();
}
int main()
{
	long long ans;
	cin>>T;
	getchar();
	for(int i=0;i<T;i++)
	{
		ans=wowo();
		if(ans != 10000000&&ans!=1000000)
			printf("%lld\n",ans);
		else if(ans==1000000)
			printf("Divide 0.\n");
		else if(ans==10000000)
		{
			printf("error.\n");
		}
	}//T
} 
		
