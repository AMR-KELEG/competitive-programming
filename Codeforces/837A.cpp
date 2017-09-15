//AC
#include <bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r" , stdin);
	#endif
	int n;
	cin>>n;
	int ans = 0;
	int cur = 0;
	string s;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<n;i++)
	{
		if(s[i]==' ')
		{
			ans = max(ans,cur);
			cur=0;
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			cur++;
		}
	}
	ans = max(ans,cur);
	cout<<ans;
	return 0;
}