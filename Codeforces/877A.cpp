// AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string fr []= {"Danil","Olya","Slava","Ann","Nikita"};
	string prob;
	cin>>prob;
	int c = 0;
	for (int i=0;i<5;i++)
	{
		if (prob.find(fr[i])!=-1)
		{
			c++;
			int idx1 = prob.find(fr[i]);
			idx1+= fr[i].size();
			if (prob.find(fr[i],idx1)!=-1)
			{
				c++;	
			}
		}
	}
	if(c==1)
		cout<<"YES";
	else
		cout<<"NO";
}