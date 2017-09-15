//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int l,c,r1,r2;
	cin>>l>>c>>r1>>r2;
	while (! (l==0 && c==0 && r1==0 && r2==0))
	{
		int max_r = max(r1,r2);
		if (max_r*2 <= min(l,c))
		{
			// try doing it
			int x1 = r1;
			int y1 = r1;
			int x2 = l-r2;
			int y2 = c-r2;
			int dx = (x1-x2);
			int dy = (y1-y2);
			int dis = (dx*dx) + (dy*dy);
			if (dis>= (r1+r2)*(r1+r2))
			{
				cout<<"S\n";
			}
			else
			{
				cout<<"N\n";
			}
		}
		else
		{
			cout<<"N\n";
		}
		cin>>l>>c>>r1>>r2;
	}

}