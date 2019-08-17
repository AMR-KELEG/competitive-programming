// AC

#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000

#define SHOP 1
#define CUSTOMER 0

// Compressing the x values
set<int> unique_x;
unordered_map<int,int> coordinates_map;

// Segment tree
std::vector<int> segment_tree;
std::vector<int> dirty;

void increment(int & rl, int & rr, int l, int r, int node=1){
	if (l > rr || r <rl)
		return;
	if (dirty[node]){
		segment_tree[node] += (r-l +1) * dirty[node];
		if(l!=r){
			dirty[2*node] += dirty[node];
			dirty[2*node + 1] += dirty[node];
		}
		dirty[node] = 0;
	}
	if (l>=rl && r<=rr)
	{
		segment_tree[node] += (r-l+1);
		if (l!=r)
		{
			dirty[2*node] += 1;
			dirty[2*node+1] += 1;
		}
		return ;
	}
	int mid = (l+r)>>1;
	increment(rl, rr, l, mid, 2*node);
	increment(rl, rr, 1 + mid, r, 2*node + 1);
	segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
}

int query(int l, int r, int node, int & i){
	if(r < i || l > i)
		return 0;
	if(dirty[node]){
		segment_tree[node] += (r-l +1) * dirty[node];
		if(l!=r){
			dirty[2*node] += dirty[node];
			dirty[2*node + 1] += dirty[node];
		}
		dirty[node] = 0;	
	}
	if (r==l)
	{
		return segment_tree[node];
	}
	int mid = (l+r)>>1;
	return query(l, mid, 2*node, i) + query(1 + mid, r, 1 + 2*node, i);
}

int main(){
	freopen("business.in", "r", stdin);
	int T;
	scanf("%d", &T);
	int shops, customers;
	while (T--){
		scanf("%d %d", &shops, &customers);
		unique_x.clear();
		coordinates_map.clear();
		// shops X, Q, R
		std::vector<int> X_s(shops), Q_s(shops), R_s(shops);
		for(int i=0; i< shops; i++){
			scanf("%d %d %d", &X_s[i], &Q_s[i], &R_s[i]);
			unique_x.insert(X_s[i]);
			unique_x.insert(X_s[i] + R_s[i]);
		}
		// customers X, Qmin
		std::vector<int> X_c(customers), Q_c(customers), ans(customers);

		for(int i=0; i< customers; i++){
			scanf("%d %d", &X_c[i], &Q_c[i]);
			unique_x.insert(X_c[i]);
		}

		// Compress the values of X(s)
		int mapped_coord=0;
		for(auto x: unique_x)
		{
			coordinates_map[x] = mapped_coord++;
		}
		int s = coordinates_map.size();
		segment_tree = std::vector<int> (4 * s, 0);
		dirty = std::vector<int> (4 * s, 0);
		priority_queue<pair<int , pair<int, int> > > quality_queue;
		
		int x_min = *(unique_x.begin());
		for (int i=0; i< shops; i++){
			Q_s[i] -= (X_s[i] - x_min);
			quality_queue.push({Q_s[i], {SHOP, i}});
		}
		for(int i=0; i< customers; i++){
			Q_c[i] -= (X_c[i] - x_min);
			quality_queue.push({Q_c[i], {CUSTOMER, i}});
		}

		while(!quality_queue.empty())
		{
			int type = quality_queue.top().second.first;
			int index = quality_queue.top().second.second;
			quality_queue.pop();
			if (type== SHOP){
				int mapped_l = coordinates_map[X_s[index]];
				int mapped_r = coordinates_map[X_s[index] + R_s[index]];
				// The shop of the current quality can serve all customers in range
				// mapped_l -> mapped_r
				increment(mapped_l, mapped_r, 0, coordinates_map.size() -1);
			}
			else
			{
				int mapped_x = coordinates_map[X_c[index]];
				// Find all the shops of quality higher than or equal quality of current
				// that can serve the mapped_x location
				ans[index] = query(0, coordinates_map.size()-1, 1, mapped_x);
			}
		}

		for(int i=0; i< customers; i++){
			printf("%d", ans[i]);
			if(i!=customers-1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
