#include "bits/stdc++.h"
using namespace std;
class chess_node
{
public:
	int r;
	int c;
	int counter;
	chess_node()
	{

	}

	chess_node(int row,int col,int ccounter)
	{
		r=row;
		c=col;
		counter=ccounter;
	}
};
int main()
{
	int T;
	int c;
	char r;
	bool board [8][8]={};//row col
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>r>>c;//start point
		queue<chess_node>node;//row col counter
		memset(board,0,sizeof(board));
		node.push(chess_node(r-'a',c-1,0));
		cin>>r>>c;// end point
		while(!node.empty())
		{
			 chess_node current_node=node.front();
			 node.pop();
			 int current_row=current_node.r,current_col=current_node.c;
			 if(current_row==r-'a' && current_col==c-1)
			 {
			 	cout<<current_node.counter<<endl;
			 	break;
			 }
			 else
			 {
			 	board[current_row][current_col]=1;
			 	if(current_col-1 >=0 && current_row-2 >=0)
			 	{
			 		if(board[current_row-2][current_col-1]==0)
			 		{
			 			board[current_row-2][current_col-1]=1;	
			 			node.push(chess_node(current_row-2,current_col-1,1+current_node.counter));
			 		}
			 	}
			 	

			 	if(current_col-2 >=0 && current_row-1 >=0)
			 	{
			 		if(board[current_row-1][current_col-2]==0)
			 		{
			 			board[current_row-1][current_col-2]=1;
			 			//node.push(pair(pair(current_row-1,current_col-2),1+current_node.second));
			 			node.push(chess_node(current_row-1,current_col-2,1+current_node.counter));
			 		}
			 	}

			 	if(current_row+1 <=7 &&current_col-2 >=0 )
			 	{
			 		if(board[current_row+1][current_col-2]==0)
			 		{
			 			board[current_row+1][current_col-2]=1;
			 			//node.push(pair(pair(current_row+1,current_col-2),1+current_node.second));
			 			node.push(chess_node(current_row+1,current_col-2,1+current_node.counter));

			 		}
			 	}

			 	if(current_row+2 <=7 &&current_col-1 >=0 )
			 	{
			 		if(board[current_row+2][current_col-1]==0)
			 		{
			 			board[current_row+2][current_col-1]=1;
			 			//node.push(pair(pair(current_row+2,current_col-1),1+current_node.second));
			 			node.push(chess_node(current_row+2,current_col-1,1+current_node.counter));
			 		}
			 	}


			 	if(current_row+2 <=7 &&current_col+1 <=7 )
			 	{
			 		if(board[current_row+2][current_col+1]==0)
			 		{
			 			board[current_row+2][current_col+1]=1;
			 			//node.push(pair(pair(current_row+2,current_col+1),1+current_node.second));
			 			node.push(chess_node(current_row+2,current_col+1,1+current_node.counter));
			 		}
			 	}




			 	if(current_row+1 <=7 &&current_col+2 <=7 )
			 	{
			 		if(board[current_row+1][current_col+2]==0)
			 		{
			 			board[current_row+1][current_col+2]=1;
			 			//node.push(pair(pair(current_row+1,current_col+2),1+current_node.second));
			 			node.push(chess_node(current_row+1,current_col+2,1+current_node.counter));
			 		}
			 	}



			 	if(current_row-1 >=0 &&current_col+2 <=7 )
			 	{
			 		if(board[current_row-1][current_col+2]==0)
			 		{
			 			board[current_row-1][current_col+2]=1;
			 			//node.push(pair(pair(current_row-1,current_col+2),1+current_node.second));
			 			node.push(chess_node(current_row-1,current_col+2,1+current_node.counter));
			 		}
			 	}



			 	if(current_row-2 >=0 &&current_col+1 <=7 )
			 	{
			 		if(board[current_row-2][current_col+1]==0)
			 		{
			 			board[current_row-2][current_col+1]=1;
			 			//node.push(pair(pair(current_row-2,current_col+1),1+current_node.second));
			 			node.push(chess_node(current_row-2,current_col+1,1+current_node.counter));
			 		}
			 	}


			 }
		}

	}
	return 0;
}