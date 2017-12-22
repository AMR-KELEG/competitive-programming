#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string str;
	cin>>str;
	std::vector<int> comp(26);
	for (auto c:str)
	{
		comp[c-'a']++;
	}
	priority_queue<pair<int,char> >q;
	for (int i=0;i<26;i++)
	{
		q.push({comp[i], 'a'+i});
	}

	std::vector<int> primes;
	std::vector<bool> is_prime(str.size()+1,1);
	for (int i=2;i<=str.size();i++)
	{
		if (!is_prime[i])
			continue;
		primes.push_back(i);
		for (int j=2;j*i<=str.size();j++)
		{
			is_prime[j*i] = 0;
		}
	}

	string ans = string(str.size(),'0');
	int no_of_ones =1;
	for (int i=2;i<=str.size();i++)
	{
		if (is_prime[i] && 2*i>str.size())
		{
			no_of_ones++;
		}
	}

	int largest_comp = str.size() - no_of_ones;
	if (largest_comp > q.top().first)
	{
		printf("NO\n");
		return 0;
	}
	char rep_char = q.top().second;
	int rep_count = q.top().first;
	q.pop();
	for (int i=0;i<ans.size();i++)
	{
		// a single value
		if ((i==0 || (is_prime[i+1] && (2*(i+1)>ans.size()))))
		{
			continue;
		}
		ans[i] = rep_char;
		rep_count--;
	}
	if (rep_count)
	{
		q.push({rep_count, rep_char});
	}

	for (int i=0;i<ans.size();i++)
	{
		if (ans[i]!='0')
			continue;
		char cur_c = q.top().second;
		int cur_co = q.top().first;
		ans[i] = cur_c;
		cur_co--;
		q.pop();
		if (cur_co)
		{
			q.push({cur_co, cur_c});
		}
	}
	printf("YES\n%s", ans.c_str());

}