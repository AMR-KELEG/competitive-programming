/* AC
- Instead of removing random k magnets, Remove magnets that lie on the 4 boundaries.
- Make sure you don't count removing the same magnet twice.
*/

#include "bits/stdc++.h"
using namespace std;
std::vector< pair<int,int> > centers_x;
std::vector< pair<int,int> > centers_y;
int n,k;

long long int find_area(int a,int b,int c,int d)
{
	// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	set<int>removed;
	int min_x = centers_x[0].first;
	int max_x = centers_x.back().first;
	int min_y = centers_y[0].first;
	int max_y = centers_y.back().first;
	int r = 0;
	int i=0;
	while(r<a)
	{
		int indx = centers_x[i].second;
		i++;
		if (removed.find(indx)!=removed.end())
		{
			continue;
		}
		removed.insert(indx);
		r++;
	}

	r=0;
	i=0;
	while(r<b)
	{
		int indx = centers_y[i].second;
		i++;
		if (removed.find(indx)!=removed.end())
		{
			continue;
		}
		removed.insert(indx);
		r++;
	}
	
	r=0;
	i=n-1;
	while(r<c)
	{
		int indx = centers_x[i].second;
		i--;
		if (removed.find(indx)!=removed.end())
		{
			continue;
		}
		removed.insert(indx);
		r++;
	}
	
	r=0;
	i=n-1;
	while(r<d)
	{
		int indx = centers_y[i].second;
		i--;
		if (removed.find(indx)!=removed.end())
		{
			continue;
		}
		removed.insert(indx);
		r++;
	}
	
	for (int i=0;i<n;i++)
	{
		int indx = centers_x[i].second;
		if (removed.find(indx)==removed.end())
		{
			min_x = centers_x[i].first;
			break;
		}
	}
	for (int i=0;i<n;i++)
	{
		int indx = centers_y[i].second;
		if (removed.find(indx)==removed.end())
		{
			min_y = centers_y[i].first;
			break;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		int indx = centers_x[i].second;
		if (removed.find(indx)==removed.end())
		{
			max_x = centers_x[i].first;
			break;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		int indx = centers_y[i].second;
		if (removed.find(indx)==removed.end())
		{
			max_y = centers_y[i].first;
			break;
		}
	}

	// cout<<min_x<<" "<<max_x<<endl;
	// cout<<min_y<<" "<<max_y<<endl<<endl; 
	long long int dx = (max_x - min_x)/2;
	long long int dy = (max_y - min_y)/2;
	if (dx==0)
		dx = 1;
	if (dy==0)
		dy = 1;
	return dx*dy;
}

long long int solve()
{
	long long int ans = find_area(0,0,0,0);
	for (int a=0;a<=k;a++)
	{
		for (int b=0;a+b<=k;b++)
		{
			for (int c=0;a+b+c<=k;c++)
			{
				int d = k-(a+b+c);
				ans = min(ans, find_area(a,b,c,d));
			}
		}
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d %d", &n, &k);
	centers_x = std::vector< pair<int,int> > (n);
	centers_y = std::vector< pair<int,int> > (n);
	for(int i=0,x1,y1,x2,y2;i<n;i++)
	{
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		centers_x[i] = {x1+x2,i};
		centers_y[i] = {y1+y2,i};
	}
	sort (centers_x.begin(), centers_x.end());
	sort (centers_y.begin(), centers_y.end());
	printf("%I64d\n", solve());
}