//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  std::vector<long long int> answers(1,1); 
  long long int n=2;
  long long int curAns=1;
  while(curAns<4294967295LL)
  {
    curAns*=(2*n)*((2*n)-1);
    curAns/=n;
    curAns/=n+1;
    answers.push_back(curAns);
    n++;
  }
  while(cin>>n)
  {
    cout<<1+lower_bound(answers.begin(), answers.end(),n)-answers.begin()<<"\n";
  }

}