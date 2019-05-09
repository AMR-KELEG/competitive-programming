// AC
#include <bits/stdc++.h>
using namespace std;

// final is 2, 3
string s;
int fx, fy;
int cx=0, cy=0;
std::vector<int> cr, cl, cu, cd; // length = n+1
bool validate(int len)
{
	for (int start=0; start<=s.size()-len; start++){
		// range from 0 to len-1
		// from 0 to 2
		// cs[2] - cs[-1]
		// cs[3] - cs[0]
		int r = cr[start+len] - cr[start];
		int l = cl[start+len] - cl[start];
		int u = cu[start+len] - cu[start];
		int d = cd[start+len] - cd[start];
		int current_x = cx - r + l;
		int current_y = cy - u + d;
		int required_operations = abs(fx - current_x) + abs(fy - current_y);
		if (required_operations <= len && ((required_operations - len) %2 == 0))
			return 1;
	}
	return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n>>s>>fx>>fy;
	cr = std::vector<int> (n+1, 0);
	cl = std::vector<int> (n+1, 0);
	cu = std::vector<int> (n+1, 0);
	cd = std::vector<int> (n+1, 0);
	for (int i=0; i<s.size(); i++)
	{
		cr[i+1] = cr[i];
		cl[i+1] = cl[i];
		cu[i+1] = cu[i];
		cd[i+1] = cd[i];
		if (s[i] == 'R')
			cr[i+1]++;
		else if(s[i] == 'L')
			cl[i+1]++;
		else if(s[i] == 'U')
			cu[i+1]++;
		else
			cd[i+1]++; 
	}
	cx = cr[s.size()] - cl[s.size()];
	cy = cu[s.size()] - cd[s.size()];
	if (cx == fx && cy == fy){
		cout<<0;
		return 0;
	}
	int l = 1;
	int r = n;
	int mid = (l+r)>>1;
	while(l<r){
		if (validate(mid))
		{
			r = mid;
		}
		else
		{
			l = mid+1;
		}
		mid = (l+r)>>1;
	}
	if (l>r || !validate(mid))
		cout<<-1;
	else
		cout<<((l+r)>>1);
	// cout<<s<<endl;
}