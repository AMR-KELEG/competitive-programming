//AC FINALLY
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	//make an array - sort -reverse - make a count of the current number - move the last number iterator until op>k 
	std::vector<int> numbers(n);
	for(int i=0;i<n;i++)
	{
		cin>>numbers[i];
	}	
	sort(numbers.begin(), numbers.end());
	/*
	for(int i=0;i<n;i++)
		cout<<numbers[i]<<" ";
	cout<<endl;
	*/
	numbers.push_back(numbers[numbers.size()-1]);
	int count=1,maxcount=1,maxnu=numbers[n-1],op=0;
	int i=n-1;
	while(i>0)
	{
		if(numbers[i]==numbers[i-1])
		{
			count++;
			i--;
		}
		else
			break;
	}
	int last=n-2,current=n-1,currentcount=0;
	while(current>=0 && last>-1)
	{
		op+=(count-currentcount)*(numbers[current]-numbers[current+1]);
		count=current-last;
		//cout<<count<<endl;
		currentcount=1;
		while(current>0)
		{
			if(numbers[current]==numbers[current-1])
			{
				current--;
				if(last==current)
				{
					count++;
					last--;
				}
				currentcount++;
				if(count>=maxcount)
				{
					maxcount=count;
					maxnu=numbers[current];
				}
			}
			else 
				break;
		}
		if(current==0 && last==-1)
		{
			count=currentcount;
		}
		if(count>=maxcount)
		{
			maxcount=count;				
			maxnu=numbers[current];
		}
		//cout<<"Current number "<<numbers[current]<<" current count "<<currentcount<<" total count "<<count<<endl;
		while(last>=0)
		{
			//cout<<op<<" "<<numbers[current]<<" "<<numbers[last]<<endl;
			if(k-op-(numbers[current]-numbers[last])>=0)
			{
				op+=numbers[current]-numbers[last];
				count++;
				last--;
				if(count>=maxcount)
				{
					maxcount=count;
					maxnu=numbers[current];
				}
			}
			else
				break;
		}
		//cout<<numbers[current]<<" "<<count<<" op "<<op<<" "<<maxcount<<endl;
		current--;
		if(last==current)
			last--;
		//cout<<numbers[last]<<endl;
	}
	/*
	*/
	cout<<maxcount<<" "<<maxnu;
}