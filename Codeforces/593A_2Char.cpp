#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	map < pair<char,char> ,int >max_pair;
	cin>>n;
	string s;
	//int totalco=0;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		//totalco+=s.size();
		int nuofchar=1;
		char c1,c2;
		int count1=1,count2=0;
		c1=s[0];
		for(int c=1;c<s.size();c++)
		{
			if(s[c]==c1)
			{
				count1++;
			}
			else if(nuofchar==1)
			{
				nuofchar++;
				c2=s[c];
				count2++;
			}
			else if(s[c]==c2)
			{
				count2++;
			}
			else
			{
				nuofchar++;
				break;
			}
		}

		if(nuofchar==1)
		{
			for(int c='a';c<c1;c++)
			{
				max_pair[pair<char,char>(c,c1)]+=count1;
			}
			for(int c=c1+1;c<='z';c++)
			{
				max_pair[pair<char,char>(c1,c)]+=count1;
			}
		}
		else if(nuofchar==2)
		{
			max_pair[pair<char,char>(min(c1,c2),max(c1,c2))]+=count1+count2;
		}


	}
	int max_counter=0;
	for(map < pair<char,char> ,int >::iterator it=max_pair.begin();it!=max_pair.end();it++)
	{
		if((*it).second>max_counter)max_counter=(*it).second;
	}
	//cout<<totalco<<endl;
	cout<<max_counter;
	return 0;
}