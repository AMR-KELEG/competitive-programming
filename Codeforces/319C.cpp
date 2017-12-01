/* AC
Convex hull optimization (trick)
*/
#include "bits/stdc++.h"
using namespace std;
int n;
int a[100000]={};
int b[100000]={};
long long int dp[100000]={};
class Vector
{
private:
	std::vector<int> M;
	std::vector<long long> C;
	int cur_size;
public:
	Vector(int size)
	{
		cur_size = 0;
		M = std::vector<int> (size);
		C = std::vector<long long> (size);
	}
	int size()
	{
		return cur_size;
	}

	long double equal_x_point(int mt, int mb, long long ct, long long cb)
	{
		// it - ib
		long double delm = mt-mb;
		long double delc = ct-cb;
		return -delc/delm;
	}

	void add_line(int m, long long c)
	{
		// Remove lines
		while(cur_size>1 && 
			equal_x_point(m,M[cur_size-1],c,C[cur_size-1]) < 
			equal_x_point(M[cur_size-1],M[cur_size-2],C[cur_size-1],C[cur_size-2]))
		{
			cur_size--;
		}
		M[cur_size] = m;
		C[cur_size] = c;
		cur_size++;
	}

	long long query(long long x)
	{
		// find first_line ; 
		int l = 0;
		int r = cur_size-1;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if (mid==cur_size-1)
			{
				// cout<<"? "<<l<<" "<<r<<endl;
				l = r = mid;
				break;
			}
			if (equal_x_point(M[mid+1],M[mid],C[mid+1],C[mid]) <= x)
			{
				l = mid+1;
			}
			else
			{
				r = mid;
			}
		}
		// cout<<l<<" "<<r<<endl;  
		return M[l]*x + C[l];
	}

};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d", &n);	
	for (int _=0,x;_<n;_++)
	{
		scanf("%d", &x);
		a[_] = x;	
	}
	for (int _=0,x;_<n;_++)
	{
		scanf("%d", &x);
		b[_] = x;
	}
	Vector v(n);
	v.add_line(b[0], 0);
	for (int i=1;i<n-1;i++)
	{
		long long int cur_c = v.query(a[i]);
		// cout<<"y="<<b[i]<<"x + "<<cur_c<<endl;
		v.add_line(b[i], cur_c);
	}
	printf("%lld\n", v.query(a[n-1]));
}