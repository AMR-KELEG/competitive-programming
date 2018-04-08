#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("C-small-attempt1.in","r",stdin);
		//freopen("C-small-out1_diff.in","w",stdout);
	#endif
	int te;cin>>te;
	int n;
	std::vector<string> fir,sec;
	map<string,int>allfir,allsec;
	std::map<string, bool> unfir,unsec;
	int cheat=0;
	std::vector<bool> skip;
	for(int t=1;t<=te;t++)
	{
		cheat=0;
		cin>>n;
		allsec.clear();
		allfir.clear();
		fir=std::vector<string> (n);
		sec=std::vector<string> (n);
		skip=std::vector<bool> (n,0);
		unfir.clear();
		unsec.clear();
		for(int i=0;i<n;i++)
		{
			cin>>fir[i]>>sec[i];
			allfir[fir[i]]++;
			allsec[sec[i]]++;
		}

		for(int i=0;i<n;i++)
		{
			if(allfir[fir[i]]>1 && allsec[sec[i]]<=1 && !unfir[fir[i]])
			{
				cout<<"Pre "<<fir[i]<<" "<<sec[i]<<endl;
				unfir[fir[i]]=1;
				allfir[fir[i]]--;
				allsec[sec[i]]--;
				skip[i]=1;
			}
			else if(allfir[fir[i]]<=1 && allsec[sec[i]]>1 && !unsec[sec[i]])
			{
				cout<<"Pre "<<fir[i]<<" "<<sec[i]<<endl;
				unsec[sec[i]]=1;
				allfir[fir[i]]--;
				allsec[sec[i]]--;
				skip[i]=1;	
			}
		}

		for(int i=0;i<n;i++)
		{
			if(skip[i])
				continue;
			if(!unfir[fir[i]] && !unsec[sec[i]])
			{
				cout<<"Vic "<<fir[i]<<" "<<sec[i]<<endl;
				allfir[fir[i]]--;
				allsec[sec[i]]--;
				unfir[fir[i]]=1;
				unsec[sec[i]]=1;
				skip[i]=1;
			}
		}

		for(int i=0;i<n;i++)
		{
			if(skip[i])
				continue;
			if(!unfir[fir[i]] || !unsec[sec[i]])
			{
				cout<<"Vic2 "<<fir[i]<<" "<<sec[i]<<endl;
				allfir[fir[i]]--;
				allsec[sec[i]]--;
				unfir[fir[i]]=1;
				unsec[sec[i]]=1;
				skip[i]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(skip[i])
				continue;
			if(allfir[fir[i]]>=1 && allsec[sec[i]]>=1 && unfir[fir[i]] && unsec[sec[i]])
			{
				cheat++;
				cout<<fir[i]<<" "<<sec[i]<<endl;
			}

		}


		
		cout<<"Case #"<<t<<": "<<cheat<<endl;

	}
}