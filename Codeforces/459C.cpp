//AC
//String wasn't good
#include "bits/stdc++.h"
using namespace std;
std::vector<std::vector<int> > students;
int n,b,d;
void next_st(std::vector<int> s,int i)
{
	if(i<0)
	{
		return ;
	}
	if(students.size()>=n)
		return ;
	s[i]++;
	if(s[i]>b)
	{
		s[i]=1;
		next_st(s,i-1);
		return ;
	}
	students.push_back(s);
	next_st(s,d-1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// n students k buses d days
	cin>>n>>b>>d;
	students.push_back(std::vector<int> (d,1));
	next_st(std::vector<int> (d,1),d-1);
	if(students.size()>=n)
	{
		for(int day=0;day<d;day++)
		{
			for(int st=0;st<n;st++)
			{
				cout<<students[st][day]<<" ";
			}
			cout<<endl;
		}
	}
	else
		cout<<-1;
}