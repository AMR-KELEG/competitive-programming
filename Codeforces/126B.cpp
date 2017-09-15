#include "bits/stdc++.h"
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n,0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    // for(int i=0;i<n;i++)
    //     cout<<z[i]<<" ";
    // cout<<endl;
    return z;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	std::vector<int> z=z_function(s);
    if(s.size()==1)
    {
        cout<<s[0];
        return 0;
    }
    int l=10000000LL;
    int c=0;
    for(int i=1;i<s.size();i++)
    {
        if(z[i]!=0)
        {
            c++;
            l=min(l,z[i]);
        }
    }

    if(l==10000000LL && c>=2)
        cout<<"Just a legend";
    else
        cout<<s.substr(0,l);
}

