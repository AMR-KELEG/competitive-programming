//AC
#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	set<int>uniqueValues;
	for(int i=0,val;i<n;i++)
	{
		scanf("%d",&val);
		uniqueValues.insert(val);
	}
	n=uniqueValues.size();
	std::vector<int> v(n);
	int in=0;
	for(auto val:uniqueValues)
	{
		v[in]=val;
		in++;
	}
	sort(v.begin(), v.end());
	int lower[2000001]={};
	int curIndx=0;
	int curVal=0;
	for(int i=1;i<=2000000;i++)
	{
		if(curIndx<n-1 && v[curIndx+1]<=i)
		{
			curIndx++;
			curVal=v[curIndx];
		}
		lower[i]=curVal;
	}
	int ans=0;
	//Choose aj -- ai % aj=?
	for(int in=0;in<n-1;in++)
	{
		int aj=v[in];
		for(int mul=2;mul*aj<=2000000;mul++)
		{
			int lowerVal=lower[(mul*aj)-1];
			ans=max(ans,lowerVal%aj);
		}
	}
	cout<<ans;
	return 0;
}