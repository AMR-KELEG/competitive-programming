/* AC
Preprocessing to find indx of certain char after cur_indx
*/
#include "bits/stdc++.h"
using namespace std;

bool char_av[26];
int indx_of_next[10000][26];
string s1,s2;

// recieve s1
int solve(int indx1, int indx2)
{
	if (indx1==s1.size())
		return 1;
	if (indx2>=s2.size())
		return 1+solve(indx1, 0);
	if (indx_of_next[indx2][s1[indx1]-'a'] !=-1)
		return solve(indx1+1, indx_of_next[indx2][s1[indx1]-'a']+1);
	return 1 + solve(indx1, 0);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(indx_of_next, -1, sizeof indx_of_next);
	cin>>s1>>s2;
	swap(s1,s2);
	for (auto c:s2)
		char_av[c-'a'] = 1;
	for (auto c:s1)
	{
		if (!char_av[c-'a'])
		{
			printf("%d\n", -1);
			return 0;
		}
	}
	// solve
	for (int i=s2.size()-1;i>=0;i--)
	{
		for (int j=i;j>=0;j--)
		{
			indx_of_next[j][s2[i]-'a'] = i;
		}
	}
	printf("%d\n", solve(0,0));
	
}