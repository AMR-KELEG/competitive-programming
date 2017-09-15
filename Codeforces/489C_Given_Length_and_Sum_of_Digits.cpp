// #include "bits/stdc++"
#include <iostream>
using namespace std;
int main()
{
	int m,s;
	string min_nu;
	cin>>m>>s;
	for(int i=0;i<m && s>0;i++)
	{
		if(s>=9)
		{
			s-=9;
			min_nu=char('0'+9)+min_nu;
		}
		else
		{
			min_nu=char('0'+s)+min_nu;
			s=0;
		}
	}
	return 0;
}