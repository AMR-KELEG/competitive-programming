#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        int D;
        string p;
        cin>>D>>p;
        int s=0;
        for (int i=0;i<p.size();i++)
        {
            if (p[i]=='S')
                s++;
        }
        if (s>D)
        {
            cout<<"Case #"<<t<<": IMPOSSIBLE\n";
            continue;
        }
        long long int d =0;
        long long int strength = 1;
        for (int i=0;i<p.size();i++)
        {
            if (p[i]=='S')
                d+=strength;
            else
                strength *=2;
        }
        int swaps = 0;
        int len = p.size();
        while(d>D)
        {
            swaps++;
            // do swap
            while(p[len-1]=='C')
            {
                len--;
            }
            int index = 0;
            strength = 1;
            for (int i=0;i<len;i++)
            {
                if (p[i]=='C')
                {
                    index = i;
                    strength *=2;
                }
            }
            // decrease damage
            swap(p[index], p[index+1]);
            d -= strength/2;
        }
        cout<<"Case #"<<t<<": "<<swaps<<"\n";

    }
}
