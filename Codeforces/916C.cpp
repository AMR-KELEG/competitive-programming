// AC
/* 
Difficulty:
	Moderate idea - Easy implementation
Idea:
We have two things to fix:
1) Making sure the shortest path 1->n is prime
Let's solve this my creating an edge (1, n) of weight 2.

# SOLVED

2) Making sure the MST weight is prime
We need to make sure the shortest path isn't affected.
Let's add edges from n to all the nodes other than 1 with weight 1.
These edges will be part of the MST.
Now the weight of the MST = 2 + (n-2)
If this weight is prime then we are done,
Else we will increment the weight of any of these edges until
the total weight of the MST is prime.

# SOLVED

Now, we need to add the other edges without creating any double edges
or affecting the shortest path/ MST.
To do so, we will add edges of weight larger than 2 and larger than the largest edge in the MST.
The edges will be generated such that they aren't any of the already generated edges.

This can be done by ensuring that neither the source nor the destination of the edge is node (n).

*/
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int no){
	if (no < 2)
		return 0;
	for (long long int i=2;i*i <=no; i++){
		if (no % i ==0)
			return 0;
	}
	return 1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int n,m;
	cin>>n>>m;
	int sp = 2;
	int mst_cost = 2 + (n-2);
	vector< pair< pair<int,int> ,int> > edges(n-1);
	edges[0] = {{1, n}, 2};
	for(int i=2; i<n;i++)
		edges[i-1] = {{n, i}, 1};
	// Find the next prime in range
	// No need to use a sieve here
	while(!is_prime(mst_cost)){
		mst_cost++;
		edges[n-2].second++;
	}

	int max_edge = max(2, edges[n-2].second);
	for (int st=1; st<n && edges.size() < m; st++){
		for(int en=st+1; en<n && edges.size()<m; en++){
			edges.push_back({{st, en}, max_edge+1});
		}
	}

	printf("%d %d\n", sp, mst_cost);
	for(auto p: edges){
		printf("%d %d %d\n", p.first.first, p.first.second, p.second);
	}
	return 0;
}
