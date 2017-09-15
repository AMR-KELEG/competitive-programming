#include "bits/stdc++.h"
using namespace std;
int main()
{
	bool show_the_schedule=true;
	vector<int>time_of_each_day,maxTime;
	int d,sumTime,minTime_i,maxTime_i;
	cin>>d>>sumTime;
	for(int i=0;i<d;i++)
	{
		cin>>minTime_i>>maxTime_i;
		maxTime.push_back(maxTime_i);
		if(sumTime-minTime_i>=0)
		{
			sumTime-=minTime_i;
			time_of_each_day.push_back(minTime_i);	
		}
		else
		{
			show_the_schedule=false;
		}
	}

	if(show_the_schedule && sumTime==0)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<d;i++)
		{
			cout<<time_of_each_day[i]<<" ";
		}
	}
	else if(!show_the_schedule)
	{
		cout<<"NO";
	}
	else
	{
		for(int i=0;i<d;i++)
		{
			if(sumTime-(maxTime[i]-time_of_each_day[i])>0)
			{
				sumTime-=maxTime[i]-time_of_each_day[i];
				time_of_each_day[i]=maxTime[i];
			}
			else if(sumTime-(maxTime[i]-time_of_each_day[i])<=0)
			{
				time_of_each_day[i]+=sumTime;	
				sumTime=0;
				break;
			}
		}
		if(sumTime==0)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<d;i++)
			{
				cout<<time_of_each_day[i]<<" ";
			}
		}
		else 
		{
			cout<<"NO";
		}
	}
	return 0;
}