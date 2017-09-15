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
	string s;
	int ans=0;
	while(n--)
	{
		cin>>s;
		if(s=="Tetrahedron")
		{
			ans+=4;	
		}
		else if(s=="Cube")
		{
			ans+=6;	
		}
		else if(s=="Octahedron")
		{
			ans+=8;	
		}
		else if(s=="Dodecahedron")
		{
			ans+=12;	
		}
		else
		{
			ans+=20;
		}
	}	
	cout<<ans;
}