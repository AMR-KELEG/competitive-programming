// WA
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double> 
#define EPS 0.00000000000000001
#define SPS 0.0001
#define len(a) abs(a)
#define X real()
#define Y imag()
#define rotate(a,th) ((a)*exp(Point(0,1)*th))

long double rou(long double value)
{
	long double ans = round( value * 1000.0 ) / 1000.0;
	if (abs(ans)<=SPS)
		ans = abs(ans);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double x1,y1,x2,y2,R1,R2;
	while(cin>>x1>>y1>>R1)
	{
		cin>>x2>>y2>>R2;
		Point C1 (x1,y1);
		Point C2 (x2,y2);
		long double dis = len(C1-C2);
		long double dr = R1 + R2;
		long double delta_r = abs(R1-R2);
		if ((abs(R2-R1)<=EPS && abs(x2-x1)<=EPS && abs(y2-y1)<=EPS) ) 
		{
			if (abs(R1)<=EPS)
				// cout<<fixed<<setprecision(3)<<"("<<x1<<","<<y1<<")\n";
				printf("(%0.3LF,%0.3LF)\n", x1,y1);
			else
				cout<<"THE CIRCLES ARE THE SAME\n";
		}
		else if (abs(delta_r - dis)<=EPS)
		{
			// int at a point
			if (R1<R2)
			{
				swap(C1,C2);
				swap(R1,R2);
			}
			Point int_1 = C2-C1;
			int_1 /= len(int_1);
			int_1 *= R1;
			int_1 += C1;
			printf("(%0.3LF,%0.3LF)\n", rou(int_1.X),rou(int_1.Y));
			// cout<<fixed<<setprecision(3)<<"("<<rou(int_1.X)<<","<<rou(int_1.Y)<<")\n";
		}
		else if (dis < delta_r)
		{
			cout<<"NO INTERSECTION\n";
		}
		else
		{
			if (dis<dr && abs (dr-dis)>EPS)
			{
				long double cos_th = (R1*R1) + (dis * dis) - (R2*R2);
				cos_th /= (2*dis*R1);
				long double th = acos(cos_th);
				Point int_1 = C2-C1;
				int_1 /= len(int_1);
				int_1 = rotate(R1*int_1, th);
				int_1 += C1;
				Point int_2 = C2-C1;
				int_2 /= len(int_2);
				int_2 = rotate(R1*int_2, -th);
				int_2 += C1;
				if ((int_1.X > int_2.X && (abs(int_1.X - int_2.X)>EPS)) || 
					((abs(int_1.X - int_2.X)<EPS) && int_1.Y > int_2.Y))
					swap(int_1,int_2);
				printf("(%0.3LF,%0.3LF)", rou(int_1.X),rou(int_1.Y));
				printf("(%0.3LF,%0.3LF)\n", rou(int_2.X),rou(int_2.Y));
				// cout<<fixed<<setprecision(3)<<"("<<rou(int_1.X)<<","<<rou(int_1.Y)<<")";
				// cout<<fixed<<setprecision(3)<<"("<<rou(int_2.X)<<","<<rou(int_2.Y)<<")\n";
			}
			else if (abs(dis-dr)<=EPS)
			{
				long double cos_th = (R1*R1) + (dis * dis) - (R2*R2);
				cos_th /= (2*dis*R1);
				long double th = acos(cos_th);
				Point int_1 = C2-C1;
				int_1 /= len(int_1);
				int_1 = rotate(R1*int_1, th);
				int_1 += C1;
				printf("(%0.3LF,%0.3LF)\n", rou(int_1.X),rou(int_1.Y));
				// cout<<fixed<<setprecision(3)<<"("<<rou(int_1.X)<<","<<rou(int_1.Y)<<")\n";
			}
			else
			{
				cout<<"NO INTERSECTION\n";
			}
		}
	}	
}