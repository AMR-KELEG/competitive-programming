//AC
#include "bits/stdc++.h"
using namespace std;
queue<int>indx;
void add(int st, int en)
{
	if(st>en)
		return;
	if(st==en)
	{
		indx.push(st);
		return;
	}
	int mid = st+ ((en-st)/2);
	indx.push(mid);
	add(st,mid-1);
	add(mid+1,en);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	getline(cin, s);
	// cout<<s;
	add(0,s.size()-1);
	string ans = s;
	for(int i=0;i<s.size();i++)
	{
		// cout<<indx[i]<<endl;	
		int in = indx.front();
		indx.pop();
		ans[in]=s[i];
	}
	cout<<ans;
}