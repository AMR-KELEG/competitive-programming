#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif	
	int T;
	cin>> T;
	string names [] = {"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
	string same [] = {"", "Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh"};
	for (int t=1;t<=T;t++)
	{
		cout<<"Case "<<t<<": ";
		int a,b;
		cin>>a>>b;
		if (a<b)
			swap(a,b);
		if (a == b)
		{
			cout<<same[a]<<"\n";
		}
		else if (a==6 && b==5)
		{
			cout<<"Sheesh Beesh\n";
		}
		else
		{
			cout<<names[a]<<" "<<names[b]<<"\n";
		}
	}
}