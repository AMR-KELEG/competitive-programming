// AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> next_av;
std::vector<bool> deleted;
int find_next(int i)
{
	if (!deleted[i])
		return i;
	return next_av[i] = find_next(next_av[i]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string t,s;
	while(getline(cin,t))
	{
		s+=t;
	}		
	int n = 1999;
	int cur_indx = 0;
	int cur_len = s.size();
	deleted = std::vector<bool> (s.size(),0);
	next_av = std::vector<int> (s.size());
	for (int i=0;i<s.size()-1;i++)
		next_av[i] = i+1;
	next_av[s.size()-1] = 0;
	while(cur_len>1)
	{
		int moves = n; // Bug
		while(moves)
		{
			int i = find_next(cur_indx);
			moves --;
			if (moves)
				cur_indx = (i+1)%s.size();
			else
				cur_indx = i;
		}
		deleted[cur_indx] = 1;
		cur_len --;
	}
	cur_indx = find_next(0);
	if (s[cur_indx] == '?')
		cout<<"Yes";
	else if(s[cur_indx]==' ')
		cout<<"No";
	else
		cout<<"No comments";
}
