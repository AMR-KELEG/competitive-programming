#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;
string third(string ans)
{
    if(ans[0]==ans[1])
        return ans.substr(1);
    if(ans.find('R')!=-1 && ans.find('G')!=-1)
        return "B";
    if(ans.find('B')!=-1 && ans.find('G')!=-1)
        return "R";
        return "G";
}
string third(char a,char b)
{
    string ans=string(1,a)+string(1,b);
    if(ans[0]==ans[1])
        return ans.substr(1);
    if(ans.find('R')!=-1 && ans.find('G')!=-1)
        return "B";
    if(ans.find('B')!=-1 && ans.find('G')!=-1)
        return "R";
        return "G";
}
string third(string a,string b)
{
    string ans=a+b;
    if(ans[0]==ans[1])
        return ans.substr(1);
    if(ans.find('R')!=-1 && ans.find('G')!=-1)
        return "B";
    if(ans.find('B')!=-1 && ans.find('G')!=-1)
        return "R";
        return "G";
}
int main() {
    #ifndef ONLINE_JUDGE
	   freopen("in.txt","r",stdin);
    #endif
	std::ios::sync_with_stdio(false);
    int n;
    
    cin>>n;
    string s;
    cin>>s;
    int cg=0,cb=0,cr=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='R')
            cr++;
        if(s[i]=='G')
            cg++;
        if(s[i]=='B')
            cb++;
    }    
    if(n>3)
    {
        if(cb>1)
            cb=1;
        if(cr>1)
            cr=1;
        if(cg>1)
            cg=1;
    }
    set<string>last;
    string ans=string(cr,'R')+string(cg,'G')+string(cb,'B');
    if(ans.size()==1)
        cout<<ans;
    else if(ans.size()==2)
    {
        if(ans[0]==ans[1])
            cout<<ans[0];
        else
            cout<<third(ans);
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=i+1;j<3;j++)
            {
                last.insert(third(third(ans[i],ans[j]),string(1,ans[3-(i+j)])));
            }
        }
        set<string>::iterator it;
        for(it=last.begin();it!=last.end();it++)
            cout<<*it;
    }
    return 0;
}
