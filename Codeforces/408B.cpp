#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	std::vector<int> has(26,0),needed(26,0);
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{		
		has[a[i]-'a']++;
	}
	for(int i=0;i<b.size();i++)
	{
		needed[b[i]-'a']++;	
	}
	//cout<<a<<endl<<b<<endl;
	int max_area=0;
	for(int i=0;i<26;i++)
	{
		if(needed[i]==0)continue;
		if(has[i]>=needed[i])max_area+=needed[i];
		else if(has[i]==0)
		{
			max_area=-1;
			break;
		}
		else
		{
			max_area+=has[i];
		}
	}
	cout<<max_area;
	return 0;
}
