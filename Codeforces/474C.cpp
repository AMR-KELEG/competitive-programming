//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<int> a(4),b(4);
std::vector<pair<long long int,long long int> > points(4),sortedpoints(4);
long long int finddis(int i,int j)
{
	return ((sortedpoints[i].first-sortedpoints[j].first)*(sortedpoints[i].first-sortedpoints[j].first))+((sortedpoints[i].second-sortedpoints[j].second)*(sortedpoints[i].second-sortedpoints[j].second));
}
bool check()
{
	set<pair<int,int> >po;
	for(int i=0;i<4;i++)
		po.insert(points[i]);
	if(po.size()<4)
		return 0;
	sortedpoints=points;
	sort(sortedpoints.begin(),sortedpoints.end());
	long long int dis=finddis(0,1);
	if(dis==0)	return 0;
	if(dis!=finddis(1,3))	return 0;
	if(dis!=finddis(2,3))	return 0;
	if(dis!=finddis(0,2))	return 0;
	if(2*dis!=finddis(1,2))	return 0;
	// cout<<dis<<endl;
	return 1;
}
void per(int i)
{
	int xold=points[i].first-a[i];
	int yold=points[i].second-b[i];
	swap(xold,yold);
	points[i].first=a[i]-xold;
	points[i].second=yold+b[i];
}
void print()
{
	for(int i=0;i<4;i++)
	{
		cout<<points[i].first<<" "<<points[i].second<<endl;
	}
}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;	
	cin>>n;
	// if(check())
	// {
	// 	cout<<"Square\n";
	// 	return 0;
	// }
	// int tx=1,ty=1;
	// for(int i=0;i<5;i++)
	// {
	// 	cout<<tx<<" "<<ty<<endl;
	// 	swap(tx,ty);
	// 	tx=-tx;
	// }
	while(n--)
	{
		int steps=1<<29;//3*4
		//x y a b
		for(int i=0;i<4;i++)
		{
			cin>>points[i].first>>points[i].second>>a[i]>>b[i];
		}
		for(int f=0;f<4;f++)
		{
			for(int s=0;s<4;s++)
			{
				for(int t=0;t<4;t++)
				{
					for(int m=0;m<4;m++)
					{
						if(check())
						{
							// if(steps>=f+s+t+m)
							// {
							// 	cout<<f<<" "<<s<<" "<<t<<" "<<m<<" "<<f+s+t+m<<endl;
							// 	print();
							// 	cout<<endl;
							// }
							steps=min(steps,f+s+t+m);
							// cout<<steps<<" IN\n";
						}
						per(3);
					}
					per(2);
				}
				per(1);
			}
			per(0);
		}
		if(steps==1<<29)
			cout<<-1<<endl;
		else
			cout<<steps<<endl;
	}
	


}