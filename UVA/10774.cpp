// AC
// 12:26
// 12:38
#include <bits/stdc++.h>
using namespace std;
int no_moves[30001];
int next_move[30001];
int winner[30001];
int solve(int n)
{
    if(no_moves[n]!=-1)
        return no_moves[n];
    if(next_move[n]==n)
        return no_moves[n]=0;
    return no_moves[n]=1+solve(next_move[n]);
}

int find_winner(int n)
{
    if(winner[n]!=-1)
        return winner[n];
    if(next_move[n]==n)
        return winner[n]=n;
    return winner[n]=find_winner(next_move[n]);
}

int main()
{
    int q;
    cin>>q;
    int val = 1;
    memset(no_moves,-1,sizeof no_moves);
    memset(winner,-1,sizeof winner);
    for(int i=1;i<=30000;i++)
    {
        if(val==i)
        {
            next_move[i]=i;
            val =1;
        }
        else
        {
            next_move[i]=val;
            val+=2;
        }
    }
    for(int t=1;t<=q;t++)
    {
        int n;
        cin>>n;
        int steps = solve(n);
        int win = find_winner(n);
        printf("Case %d: %d %d\n",t,steps,win);
    }
}
