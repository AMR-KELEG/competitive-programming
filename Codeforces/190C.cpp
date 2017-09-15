//AC
#include "bits/stdc++.h"
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	/*
	string st1;
	int n;
	cin>>n;
	stack<string>st,temp;
	while(cin>>st1)
	{
		temp.push(st1.substr(0,1));
	}
	bool ok=1;
	string fi,se;
	while(!temp.empty())
	{
		if(temp.top()=="p")
		{
			if(st.size()<2)
			{
				ok=0;
				break;
			}
			else
			{
				temp.pop();
				fi=st.top();
				st.pop();
				se=st.top();
				st.pop();
				st.push("p<"+fi+","+se+">");
			}
		}
		else
		{
			st.push(temp.top());
			temp.pop();
		}
	}
	if(st.size()!=1)
	{
		ok=0;
	}
	if(ok)
	{
		string ts=st.top();
		for(int i=0;i<ts.size();i++)
		{
			if(ts[i]=='p')
			{
				printf("%s","pair");
			}
			else if(ts[i]=='i')
			{
				printf("%s","int");
			}
			else
			{
				printf("%c",ts[i]);
			}
				
		}
	}
	else
	{
		cout<<"Error occurred";
	}
	pair int int
	pair<int,int>

	pair int pair int int
	pair<int,pair<int,int>>


	}




	*/
	int n;
	cin>>n;
	stack<int>st;
	string s;
	queue<string> ans;
	bool ok=1;
	bool first=1;
	while(cin>>s)
	{
		if(s=="pair")
		{
			first=0;
			st.push(0);
			ans.push("pair<");
		}
		else
		{
			if(first)
			{
				if(cin>>s)
				{	
					ok=0;
					break;
				}
				else
				{
					ans.push("int");
					break;
				}
			}
			if(st.empty())
			{
				ok=0;
				break;	
			}
			else if(st.top()==0)
			{
				st.top()++;
				ans.push("int,");
			}
			else
			{
				ans.push("int>");
				st.pop();
				while(!st.empty())
				{
					st.top()++;
					if(st.top()==2)
					{
						ans.push(">");
						st.pop();
					}
					else
					{
						ans.push(",");
						break;
					}
				}
			}
		}
	}
	
	if(st.size()>0)
	{
		ok=0;
	}
	if(ok)
	{
		while(!ans.empty())
		{
			printf("%s",ans.front().c_str());
			ans.pop();
		}
	}
	else
		cout<<"Error occurred";
	
}