#include "bits/stdc++.h"
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	cin>>m>>n;
	std::vector<int> elapsedtime(m,0);
	std::vector<vector<int> > time;
	std::vector<int> temp(n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp[j];
		}
		time.push_back(temp);
	}
	int current_time=0;
	for(int p=0;p<n;p++)
	{
		current_time=elapsedtime[0];
		for(int i=0;i<m;i++)
		{
			if(current_time<elapsedtime[i])
			{
				//elapsedtime[i]=current_time;
				elapsedtime[i]+=time[i][p];
			}
			else
			{
				elapsedtime[i]=current_time+time[i][p];
			}
			current_time=elapsedtime[i];
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<elapsedtime[i]<<" ";
	}
	return 0;
}