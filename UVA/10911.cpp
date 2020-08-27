// AC
// Bitmask dp
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int max_size = 1<<16;
long double dp[max_size];
bool solved[max_size];

int x[16], y[16], N;

bool done(int mask){
	return mask == ((1<<2*N)-1);
}

bool free(int mask, int index){
	return ((mask>>index) &1) ==0;
}

long double distance(int a, int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

long double solve(int mask=0){
	if(solved[mask])
		return dp[mask];
	if(done(mask)){
		solved[mask] = 1;
		return dp[mask] = 0;
	}
	solved[mask] = 1;
	int first_free = 0;
	while(!free(mask, first_free)){
		first_free++;
	}
	long double ans = INF;
	for(int i=first_free+1; i<2*N;i++){
		if(free(mask, i)){
			ans = min(ans,
				distance(first_free, i) + solve(mask | (1<<first_free) | (1<<i)));
		}
	}
	return dp[mask] = ans;
}

int main(){
	cin>>N;
	int t=1;
	string _;

	while(N){
		memset(solved, 0, sizeof solved);
		for(int i=0; i<2*N;i++){
			cin>>_>>x[i]>>y[i];
		}
		printf("Case %d: %0.2LF\n", t, solve());
		t++;
		cin>>N;
	}
}