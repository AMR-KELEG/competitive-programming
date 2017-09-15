#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	cin>>n;
	string old_s,new_s;
	int no_of_dependencies[26]={};
	vector<int>nodes_dependant[26];
	cin>>new_s;
	if(n==1)cout<<"abcdefghijklmnopqrstuvwxyz";
	else
	{
		bool different=true;
		bool change=true;
		for(int i=1;i<n;i++)
		{
			different=false;
			old_s=new_s;
			cin>>new_s;
			for(int j=0;j<min(old_s.length(),new_s.length());j++)
			{
				if(old_s[j]!=new_s[j])
				{
					different=true;
					no_of_dependencies[new_s[j]-'a']++;
					nodes_dependant[old_s[j]-'a'].push_back(new_s[j]-'a');
					break;
				}
			}	
			if(different==false && new_s.length()<old_s.length())
			{
				i=n;
				change=false;
			}

		}
		
		
		string output;
		int no_of_letters=0;
		while(change)
		{
			change=false;
			for(int i=0;i<26;i++)
			{
				if(no_of_dependencies[i]==0)
				{
					change=true;
					no_of_letters++;
					output=output+char('a'+i);
					no_of_dependencies[i]=-1;
					for(int j=0;j<nodes_dependant[i].size();j++)
					{
						no_of_dependencies[nodes_dependant[i][j]]--;
					}
					break;
				}
			}
		}

		if(no_of_letters==26)
		{
			cout<<output;
		}
		else
		{
			cout<<"Impossible";
		}



	}
	return 0;
}