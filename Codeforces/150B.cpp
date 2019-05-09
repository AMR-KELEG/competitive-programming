/*AC
- n^2 constraints can be generated from
all the palindromes of length k.
- Disjoint set is used to merge the
constraints.
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> par;

int find(int a){
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void join(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if (pa==pb) return;
	par[pa] = pb;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif
	int str_len, alphabet_char, substr_len;
	cin>>str_len>>alphabet_char>>substr_len;
	par = vector<int>(str_len);
	for (int i=0; i<str_len; i++) par[i] = i;

	for (int st=0; st<str_len-substr_len+1; st++){
		for (int indx=0; indx< substr_len/2; indx++){
			if (st+indx >= str_len)
				continue;
			if (st+substr_len -1 - indx >= str_len)
				continue;
			join(st+indx, st + substr_len - 1 - indx);
		}
	}
	set<int> unique_components;
	for (int i=0; i< str_len; i++)
		unique_components.insert(find(i));
	// find m ^ unique_components
	long long int ans = 1;
	for (int i=0; i<unique_components.size(); i++){
		ans = (ans * alphabet_char) % MOD;
	}
	cout<<ans;
}
