#include <bits/stdc++.h>
using namespace std;
struct node
{
	node * children[26];
	node()
	{
		for(int i=0;i<26;i++)
			children[i]=0;
	}
};
std::vector<int> badcs;
string s;
node * root=new node();
char good[26];
int counter=0;
int k;
void addtotrie(int st,int en)
{
	node* it=root;
	int i=st;
	while(i<=en)
	{
		if(it->children[s[i]-'a']==NULL)
		{
			//
			node * tem=new node();
			it->children[s[i]-'a']=tem;
			it=it->children[s[i]-'a'];
			i++;
			counter++;
			while(i<=en)
			{
				counter++;
				node * t=new node();
				it->children[s[i]-'a']=tem;
				it=it->children[s[i]-'a'];
				i++;
			}
			return ;
		}
		it=it->children[s[i]-'a'];
		i++;
	}
}
void formsubstrings(int st,int en,bool addall=0)
{
	for(int sst=st;sst<=en;sst++)
	{
		for(int sen=sst;sen<=en;sen++)
		{
			int b=badcs[sen]-badcs[sst]+!good[s[sst]-'a'];
			if(b==k)
				addtotrie(sst,sen);
			else
				break;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	cin>>s;
	for(int i=0;i<26;i++)
	{
		cin>>good[i];
		good[i]-='0';
	}
	cin>>k;
	badcs=std::vector<int> (int(s.size()),0);
	badcs[0]=!good[s[0]-'a'];
	for(int i=1;i<s.size();i++)
		badcs[i]=badcs[i-1]+!good[s[i]-'a'];
	if(badcs[s.size()-1]<k)
		formsubstrings(0,int(s.size())-1,1);
	else
		formsubstrings(0,int(s.size())-1,0);
	cout<<counter;
	return 0;
}