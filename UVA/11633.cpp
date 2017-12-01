// AC
#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define EPS 0.0000000000001
struct Fraction
{
	ll a,b;
	Fraction(ll aa=0, ll bb=1):a(aa),b(bb){}
	void add(const Fraction & f2)
	{
		ll c = f2.a;
		ll d = f2.b;
		ll num = a*d + b*c;
		ll den = b*d;
		ll GCD = __gcd(num, den);
		num /= GCD;
		den /= GCD;
		a = num;
		b = den;
	}
	
	void sub(ll c)
	{
		ll num = a - b*c;
		ll den = b;
		ll GCD = __gcd(num, den);
		num /= GCD;
		den /= GCD;
		a = num;
		b = den;
	}
	void mul(ll c)
	{
		ll num = a*c;
		ll den = b;
		ll GCD = __gcd(num, den);
		num /= GCD;
		den /= GCD;
		a = num;
		b = den;
	}
	bool less(const Fraction & f2)
	{
		long double v1= 1.0*a/b;
		long double v2= 1.0*f2.a/f2.b;
		return v1<v2;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		ll a,b;
		cin>>a>>b;
		std::vector<int> v(n);
		ll total_req = 0;
		for (int i=0;i<n;i++)
		{
			cin>>v[i];
			total_req += v[i];
		}
		sort (v.begin(), v.end());
		Fraction ans (-1,1);
		bool not_set = 1;
		for (int i=0;i<n;i++)
		{
			for (int den = 1;den<=3;den++)
			{
				long double ss = ((long double)1.0*v[i]) /den;
				if (ceil(v[n-1]/ss)>3)
				{
					continue;
				}
				Fraction s(v[i],den);
				ll total_fetches = 0;
				for (int j=0;j<n;j++)
				{
					int fetches = ceil(v[j]/ss);
					total_fetches += fetches;
					// cur_ans.add(Fraction(b*fetches,1));
					
					// Fraction rem(s);
					// rem.mul(fetches);
					// rem.sub(v[j]);
					// rem.mul(a);
					// cur_ans.add(rem);
				}
				Fraction cur_ans(b*total_fetches,1);
				// s* total_fetches - req
				s.mul(total_fetches);
				s.sub(total_req);
				s.mul(a);
				cur_ans.add(s);
				if (not_set || cur_ans.less(ans))
				{
					not_set = 0;
					ans = cur_ans;
				}
			}
		}
		ll GCD = __gcd(ans.a,ans.b);
		ans.a /= GCD;
		ans.b /= GCD;
		if (ans.b !=1)
		{
			cout<<ans.a<<" / "<<ans.b<<"\n";
		}
		else
			cout<<ans.a<<"\n";
		cin>>n;
	}
}	