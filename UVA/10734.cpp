// AC
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double> 
#define X real()
#define Y imag()
#define EPS 1e-12
#define Triangle std::vector<long double> 
#define A first.first
#define B first.second
#define C second

std::vector<Triangle> valid_tri;
void add_tri(long double a,long double b,long double c)
{
	Triangle cur_t(3);
	cur_t[0] = a;
	cur_t[1] = b;
	cur_t[2] = c;
	sort(cur_t.begin(), cur_t.end());
	if (abs(cur_t[0])<EPS)
		return ;
	for (int i=2;i>=0;i--)
	{
		cur_t[i] /= cur_t[0];
	}
	for (auto t:valid_tri)
	{
		int no_eq = 0;
		for (int i=0;i<3;i++)
		{
			if (abs(t[i]-cur_t[i])<EPS)
				no_eq++;
		}
		if (no_eq == 3)
			return ;
	}
	valid_tri.push_back(cur_t);
	long double cos_ang = cur_t[1]*cur_t[1] + cur_t[2]*cur_t[2] - cur_t[0]*cur_t[0];
	cos_ang /= 2*cur_t[1]*cur_t[2];
	long double n = cur_t[1]*cur_t[1] + (cur_t[2]/2)*(cur_t[2]/2);
	n -= cur_t[1]*cur_t[2]*cos_ang;
	n = sqrt(n);
	add_tri(n,cur_t[0],cur_t[2]/2);
	add_tri(n,cur_t[1],cur_t[2]/2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		valid_tri.clear();
		long double a,b,c;
		cin>>a>>b>>c;
		add_tri(a,b,c);
		printf("Triangle %d: %d\n", t,(int)valid_tri.size());
	}	
}