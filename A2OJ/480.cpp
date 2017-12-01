// AC
#include "bits/stdc++.h"
using namespace std;
class Sub
{	
public:
	int ti;
	int c_id;
	int p_id;
	bool is_AC;
	Sub(int t,int c,int p,bool v)
	{
		ti =t;
		c_id = c;
		p_id = p;
		is_AC = v;
	}

};
bool cmp(const Sub & s1, const Sub & s2)
{
	return s1.ti < s2.ti;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int C,P,S;
		cin>>C>>P>>S;
		std::vector<std::vector<int> > no_of_wrong_sub(C+1, std::vector<int> (P+1,0));
		std::vector<std::vector<bool> > solved(C+1, std::vector<bool> (P+1,0));
		std::vector<int> no_of_solved(C+1,0);
		std::vector<int> penalty(C+1,0);
		// ti contestant problem verdict (0 == wrong)
		std::vector<Sub> submissions;
		while(S--)
		{
			int t,c,p,v;
			cin>>t>>c>>p>>v;
			submissions.push_back(Sub(t,c,p,v));
		}
		sort(submissions.begin(), submissions.end(), cmp);
		for (int i=0;i<submissions.size();i++)
		{
			int t = submissions[i].ti;
			int p_id = submissions[i].p_id;
			int c_id = submissions[i].c_id;
			bool is_AC = submissions[i].is_AC;
			if (solved[c_id][p_id])
				continue;
			if (is_AC)
			{
				solved[c_id][p_id] = 1;
				penalty[c_id] += no_of_wrong_sub[c_id][p_id] * 20 + t;
				no_of_solved[c_id]++;
			}
			else
			{
				no_of_wrong_sub[c_id][p_id]++;
			}
		}
		// - no_of_solved penalty id 
		std::vector<pair<pair<int,int>,int> > scoreboard(C);
		for (int i=1;i<=C;i++)
		{
			scoreboard[i-1].first.first = - no_of_solved[i];
			scoreboard[i-1].first.second = penalty[i];
			scoreboard[i-1].second = i;
		}
		sort(scoreboard.begin(), scoreboard.end());
		// cout<<submissions.size()<<endl;
		// continue;
		for (int i=0;i<scoreboard.size();i++)
		{
			cout<<scoreboard[i].second<<" "
				<<-scoreboard[i].first.first<<" "<<scoreboard[i].first.second<<endl;
		}
	}
}