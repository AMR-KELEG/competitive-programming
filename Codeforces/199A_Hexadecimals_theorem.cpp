#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main()
{
	vector<int>fib;
	int max=1E9;
	int f=0,s=1,t;
	fib.push_back(f);
	fib.push_back(s);
	int count=1;
	while(s<=max)
	{
		t=f;
		f=s;
		s+=t;
		fib.push_back(s);
	//	count++;
	}
//	cout<<count;
	int n,a,b,c;
	cin>>n;
	for(int f=0;f<fib.size();f++)
	{
		for(int s=0;s<fib.size();s++)
		{
			for(int t=0;t<fib.size();t++)
			{
				if(fib[f]+fib[s]+fib[t]==n)
				{
					cout<<fib[f]<<" "<<fib[s]<<" "<<fib[t];
					return 0;
				}
			}
		}
	}

		cout<<"I'm too stupid to solve this problem";

	return 0;
}