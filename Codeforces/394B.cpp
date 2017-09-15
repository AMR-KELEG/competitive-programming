//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int p,x;
	cin>>p>>x;
	std::vector<int> s(p);
	int val;
	for(s[0]=1;s[0]<=9;s[0]++)
	{
		val=s[0]*x;
		for(int i=1;i<p;i++)
		{
			s[i]=(val%10);
			val=(val/10)+(x*s[i]);
		}

		// cout<<s[0]<<": ";
		// for(int i=p-1;i>=0;i--)
		// 	cout<<s[i];
		// cout<<" V: "<<val<<" "<<endl;
		if(val==s[0] && s[p-1]!=0)
		{
			//found
			for(int i=p-1;i>=0;i--)
				printf("%d", s[i]);
			return 0;
		}
	}	
	cout<<"Impossible";
}