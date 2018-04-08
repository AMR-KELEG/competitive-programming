#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<int>v1(ceil(0.5*n));
        vector<int>v2(0.5*n);
        for (int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            if (i%2==0)
            {
                v1[i/2] = val;
            }
            else
            {
                v2[i/2] = val;
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> v(n);
        for (int i=0;i<n;i++)
        {
            if (i%2==0)
            {
                v[i]= v1[i/2];
            }
            else
            {
                v[i]= v2[i/2];
            }
        }
        int bad_index = -1;
        for (int i=0;i<n-1;i++)
        {
            if (v[i]>v[i+1])
            {
                bad_index=i;
                break;
            }
        }
        if (bad_index==-1)
        {
            cout<<"Case #"<<t<<": OK\n";
        }
        else
        {
            cout<<"Case #"<<t<<": "<<bad_index<<"\n";
        }
    }
}
