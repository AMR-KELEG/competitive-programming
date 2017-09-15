#include "bits/stdc++.h"
using namespace std;
int n,p;
string s;

//make me in a palindrome of 2 or 3 only
//how to make string? s[index] & s[index-1]
// pattern is a b c 
// a b -> c a b
// a c -> b a c
// b a -> c b a
// b c -> 
// c a
// c b
bool findnext(int index)
{
  //cout<<index<<" "<<s[index]<<endl;
  if(index==0)
  { 
    s[index]++;
    if(s[index]=='a'+p)
    {
      return 0;
    }
    int pat[3]={0,1,2};
    if(s[index]<='c')
    {
       pat[2]=s[index]-'a';
       pat[1]=ceil((4-pat[2])/2.0);
       pat[0]=3-pat[1]-pat[2];
    }
    for(int i=index+1,j=0;i<s.size();i++,j=(j+1)%3)
    {
      s[i]=pat[j]+'a';
    }
    return 1;
  }
  if(index==1)
  {
    s[index]++;
    //cout<<s[index]<<" "<<char('a'+p)<<endl;
    if(s[index]=='a'+p)
    {
      return findnext(0);
    }
    if(s[index]==s[0])
    {
     return findnext(1); 
    }
    //cout<<s<<endl;
    int pat[3]={0,1,2};
    if(s[index-1]<='c')
    {
      if(s[index]<='c')
      {
        pat[2]=s[index]-'a';
        pat[1]=s[index-1]-'a';
        pat[0]=3-pat[1]-pat[2];
      }
      else
      {
        pat[1]=min(1,s[index-1]-'a');
        pat[2]=ceil((4-pat[1])/2.0);
        pat[0]=3-pat[1]-pat[2];
      }
      
    }
    else
    {
      if(s[index]<='c')
      {
        pat[2]=s[index]-'a';
        pat[1]=ceil((4-pat[2])/2.0);
        pat[0]=3-pat[1]-pat[2];
      }
    }
    
    for(int i=index+1,j=0;i<s.size();i++,j=(j+1)%3)
    {
      s[i]=pat[j]+'a';
    }
    return 1;
  }

  s[index]++;
  if(s[index]>='a'+p)
  {
    return findnext(index-1);
  }
  if(s[index]!=s[index-1] && s[index]!=s[index-2])
  {
    int pat[3]={0,1,2};
    if(s[index-1]<='c')
    {
      if(s[index]<='c')
      {
        pat[2]=s[index]-'a';
        pat[1]=s[index-1]-'a';
        pat[0]=3-pat[1]-pat[2];
      }
      else
      {
        pat[1]=min(1,s[index-1]-'a');
        pat[2]=ceil((4-pat[1])/2.0);
        pat[0]=3-pat[1]-pat[2];
      }
      
    }
    else
    {
      if(s[index]<='c')
      {
        pat[2]=s[index]-'a';
        pat[1]=ceil((4-pat[2])/2.0);
        pat[0]=3-pat[1]-pat[2];
      }
    }
    
    for(int i=index+1,j=0;i<s.size();i++,j=(j+1)%3)
    {
      s[i]=pat[j]+'a';
    }
    return 1;
  }
  return findnext(index);
}
int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  cin>>n>>p;
  cin>>s;
  if(p==1)
  {
    cout<<"NO";
  } 
  else if(p==2)
  {
    if(findnext(s.size()-1))
      cout<<s;
    else
      cout<<"NO";
  }
  else
  {
    //abc 
    if(findnext(s.size()-1))
      cout<<s;
    else
      cout<<"NO";
  }
}