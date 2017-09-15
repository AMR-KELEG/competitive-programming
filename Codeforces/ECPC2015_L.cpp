#include "bits/stdc++.h"
using namespace std;
vector<char>winner;
int N;
char find_winner(int jar)
{
	if(jar<N)return winner[jar]='p';
	if(winner[jar]!='x')return winner[jar];
	for(int i=jar-N+1;i>=ceil((jar*1.0)/N);i--)
	{
		//if you have 1000 and divide it into 600 400 make sure that 400 isn't a winning position for the other player
		if(find_winner(i)=='p')
			return winner[jar]='n';
	}
	return winner[jar]='p';
}
int main()
{
	freopen("in.txt","r",stdin);
	int T;
	int tem;
	vector<int>jars;
	cin>>T;
	while(T--)
	{
		cin>>N;
		winner.assign(1001,'x');
		jars.clear();
		for(int i=0;i<N;i++)
		{
			cin>>tem;

			if(tem>=N)
				jars.push_back(tem);
		}	
		//set<int>::iterator it=jars.begin();
		char winner_p='p';
		for(int i=0;i<jars.size();i++)
		{
			if(find_winner(jars[i])=='n')
			{
				winner_p='n';
				break;
			}
			//std::advance(it,1);
		}
		/*
		for(int i=0;i<winner.size();i++)
			cout<<winner[i];
		cout<<endl;
		*/
		if(winner_p=='n')cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
}