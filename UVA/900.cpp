// AC
#include <bits/stdc++.h>

using namespace std;
long long int dp[51];

long long int solve(int len){
	if (len<0)
		return 0;
	if (len==0)
		return 1;
	if (dp[len] != 0)
		return dp[len];
	return dp[len] = solve(len-1) + solve(len-2);
}
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	while(n!=0){
		cout<<solve(n)<<endl;
		cin>>n;
	}
}