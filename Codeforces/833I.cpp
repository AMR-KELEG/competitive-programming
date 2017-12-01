// AC
#include <bits/stdc++.h>
using namespace std;
std::vector<int> cont;
int n,k;
bool valid(int off)
{
	std::vector<bool> valid(n,0);
	queue<int>q;
	q.push(n);
	for (int i=n-k;i>=0;i--)
	{
		int j = upper_bound(cont.begin()+i,cont.end(),cont[i]+off) - cont.begin();
		if (j>n || (j<n && cont[j]>cont[i]+off))
			j--;
		int cur_s = (j-i+1);
		if (cur_s<k)
			valid[i] = 0;
		else
		{
			while(!q.empty() && q.front()>j+1)
				q.pop();
			if (!q.empty() && q.front()>=i+k)
			{
				q.push(i);
				valid[i] = 1;
			}
		}
	}
	return valid[0];
}

int main()
{
	cin>>n>>k;
	cont = std::vector<int> (n);
	for (int i=0;i<n;i++)
	{
		cin>>cont[i];
	}
	sort (cont.begin(), cont.end());
	int l = 0,r=1000000000;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if (valid(mid))
		{
			r= mid;
		}
		else
		{
			l = mid+1;
		}
	}
	int ans = (l+r)>>1;
	cout<<ans;
	return 0;
}