#include "bits/stdc++.h"
using namespace std;
char board[8][8]={};
bool is_pos_valid(int r,int c,int t)
{
	if(r>7 || c>7)return 0;
	if(r<0 || c<0)return 0;
	if(t>=8)return 1;
	if(r==0 && c==7)return 1;
	if(r-t>=0)
	{
		if(board[r-t][c]=='S')return 0;
	}
	bool f= is_pos_valid(r,c,t+1);
	if(board[r-1-t][c]!='S')
		f=f||is_pos_valid(r-1,c,t+1);
	if(board[r-1-t][c+1]!='S')
		f=f||is_pos_valid(r-1,c+1,t+1);
	if(board[r-t][c+1]!='S')
		f=f||is_pos_valid(r,c+1,t+1);
	if(board[r+1-t][c+1]!='S')
		f=f||is_pos_valid(r+1,c+1,t+1);
	if(board[r+1-t][c]!='S')
		f=f||is_pos_valid(r+1,c,t+1);
	if(board[r+1-t][c-1]!='S')
		f=f||is_pos_valid(r+1,c-1,t+1);
	if(board[r-t][c-1]!='S')
		f=f||is_pos_valid(r,c-1,t+1);
	if(board[r-1-t][c-1]!='S')
		f=f||is_pos_valid(r-1,c-1,t+1);
	return f;
}
int main()
{
	//freopen("in.txt","r",stdin);
	for(int row=0;row<8;row++)
	{
		for(int col=0;col<8;col++)
		{
			cin>>board[row][col];
		}
	}
	if(is_pos_valid(7,0,0))
	{
		cout<<"WIN";
	}
	else
	{
		cout<<"LOSE";
	}
	return 0;
}