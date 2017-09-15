//11:47
// start 12:04
// debug 12:23
// 12:38
//AC
#include "bits/stdc++.h"
#define PI 3.141592653589793
#define INF 1000000000
#define R 6378
int dis[100][100]={};
std::vector<long double> lon,lat;
using namespace std;
int find_dis(int ina,int inb)
{
	long double d=R*cos(lat[ina]);
	long double xa= d* cos(lon[ina]),ya= d* sin(lon[ina]);
	long double za=R*sin(lat[ina]);
	d=R*cos(lat[inb]);
	long double xb= d* cos(lon[inb]),yb= d* sin(lon[inb]);
	long double zb=R*sin(lat[inb]);
	
	// cout<<"Lon Lat "<<lon[ina]*180/PI<<" "<<lat[ina]*180/PI<<endl;
	// cout<<"Coord "<<xa<<" "<<ya<<" "<<za<<endl;	
	long double a = sqrt((xa*xa)+(ya*ya)+(za*za));
	long double b = sqrt((xb*xb)+(yb*yb)+(zb*zb));
	long double dot = (xa*xb)+(ya*yb)+(za*zb);

	long double th = dot/a;
	th/=b;
	th=acos(th);
	long double distance = R *th;
	return round(distance);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,q;
	cin>>n>>m>>q;
	int test=1;
	while(!(n==0 && m==0 && q==0))
	{
		lon = std::vector<long double> (n);
		lat = std::vector<long double> (n);
		map<string,int> city;
		int cur_city=0;
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s>>lat[i]>>lon[i];
			lon[i] *=(PI/180);
			lat[i] *=(PI/180);
			if(city.find(s)==city.end())
			{
				city[s]=cur_city++;
			}
			// cout<<s<<" "<<city[s]<<endl;
			for(int j=0;j<n;j++)
			{
				if(i==j)
					dis[i][j]=0;
				else
					dis[i][j]=INF;
			}
		}
		string a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			int ina= city[a];
			int inb= city[b];
			dis[ina][inb]=find_dis(ina,inb);
		}

		for(int piv=0;piv<n;piv++)
		{
			for(int src=0;src<n;src++)
			{
				for(int des=0;des<n;des++)
				{
					if(dis[src][piv]+dis[piv][des]<dis[src][des])
						dis[src][des] = dis[src][piv]+dis[piv][des];
				}
			}
		}

		printf("Case #%d\n",test++);
		while(q--)
		{
			cin>>a>>b;
			int ina=city[a];
			int inb=city[b];
			if(dis[ina][inb]==INF)
				printf("no route exists\n");
			else
				printf("%d km\n", dis[ina][inb]);
		}
		cin>>n>>m>>q;
		if(!(n==0 && m==0 && q==0))
		printf("\n");
	}
}