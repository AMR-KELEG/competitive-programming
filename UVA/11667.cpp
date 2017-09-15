//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int M,Min,Max;
	cin>>M>>Min>>Max;
	int t=0;
	while (M!=0)
	{
		t++;
		cout<<"Case "<<t<<": ";
		if (M<=Min)
		{
			cout<<fixed<<setprecision(2)<<0.0<<"\n";
		}
		else if(M>=Max)
		{
			// OK - right
			long double C0 = 0.2*M*(Max+1) -0.5*0.1*(Max)*(Max+1);
			long double C1 = -0.2*M -0.1*(Max+1) -0.1*0.5;
			long double C2 = 0.1 + 0.1*0.5;
			long double ans = C0 * (Max+1-Min);
			ans += 0.5* C1* ((Max*(Max+1))-(Min*(Min-1)));
			ans += (1/6.0)* C2* ((Max*(Max+1)*(2*Max+1))-(Min*(Min-1)*(2*Min-1)));
			long double ways = (Max+1) * (Max+1- Min);
			ways += -0.5 * ((Max * (Max+1))-(Min * (Min-1)));
			cout<<fixed<<setprecision(2)<<ans/ways<<"\n";
		}
		else
		{
			// s2<= M
			long double C0 = 0.2*M*(M+1) -0.5*0.1*(M)*(M+1);
			long double C1 = -0.2*M -0.1*(M+1) -0.1*0.5;
			long double C2 = 0.1 + 0.1*0.5;
			long double ans = C0 * (M+1-Min);
			ans += 0.5* C1* ((M*(M+1))-(Min*(Min-1)));
			ans += (1/6.0)* C2* ((M*(M+1)*(2*M+1))-(Min*(Min-1)*(2*Min-1)));

			// s2 > M
			ans += 0.1 * M * (Max - M)* (M+1 - Min);
			ans += -0.1 * (Max - M)*0.5* ((M*(M+1)) - (Min*(Min-1)));
			long double ways = (Max+1) * (Max+1- Min);
			ways += -0.5 * ((Max * (Max+1))-(Min * (Min-1)));
			cout<<fixed<<setprecision(2)<<ans/ways<<"\n";
		}
		cin>>M>>Min>>Max;
	}	
}