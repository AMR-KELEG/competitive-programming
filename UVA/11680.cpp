//AC
#include "bits/stdc++.h"
#define state std::vector<pair<int,long double>>
using namespace std;
int n;
vector<std::vector<long double>> prob;
std::vector<pair<int,int>> matches;

state mergeWin(state & s1,state & s2)
{
	map<int,long double> winners;
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			int player1 = s1[i].first;
			int player2 = s2[j].first;
			long double prob1 = s1[i].second;
			long double prob2 = s2[j].second;
			winners[player1]+= (prob1*prob2)*prob[player1][player2];
			winners[player2]+= (prob1*prob2)*prob[player2][player1];
		}
	}
	state ans;
	for(auto i:winners)
	{
		ans.push_back({i.first,i.second});
	}
	return ans;
}

state findWinner(int match)
{
	state p1,p2;
	if(match<=n) // match with player match
	{
		int player1 = match;
		p1 = {{player1,1}};
		for(int m=0;m<matches.size();m++)
		{
			if(matches[m].first== player1 ||matches[m].second== player1)
			{
				//Found the match 
				int player2 = matches[m].first + matches[m].second - player1;
				if(player2<=n)
				{
					// vector of 2 only
					p2={{player2,1}};
				}
				else
				{
					p2=findWinner(player2);
				}
			}
		}
	}
	else
	{
		// Go to index (match - n+1)
		// solve for first and second
		int player1 = matches[match-(n+1)].first;
		int player2 = matches[match-(n+1)].second;
		if(player1 <=n)
		{
			p1={{player1,1}};
		}
		else
		{
			p1= findWinner(player1);
		}
		if(player2<=n)
		{
			p2={{player2,1}};
		}
		else
		{
			p2=findWinner(player2);
		}
	}
	return mergeWin(p1,p2);
}

long double solve()
{
	int lastMatch;
	for(int m=0;m<matches.size();m++)
	{
		if(matches[m].first==1 || matches[m].second==1)
		{
			lastMatch=m+(n+1);
			break;
		}
	}
	bool notLast=1;
	while(notLast)
	{
		notLast=false;
		for(int m=0;m<matches.size();m++)
		{
			if(matches[m].first==lastMatch || matches[m].second==lastMatch)
			{
				lastMatch=m+(n+1);
				notLast=1;
				break;
			}
		}	
	}
	state s= findWinner(lastMatch);
	for(int i=0;i<s.size();i++)
	{
		if(s[i].first==1)
			return s[i].second;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	while(n)
	{
		prob = std::vector<std::vector<long double>> (n+1,std::vector<long double> (n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin>>prob[i][j];
		}
		matches = std::vector<pair<int,int>> (n-1);
		for(int m=0;m<n-1;m++)
		{
			cin>>matches[m].first>>matches[m].second;
		}
		cout<<fixed<<setprecision(6)<<solve()<<endl;
		cin>>n;
	}
	return 0;
}