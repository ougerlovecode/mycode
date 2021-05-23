#include <iostream>
#include <cstdlib>
#define N 20
using namespace std;
int part_number[5][5];
char sudoku[N][N],a[N][N];
int dfs(int i1,int j1)
{
    for(int i2 = 0 ; i2 < 4 ; i2++)//all kinds of 
	{
		part_number[i1][j1]=i2;
    	int h_ok=1,l_ok=1;
		for(int i=((i1-1)<<2)+1;i<=(i1<<2)&&h_ok;i++)
		{
			for(int j=1;(j<=(j1<<2)-1)&&h_ok;j++)
			{
				for(int k=j+1;k<=(j1<<2);k++)
				{
					if(sudoku[i][j]==sudoku[i][k])
					{	h_ok=0;
						break;
					}
				}
			}
		}
		for(int j=((j1-1)<<2)+1;j<=(j1<<2)&&l_ok;j++)
		{
			for(int i=1;i<=((i1<<2)-1)&&l_ok;i++)
			{
				for(int k=i+1;k<=(i1<<2)&&l_ok;k++)
				{
					if(sudoku[i][j]==sudoku[k][j])
					{	l_ok=0;
						break;
					}
				}
			}
		}
		int ok= (h_ok&&l_ok);
        if(ok)//no reapeated 
		{
		if(i1==4&&j1==4)//find answer
    		{
    		return true;
			}
		else
		{	int i,j;
    		if(j1==4)
    		{
        		j=1;
        		i=i1+1;
    		}
    		else if(j1<4&&j1>0)
    		{
        		i=i1;
        		j=j1+1;
    		}
            int r=dfs(i,j);//next one
            if(r==true)
            	return true;
        }
        }
        for(int i0=((i1-1)<<2),i=1;i+i0<=(i1<<2);i++)
    	{
        	for(int j0=((j1-1)<<2),j=1;j0+j<=(j1<<2);j++)
            	a[i0+5-j][j0+i]=sudoku[i0+i][j0+j];
    	}
		for(int i=(i1<<2)-3;i<=(i1<<2);i++)
    	{
        	for(int j=(j1<<2)-3;j<=(j1<<2);j++)
            	sudoku[i][j] = a[i][j];
    	}//表中区域(i1，j1)的位置逆时针旋转i次
    }
    
		/*for(int i0=((i1-1)<<2),i=1;i+i0<=(i1<<2);i++)//shit!,it had turned 4!no need more trun,shit!shit!shit!!!!!!
    	{
        	for(int j0=((j1-1)<<2),j=1;j0+j<=(j1<<2);j++)
            	a[i0+5-j][j0+i]=sudoku[i0+i][j0+j];
    	}
		for(int i=(i1<<2)-3;i<=(i1<<2);i++)
    	{
        	for(int j=(j1<<2)-3;j<=(j1<<2);j++)
            	sudoku[i][j] = a[i][j];
    	}表中区域(编号1，编号2)的位置顺时针旋转3次,即再逆时针转一次 (X)*/
	part_number[i1][j1]=0;
	return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i1=0;i1<T;i1++)
    {
        /*don't forget initialize */
        for(int i=1;i<=16;i++)
        {
            for(int j=1;j<=16;j++)
                sudoku[i][j]=getchar();
            getchar();
        }
        int r=dfs(1,1);
        int ans=0,ans1=0;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
                {
                	ans+=part_number[i][j];
                    ans1+=((part_number[i][j]+2)&3);
                }
        }
        /*following is cout*/
        if(ans<=ans1)
        {
            printf("%d\n",ans);
            for(int i=1;i<=4;i++)
            {
                for(int j=1;j<=4;j++)
                {
                    if(part_number[i][j]>0)
                    {
                        for(int i1=0;i1<part_number[i][j];i1++)
                            printf("%d %d\n",i,j);
                    }
                }
            }
        }
        else if(ans1<ans)
        {
            printf("%d\n",ans1);
            for(int i=1;i<=4;i++)
            {
                for(int j=1;j<=4;j++)
                {
                    part_number[i][j]=((part_number[i][j]+2)&3);
                    if(part_number[i][j]>0)
                    {
                        for(int i1=0;i1<part_number[i][j];i1++)
                            printf("%d %d\n",i,j);
                    }
                }
            }
        }
    }
}

