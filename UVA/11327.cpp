//AC
#include "bits/stdc++.h"
using namespace std;
vector<long long int> cs(200001,0);
std::vector<bool> isPrime(200001,1);
void prepare()
{
  cs[0]=0; cs[1]=2;
  std::vector<int> totient(200001,1);
  
  for(int i=2;i<200001;i++)
  {
    totient[i]=i;
  }
  
  for(int p=2;p<200001;p++)
  {
    if(isPrime[p])
    {
      totient[p]-=(totient[p]/p);
      for(int mult=2;mult*p<200001;mult++)
      {
        isPrime[mult*p]=0;
        totient[mult*p]-=(totient[mult*p])/p;
      }
    }
  }

  for(int i=2;i<200001;i++)
  {
    cs[i]=cs[i-1]+totient[i];
  }
}


int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  //max is 200000
  prepare();
  long long int ind;
  cin>>ind;
  while(ind!=0)
  {
    int den=lower_bound(cs.begin(), cs.end(),ind)-cs.begin();
    long long int skip=ind-cs[den-1]-1;
    int no=1;
    if(den==1)
    {
      no--;
    }
    while(skip>0)
    {
      if(__gcd(no,den)==1)
      {
        skip--;
      }
      no++;
    }
    while(__gcd(no,den)!=1)
      no++;
    printf("%d/%d\n",no,den );
    // cout<<skip<<endl;

    cin>>ind;
  } 
}