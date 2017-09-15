//AC
#include "bits/stdc++.h"
#define INF 100000
#define EPS 0.0000001
using namespace std;
int req[4];

float dp[16][16][16][16][3][3][3][3];
int vis[16][16][16][16][3][3][3][3]={};
int t;
float solve(int a=13,int b=13,int c=13,int d=13,int aa=0,int ab=0,int ac=0,int ad=0)
{
	int takena = 13-a +aa;
	int takenb = 13-b +ab;
	int takenc = 13-c +ac;
	int takend = 13-d +ad;
	if ( takena >= req[0] && takenb >= req[1] && takenc >= req[2] && takend >= req[3] )
		return 0;
	if(vis[a][b][c][d][aa][ab][ac][ad] == t)
		return dp[a][b][c][d][aa][ab][ac][ad];
	int tak [] ={takena,takenb,takenc,takend};
	int da [] ={1,0,0,0};
	int db [] ={0,1,0,0};
	int dc [] ={0,0,1,0};
	int dd [] ={0,0,0,1};
	int param[] = {a,b,c,d};
	vis[a][b][c][d][aa][ab][ac][ad] = t;
	long double ans = 0;
	int ways = 0;
	int j = 2 - (aa+ab+ac+ad);
	int rem = a+b+c+d+ j;
	
	if(j>0)
	{
		float subans [4]={};
		for (int i = 0; i < 4; ++i)
		{
			subans[i] = solve(a,b,c,d,aa+da[i],ab+db[i],ac+dc[i],ad+dd[i]);
			if (abs(subans[i]-INF)<EPS)
				continue;
			ways++;		
		}
		long double p = j;
		p/= (rem);
		float minAns = subans[0];
		for(int i=1;i<4;i++)
		{
			minAns = min(minAns,subans[i]);
		}
		ans +=p*(1+minAns);
	}

	for(int i=0;i<4;i++)
	{
		if(param[i]>0)
		{
			float sub = solve(a-da[i],b-db[i],c-dc[i],d-dd[i],aa,ab,ac,ad);
			if (abs(sub-INF)<EPS)
				continue;
			long double p = param[i];
			p/= rem;
			ans += (1+sub)*p;
			ways++;
		}
	}
	if(ways == 0)
	{
		return dp[a][b][c][d][aa][ab][ac][ad] = INF;
	}
	// ans /=ways;
	return dp[a][b][c][d][aa][ab][ac][ad] = ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		int A,B,C,D;
		cin>>A>>B>>C>>D;
		req[0]=A;
		req[1]=B;
		req[2]=C;
		req[3]=D;
		int sum = A+B+C+D;
		int more = 0;
		for(int i=0;i<4;i++)
		{
			if(req[i]>13)
			{
				more+=req[i]-13;
			}
		}
		if (sum>54 || more>2)
		{
			printf("Case %d: %0.3f\n", t,-1.000);		
		}
		else if(sum == 0)
		{
			printf("Case %d: %0.3f\n", t,0.000);
		}
		else
		{
			printf("Case %d: %0.3f\n", t,solve());
		}
	}
}