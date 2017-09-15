//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	char c1='G',c2='B';
	if(a<b)
	{
		swap(a,b);
		swap(c1,c2);
	}
	int curDrink=0;
	queue<char>q;
	for(int i=0;i<n && a>0;i++)
	{
		q.push(c1);
		a--;
		curDrink++;
		if(!(a>=b && curDrink<k))
		{
			swap(a,b);
			swap(c1,c2);
			curDrink=0;		
		}
	}
	if(q.size()==n)
	{
		while(!q.empty())
		{
			printf("%c", q.front());
			q.pop();
		}
	}
	else
	{
		cout<<"NO";
	}
}