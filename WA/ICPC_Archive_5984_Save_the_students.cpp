#include "bits/stdc++.h"
using namespace std;
bool board[205][205]={};
bool line_is_vertical(int &x1,int &x2)
{
	if(x1==x2)
	{
		return true;
	}
	return false;
}
bool line_is_horizontal(int &y1,int &y2)
{
	if(y1==y2)
	{
		return true;
	}
	return false;
}
bool point_is_inside(float &x1,float &x2,float &x3,float &y1,float &y2,float &y3,float &px,float &py)
{
	float alpha = ((y2 - y3)*(px - x3) + (x3 - x2)*(py - y3)) /
        ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
	float beta = ((y3 - y1)*(px - x3) + (x1 - x3)*(py - y3)) /
       ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
	float gamma = 1.0f - alpha - beta;
	if(alpha>=0 && beta>=0 && gamma>=0)
	{
		return true;
	}
	return false;
}


float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed 
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */  
   float A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */  
   float A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */   
   float A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   //may be the reason
   return (A -(A1 + A2 + A3)<= 0.00000001 );
}





int main()
{	
	int T,number_of_shapes,saved;
	char shape;
	int x,y,r,l;
	int x1,y1,x2,y2,x3,y3;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		memset(board,0,sizeof(board));
		cin>>number_of_shapes;
		for(int j=0;j<number_of_shapes;j++)
		{
			cin>>shape;
			if(shape=='C')
			{
				cin>>x>>y>>r;
				for(int c_y=y-(r-1);c_y<=y+(r-1);c_y++)
				{
					for(int c_x=x-(r-1);c_x<=x+(r-1);c_x++)
					{
						board[c_x+100][c_y+100]=1;
					}	
				}
				board[x+r+100][y+100]=1;
				board[x+100][y+r+100]=1;
				board[x-r+100][y+100]=1;
				board[x+100][y-r+100]=1;
			}


			else if(shape=='T')
			{
				cin>>x1>>y1>>x2>>y2>>x3>>y3;
				board[x1+100][y1+100]=1;
				board[x2+100][y2+100]=1;
				board[x3+100][y3+100]=1;

				int min_x=min(x1,min(x2,x3)),max_x=max(x1,max(x2,x3)),min_y=min(y1,min(y2,y3)),max_y=max(y1,max(y2,y3));
				for(int c_x=min_x;c_x<=max_x;c_x++)
				{
					for(int c_y=min_y;c_y<=max_y;c_y++)
					{
						if(isInside(x1,y1,x2,y2,x3,y3,c_x,c_y))
						{
							//cout<<c_x<<" "<<c_y<<endl;
							board[c_x+100][c_y+100]=1;
						}

					}	
				}
			}


			else if(shape=='S')
			{
				cin>>x>>y>>l;
				for(int c_y=y;c_y<=y+l;c_y++)
				{
					for(int c_x=x;c_x<=x+l;c_x++)
					{
						board[c_x+100][c_y+100]=1;
					}	
				}
			}	



		}

		saved=0;
		for(int row=0;row<205;row++)
		{
			for(int col=0;col<205;col++)
			{
				if(board[row][col]==true)
				{
					saved++;
				}
			}
		}
		cout<<saved<<endl;
		
	}

	
	return 0;
}