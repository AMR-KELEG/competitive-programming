// AC
#include "bits/stdc++.h"
using namespace std;
short to_hex(char c1,char c2)
{
	short ans = 0;
	if (c1>='0' && c1<='9')
	{
		ans += 16 * (c1-'0');
	}
	else
	{
		ans += 16 * (10 + c1-'A');
	}
	if (c2>='0' && c2<='9')
	{
		ans += (c2-'0');
	}
	else
		ans += (10 + c2-'A');
	return ans;
}

void print_hex(short val)
{
	int c1 = val/16;
	val %=16;
	int c2 = val;
	if (c1<=9)
	{
		printf("%d", c1);
	}
	else
	{
		char cur = 'A'+(c1-10);
		printf("%c", cur);
	}
	if (c2<=9)
	{
		printf("%d", c2);
	}
	else
	{
		char cur = 'A'+(c2-10);
		printf("%c", cur);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s1,s2;
	cin>>s1>>s2;
	std::vector<short> e1(s1.size()/2),e2(s2.size()/2);
	for (int i=0,j=0;i<s1.size();i+=2,j++)
	{
		e1[j] = to_hex(s1[i],s1[i+1]);
	}
	for (int i=0,j=0;i<s2.size();i+=2,j++)
	{
		e2[j] = to_hex(s2[i],s2[i+1]);
	}
	short last_m = 32;
	short last_k = 0;
	for (int i=0;i<e1.size();i++)
	{
		last_k = e2[i] ^ last_m;
		print_hex(last_k);
		last_m = e1[i] ^ last_k;
	}
	last_k = e2[e1.size()] ^ last_m;
	print_hex(last_k);
}