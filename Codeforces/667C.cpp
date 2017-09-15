#include "bits/stdc++.h"
using namespace std;
long long int com[64]={};
void convert(char &c)
{
	if(c>='0' && c<='9')
		c-='0';
	else if(c>='A' && c<='Z')
		c=c-'A'+10;
	else if(c>='a' && c<='z')
		c=c-'a'+36;
	else if(c=='-')
		c=62;
	else
		c=63;
	// cout<<(int)c<<endl;
}
int findcount(int c)
{
	int ans=0;
	for(int i=0;i<64;i++)
		if((i & c )==c)
			ans++;
	return ans;
}
long long int findcomb(char c)
{
	convert(c);
	if(com[c]!=-1)
		return com[c];
	return com[c]=findcount(c);
}
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string s;
	long long int val=1;
	cin>>s;
	memset(com,-1,sizeof com);
	for(int i=0;i<s.size();i++)
	{
		val=val*((2*findcomb(s[i]))-1);
		// cout<<s[i]<<" "<<findcomb(s[i])<<endl;
		if(val>1000000007)
			cout<<"AAZA\n";
		val%=1000000007;
	}
	// val=(2*val)%1000000007+1;
	val%=1000000007;
	cout<<val<<endl;
	// cout<<(val*(val%1000000007))-1;
}