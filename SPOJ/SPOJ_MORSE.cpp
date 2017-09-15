//AC

#include "bits/stdc++.h"
using namespace std;
string a[26];
int dp[10001];
int vis[10001];
int curTest=0;
string word;
void make_array()
{
  a[0]=".-";
  a[1]="-...";
  a[2]="-.-.";
  a[3]="-..";
  a[4]=".";
  a[5]="..-.";
  a[6]="--.";
  a[7]="....";
  a[8]="..";
  a[9]=".---";
  a[10]="-.-";
  a[11]=".-..";
  a[12]="--";
  a[13]="-.";
  a[14]="---";
  a[15]=".--.";
  a[16]="--.-";
  a[17]=".-.";
  a[18]="...";
  a[19]="-";
  a[20]="..-";
  a[21]="...-";
  a[22]=".--";
  a[23]="-..-";
  a[24]="-.--";
  a[25]="--..";
}

struct node
{
  int Words;
  node*  hasDash;
  node* hasDot;
  node()
  {
    Words=0;
    hasDot=hasDash=nullptr;
  }
};

void deletenode(node * n)
{
  if(n==nullptr)
    return ;
  deletenode(n->hasDash);
  deletenode(n->hasDot);
  delete n;
}

node * root;
void addToTrie(string & s)
{
  node * curnode=root;
  for(int in=0;in<s.size();in++)
  {
    if(s[in]=='-')
    {
      if(curnode->hasDash!=nullptr)
      {
        curnode=curnode->hasDash;
      }
      else
      {
        node * tem=new node();
        curnode->hasDash=tem;
        in++;
        curnode=tem;
        while(in<s.size())
        {
          if(s[in]=='-')
          {
            node * tem2=new node();
            curnode->hasDash=tem2;
            in++;
            curnode=tem2;
          }
          else
          {
            node * tem2=new node();
            curnode->hasDot=tem2;
            curnode=tem2; 
            in++;
          }
        }
      }
    }
    else
    {
      if(curnode->hasDot!=nullptr)
      {
        curnode=curnode->hasDot;
      }
      else
      {
        node * tem=new node();
        curnode->hasDot=tem;
        curnode=tem;
        in++;
        while(in<s.size())
        {
          if(s[in]=='-')
          {
            node * tem2=new node();
            curnode->hasDash=tem2;
            in++;
            curnode=tem2;
          }
          else
          {
            node * tem2=new node();
            curnode->hasDot=tem2;
            curnode=tem2; 
            in++;
          }
        }
      } 
    }
  }
  curnode->Words++;
}

string convert(string & s)
{
  string ans;
  for(int i=0;i<s.size();i++)
  {
    ans+=a[s[i]-'A'];
  }
  return ans;
}

int solve(int i)
{
  if(i==word.size())
    return 1;
  if(i>word.size())
    return 0;
  if(vis[i]==curTest)
    return dp[i];
  vis[i]=curTest;  
  int ans=0;
  stack<pair<node *,int> >st;
  st.push({root,i});
  while(!st.empty())
  {
    node * curnode=st.top().first;
    int in=st.top().second;
    st.pop();
    if(curnode->Words)
    {
      ans+=(curnode->Words)*solve(in);
    }

    if(in<word.size() && word[in]=='-' && curnode->hasDash!=nullptr)
    {
      st.push({curnode->hasDash,in+1});
    }
    else if(in<word.size() && word[in]=='.' && curnode->hasDot!=nullptr)
    {
      st.push({curnode->hasDot,in+1});
    }
  }
  return dp[i]=ans;
}



int main()
{
  std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  make_array();
  int t;
  cin>>t;
  string s,tem;
  while(t--)
  {
    cin>>word;
    root=new node();
    curTest++;
    int n;
    cin>>n;
    //10000 * 20 * 5 =10^7 Char in the trie
    for(int i=0;i<n;i++)
    {
      cin>>s;
      tem=convert(s);
      addToTrie(tem);
    }
    cout<<solve(0)<<endl;
    if(t)
      cout<<endl;
    deletenode(root);
  }
}