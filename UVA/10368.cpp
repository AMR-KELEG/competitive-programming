/* AC
Game Theory - GCD 
*/
#include "bits/stdc++.h"
using namespace std;
bool solve(int a,int b)
{
	if (b==0)
		return 0;
	if (b==1 || a==b)
		return 1;
	int na = a%b;
	if (!solve(b,na))
		return 1;
	int mult = a/b;
	if (mult>1)
		return 1;
	return 0;

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b;
	cin>>a>>b;
	while(a>0 && b>0)
	{
		if (a<b)
			swap(a,b);
		if (solve(a,b))
		{
			printf("Stan wins\n");
		}
		else
			printf("Ollie wins\n");
		cin>>a>>b;
	}
}