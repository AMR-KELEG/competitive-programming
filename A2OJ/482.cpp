//AC
#include "bits/stdc++.h"
using namespace std;

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
		int n;
		cin>>n;
		std::vector<char> v(n);
		for (int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			v[i]= s[0];
		}
		for (int i=0;i<v.size();i++)
		{
			printf("%c", v[i]);
			int co = 1;
			while (i+1<v.size() && v[i]==v[i+1])
			{
				co++;
				i++;
			}
			if (co==1)
				continue;
			else
				printf("%d", co);
		}
		printf("\n");
	}	
}