// AC
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int mod_pow(long long int val, int p){
	if (p==0)
		return 1;
	if (p==1)
		return val;
	long long int res = mod_pow(val, p/2);
	res = (res*res) % MOD;
	if (p%2){
		return (res*val) %MOD;
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	long long int ans = mod_pow(27, n) - mod_pow(7, n);
	if (ans < 0)
		ans += MOD;
	cout<<ans;
	return 0;
}
