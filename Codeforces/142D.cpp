//AC
#include "bits/stdc++.h"
using namespace std;

int n,m,k;
vector<int> xorVal(7,0);

vector<int> convert(int no)
{
	vector<int>ans(7,0);
	int in=6;
	while(no>0)
	{
		ans[in--]=no%2;
		no/=2;
	}
	return ans;
}

int main()
{
	cin>>n>>m>>k;
	if(m==1)
	{
		cout<<"Second";
	}
	
	else if(m==2)
	{
		int r=0,g=0;
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s=="GR" || s=="RG" || s=="RR" || s=="RG" || s=="RR" || s=="GG")
				continue;
			if(s.find('G')!=-1)
				g++;
			else if(s.find('R')!=-1)
				r++;
		}
		if(g>r)
			cout<<"First";
		else
			cout<<"Second";
	}
	
	else if(n==1)
	{
		string s;
		cin>>s;
		if( s.find('G')==-1 || s.find("GR")!=-1 || s.find("RG")!=-1 )
		{
			cout<<"Second";
		}
		else
		{
			cout<<"First";
		}
	}
	
	else
	{
		bool g=0,r=0;
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s.find('G')==-1 && s.find('R')==-1)
				continue;
			if(s.find("GR")!=-1 || s.find("RG")!=-1)
				continue;
			if(s.find('G')!=-1)
			{
				if(s.find('R')!=-1)
				{
					int p=abs((int)s.find('R')-(int)s.find('G'));
					auto v=convert(p-1);
					for(int i=0;i<7;i++)
						xorVal[i]+=v[i];
				}
				else
				{
					g=1;
				}
			}
			else if(s.find('R')!=-1)
			{
				r=1;
			}
		}
		if(g && r)
			cout<<"Draw";
		else if(g)
		{
			cout<<"First";
		}
		else if(r)
		{
			cout<<"Second";
		}
		else
		{
			for(int i=0;i<7;i++)
				if(xorVal[i]%(k+1)!=0)
				{
					g=1;
					break;
				}
			if(g)
				cout<<"First";
			else
				cout<<"Second";
		}
	}
}
