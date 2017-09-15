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
	cin>>s;
	int lenout=0,wordsin=0;
	bool isin=0;
	int curlen=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			lenout=max(lenout,curlen);
			curlen=0;
			isin=1;
		}
		else if(s[i]==')')
		{
			if(curlen>0)
			{
				wordsin++;
			}
			curlen=0;
			isin=0;	
		}
		else if(s[i]==' ' ||s[i]=='_')
		{
			if(isin)
			{
				if(curlen>0)
				{
					wordsin++;
				}
			}
			else
			{
				lenout=max(lenout,curlen);
			}
			curlen=0;
		}
		else
		{
			curlen++;
		}
	}

	if(isin && curlen)
	{
		wordsin+=1;
	}
	else
	{
		lenout=max(lenout,curlen);
	}
	cout<<lenout<<" "<<wordsin;
}