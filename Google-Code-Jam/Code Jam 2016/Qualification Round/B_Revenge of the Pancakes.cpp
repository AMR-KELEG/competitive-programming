#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("B-large.in","r",stdin);
		freopen("b.txt","w",stdout);
	#endif
	int test;
	cin>>test;
	string s;
	int flips;
	bool pos;
	for(int t=1;t<=test;t++)
	{
		flips=0;
		pos=1;
		cin>>s;
		if(s[0]=='-')
			pos=0;
		for(int i=0;i<s.size()-1;i++)
		{
			//cout<<s[i]<<" "<<s[i+1]<<endl;
			if(s[i]!=s[i+1])
			{
				flips++;
				pos=!pos;
			}
		}
		if(!pos)
			flips++;
		cout<<"Case #"<<t<<": "<<flips<<endl;
	}	
}
/*


1 ≤ T ≤ 100.
Every character in S is either + or -.

Small dataset

1 ≤ length of S ≤ 10.
Large dataset

1 ≤ length of S ≤ 100.
*/