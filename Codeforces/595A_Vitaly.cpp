#include "iostream"
using namespace std;
int main()
{
int n,m,awake=0;
bool w1,w2;
cin>>n>>m;
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
cin>>w1>>w2;
awake+=(w1||w2);
}
}
cout<<awake;
return 0;
}