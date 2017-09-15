#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int>cells;
int n;
//longest equal -- longest increasing -- longest decreasing -- longest equal
// next step start from longest_increasing
int increasing_lasti(int s)//endit is n-1
{
	int i;
	for(i=s+1;i<n;i++)
	{
		if(cells[i]<cells[i-1])
			return i-1;
	}
	return n;
}
int decreasing_lasti(int s)//endit is n-1
{
	int i;
	for(i=s+1;i<n;i++)
	{
		if(cells[i]>=cells[i-1])
			return i-1;
	}
	return n;
}
int equal_lasti(int s)//endit is n-1
{
	int i;
	for(i=s+1;i<n;i++)
	{
		if(cells[i]!=cells[i-1])
			return i-1;
	}
	return n;
}


int main()
{
	cin>>n;
	cells.assign(n);
	int max_d=0,current_d=0;
	for(int i=0;i<n;i++)
		cin>>cells[i];
	int start;
	int temp;
	for(int i=0;i<n;i++)
	{
		i=start=equal_lasti(i);
		while(1)
		{
			
		}
		
	}
	
	cout<<max_d;
	return 0;
}