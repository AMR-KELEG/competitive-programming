//AC
#include <bits/stdc++.h>
using namespace std;
vector<int> devali;
bool is_devali(int val, int pow_ten=6, int cur_sum=0)
{
    if(pow_ten==-1)
        return cur_sum != val;
    if(cur_sum>val)
        return 1;
    //MAX IS 1
    int mult=ceil(pow(10,pow_ten));
    if(cur_sum+(10*mult)-1+(9*(pow_ten+1))<val)
        return 1;
    bool is_dev=true;
    for(int i=0;i<10;i++)
    {
        is_dev=is_dev &&
            is_devali(val, pow_ten-1, cur_sum+(i*(mult+1)));
    }
    return is_dev;
}
void generate_primes()
{
    vector<bool> prime(1000002,1);
    for(int i=4;i<=1000000;i+=2)
        prime[i]=0;
    for(int i=3;i<=1000000;i+=2)
    {
        if(prime[i])
        {
            for(int mult=2;i*mult<=1000000;mult++)
            {
                prime[i*mult]=0;
            }
            // Check prime[i]
            if(is_devali(i))
                devali.push_back(i);
        }
    }
}

int main()
{
    generate_primes();
    int q;
    cin>>q;
    int a,b;
    while(q--)
    {
        cin>>a>>b;
        //find indx1 && indx2
        int indx1 =
            lower_bound(devali.begin(),devali.end(),a)
            -devali.begin();
        int indx2 =
            upper_bound(devali.begin(),devali.end(),b)
            -devali.begin();
        printf("%d\n",indx2-indx1);
    }
}
