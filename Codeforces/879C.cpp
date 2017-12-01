// AC
#include "bits/stdc++.h"
using namespace std;

char do_op(const char & op, const char & f,const char & s)
{
	if (op=='~')
	{
		if (f=='0')
			return '1';
		if (f=='1')
			return '0';
		if (f=='a')
			return 'n';
		return 'a';
	}
	if (op=='&')
	{
		if (s=='1')
			return f;
		return '0';
	}
	if (op=='|')
	{
		if (s=='1')
			return '1';
		return f;
	}
	if (s=='0')
		return f;
	return do_op('~',f,s);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	string bits(10,'a');
	for (int i=0;i<n;i++)
	{
		char op;
		int mask;
		cin>>op>>mask;
		for (int s=0;s<10;s++)
		{
			if ((mask>>s) & 1)
			{
				bits[9-s] = do_op(op,bits[9-s],'1');
			}
			else
				bits[9-s] = do_op(op,bits[9-s],'0');	
		}
	}
	int and_mask = 1023, or_mask = 0, xor_mask = 0;
	for (int i=9;i>=0;i--)
	{
		// cout<<bits[i];
		if (bits[i]=='0')
			and_mask ^= (1<<(9-i));
		else if(bits[i]=='1')
			or_mask |= (1<<(9-i));
		else if(bits[i]=='n')
			xor_mask |= (1<<(9-i));
	}
	// cout<<endl<<endl;
	cout<<3<<endl;
	string oper="&|^";
	int ma[]={and_mask,or_mask,xor_mask};
	for (int i=0;i<3;i++)
	{
		cout<<oper[i]<<" "<<ma[i]<<endl;
	}	
}