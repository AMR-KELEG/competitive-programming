#include "bits/stdc++.h"
using namespace std;
#define Polygon pair<char,vector<pair<long double,long double> > >
#define Type first
#define PTS second
vector<Polygon> poly;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	char pol;
	cin>>pol;
	while(pol!='*')
	{
		Polygon cur_pol;
		cur_pol.Type = pol;
		if (pol == 'r')
		{
			long double x,y;
			for(int i=0;i<2;i++)
			{
				cin>>x>>y;
				cur_pol.PTS.push_back({x,y});
			}
		}
		else if(pol=='c')
		{
			long double x,y;
			cin>>x>>y;
			cur_pol.PTS.push_back({x,y});
			cin>>x;
			cur_pol.PTS.push_back({x,0});
			
		}
		else
		{
			long double x,y;
			for(int i=0;i<3;i++)
			{
				cin>>x>>y;
				cur_pol.PTS.push_back({x,y});
			}
		}
		poly.push_back(cur_pol);
		cout<<pol<<endl;
		cin>>pol;
	}	
	long double x,y;
	cin>>x>>y;
	int indx = 1;
	while (!(x==9999.9 &&y==9999.9))
	{
		bool found = 0;

		if (!found)
			cout<<"Point "<<indx<<" is not contained in any figure\n";
		indx++;
		cout<<x<<" "<<y<<endl;
		if (indx == 10)
			break;
		cin>>x>>y;
	}
}