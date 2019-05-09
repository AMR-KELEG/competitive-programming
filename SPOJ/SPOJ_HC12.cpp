// AC
/*
Solution Idea:
1) Sort the array
2) Answer the following questions:
   What is the number of ways to choose values such that the maximum
   one is a[K-1]?
   Ans: 1 (K-1 Choose K-1)
   What is the number of ways to choose values such that the maximum
   one is a[K]?
   Ans: K (K Choose K-1)
3) Compute the nCk iteratively by updating the last value
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int mod_pow(int val, int p){
	if (p==0) return 1;
	if (p==1) return val;
	long long int res = mod_pow(val, p>>1);
	res = (res * res) % MOD;
	if (p%2) res = (res * val) % MOD;
	return res;
}

int inv(int val){
	return mod_pow(val, MOD-2);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int T;
	cin>>T;
	for (int t=1; t<=T; t++){
		int N, K;
		cin>>N>>K;
		vector<int> a(N);
		for (int i=0; i<N; i++) cin>>a[i];
		sort(a.begin(), a.end());

		long long int base_nCk = 1;
		long long int ans = 0;

		for (int i=K-1; i<N;i++){
			// max is a[K-1]
			ans = ((ans) + (base_nCk * a[i])%MOD)% MOD;
			base_nCk = (base_nCk * (i+1))% MOD;
			base_nCk = (base_nCk * inv(i + 1 + 1- K))% MOD;
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
