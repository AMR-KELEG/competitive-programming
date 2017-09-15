//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-small-practice.in","r",stdin);
		freopen("a.txt","w",stdout);
	#endif
	map<char,char>mp;
	mp['a']='y';
	mp['b']='h';
	mp['c']='e';
	mp['d']='s';
	mp['e']='o';
	mp['f']='c';
	mp['g']='v';
	mp['h']='x';
	mp['i']='d';
	mp['j']='u';
	mp['k']='i';
	mp['l']='g';
	mp['m']='l';
	mp['n']='b';
	mp['o']='k';
	mp['p']='r';
	mp['q']='z';
	mp['r']='t';
	mp['s']='n';
	mp['t']='w';
	mp['u']='j';
	mp['v']='p';
	mp['w']='f';
	mp['x']='m';
	mp['y']='a';
	mp['z']='q';
	mp[' ']=' ';
	int T;
	cin>>T;
	string s;
	getline(cin,s);
	for(int t=1;t<=T;t++)
	{
		getline(cin,s);
		cout<<"Case #"<<t<<": ";
		for(int i=0;i<s.size();i++)
		{
			cout<<mp[s[i]];
		}
		cout<<endl;
	}
}