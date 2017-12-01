// AC
#include "bits/stdc++.h"
using namespace std;

string s;
std::vector<int> count_a,count_b;
void prepare()
{
	count_a = std::vector<int> (s.size()+1,0);
	count_b = std::vector<int> (s.size()+1,0);
	for (int i=0;i<s.size();i++)
	{
		count_a[i+1] = count_a[i];
		count_b[i+1] = count_b[i];
		if (s[i]=='a')
			count_a[i+1]++;
		else
			count_b[i+1]++;
	}
}

int find_no_of_deleted(int st,int en, bool del_a)
{
	if (st>en)
		return 0;	
	if (del_a)
		return count_a[en+1]-count_a[st];
	return count_b[en+1]-count_b[st];
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>s;
	int ans = 0;
	int n = s.size();
	prepare();
	for (int i=0;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int cur_ans = s.size();
			//from 0 -> i-1
			cur_ans -= find_no_of_deleted(0,i-1,0);
			//from i -> j-1
			cur_ans -= find_no_of_deleted(i,j-1,1);
			//from j -> n-1
			cur_ans -= find_no_of_deleted(j,n-1,0);
			ans = max(ans,cur_ans);
		}
	}
	cout<<ans;
}