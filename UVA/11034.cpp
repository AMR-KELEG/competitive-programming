//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int l,templ,m,c;
	cin>>c;
	while(c--)
	{
		cin>>l>>m;
		l=l*100;
		string s;
		long long int sl;
		queue<int>le,ri;
		bool left=1;
		long long int trips=0;
		for(int i=0;i<m;i++)
		{
			cin>>sl>>s;
			if(s=="left")
			{
				le.push(sl);
			}
			else
			{
				ri.push(sl);
			}
		}
		while(!le.empty() || !ri.empty())
		{
			templ=l;
			if(left)
			{
				while(!le.empty())
				{
					if(templ>=le.front())
					{
						templ-=le.front();
						le.pop();
					}
					else
					{
						break;
					}
				}
				
			}
			else
			{
				while(!ri.empty())
				{
					if(templ>=ri.front())
					{
						templ-=ri.front();
						ri.pop();
					}
					else
					{
						break;
					}
				}
			}
			trips++;
			left=!left;
		}
		cout<<trips<<endl;



	}	
}