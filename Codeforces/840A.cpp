// AC
// GREEDY
#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	std::vector<int> a_dash(n);
	priority_queue<int> a;
	for (int i=0;i<n;i++){
		int val;
		cin>>val;
		a.push(val);
	}
	priority_queue<pair<int,int>>b;
	for (int i=0;i<n;i++){
		int val;
		cin>>val;
		b.push({-val, i});
	}

	for (int i=0;i<n;i++){
		int val = a.top();
		a.pop();
		int indx = b.top().second;
		b.pop();
		a_dash[indx] = val;
	}

	for (int i=0;i<n;i++)
		printf("%d ", a_dash[i]);
	return 0;
}