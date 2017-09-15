#include "bits/stdc++.h"
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	char arr[26];
	for(int i=0;i<26;i++)
		arr[i]='a'+i;
	char x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		for(int c=0;c<26;c++)
		{
			if(arr[c]==x)
			{
				arr[c]=y;
			}
			else if(arr[c]==y)
			{
				arr[c]=x;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[s[i]-'a'];
	}
	return 0;
}