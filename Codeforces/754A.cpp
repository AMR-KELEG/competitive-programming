//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	std::vector<pair<int,int>> ans;
	int l=1;
	int i,no;
	for(i=1;i<=n;i++)
	{
		cin>>no;
		if(no!=0)
		{
			ans.push_back({l,i});
			l=i+1;
		}
	} 	
	if(l==n+1 || ans.size()>0)
	{
		if(l!=n+1)
			ans[ans.size()-1].second=n;
		cout<<"YES\n"<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	else
	{
		cout<<"NO";
	}
}