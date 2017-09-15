#include "bits/stdc++.h"
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	string num[7],same[7];
	num[1]="Yakk";
	num[2]="Doh";
	num[3]="Seh";
	num[4]="Ghar";
	num[5]="Bang";
	num[6]="Sheesh";
	same[1]="Habb Yakk";
	same[2]="Dobara";
	same[3]="Dousa";
	same[4]="Dorgy";
	same[5]="Dabash";
	same[6]="Dosh";
	int T,a,b;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>a>>b;
		if(a==b)cout<<"Case "<<i<<": "<<same[a]<<endl;
		else if (max(a,b)==6 && min(a,b)==5)cout<<"Case "<<i<<": "<<"Sheesh Beesh"<<endl;
		else cout<<"Case "<<i<<": "<<num[max(a,b)]<<" "<<num[min(a,b)]<<endl;
	}	

	return 0;
}