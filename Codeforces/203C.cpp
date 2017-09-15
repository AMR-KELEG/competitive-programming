//Solve it using greedy
//AC
#include "bits/stdc++.h"
using namespace std;

int n,d,a,b;//no and size	
std::vector<long long int> x,y;
std::vector<pair<long long int,int> >user;
std::vector<int> v;

int main()
{
	//std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>d>>a>>b;
	//cout<<n<<endl;
	user.resize(n+1);
	user[0]=pair<long long int,int>(10000000000LL,0);		
	int tx,ty;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tx);
		scanf("%d",&ty);
		user[i]=pair<long long int,int>((a*tx)+(b*ty),i);		
	}
	sort(user.begin(), user.end());
	//cout<<"Start\n";
	int index=0;
	while(index<n)
	{
		if(d>=user[index].first)
		{
			d-=user[index].first;
			v.push_back(user[index].second);
		}
		else
			break;
		index++;
	}
	cout<<v.size()<<endl;
	for(int  i=0;i<v.size();i++)
		printf("%d ", v[i]);
}