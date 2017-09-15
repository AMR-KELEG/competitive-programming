//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k,p;
	cin>>n>>k>>p;
	std::vector<int> odd,even;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		if(no%2)
		{
			odd.push_back(no);
		}
		else
		{
			even.push_back(no);
		}
	}	
	int o=odd.size();
	int ev=even.size();
	// cout<<o<<" "<<k-p<<endl;
	// cout<<o-(k-p)%2<<endl;
	// cout<<ev+((o-(k-p))/2)<<" "<<p<<endl;
	if(k-p<=o && (o-(k-p))%2==0 && ev+((o-(k-p))/2)>=p)
	{
		int oddin=0,evenin=0;
		printf("YES\n");
		// cout<<k-p-1<<endl;
		for(int i=0;i<k-p-1;i++)
		{
			printf("1 %d\n", odd[oddin++]);
			// cout<<"NO";
		}
		if(p==0)
		{
			// printf("%d\n",(int)odd.size()-oddin);
			// printf("HERE\n");
			if(((int)odd.size()-oddin+ev)>0)
			{
				printf("%d %d ", (int)odd.size()-oddin+1+ev ,odd[oddin++]);
				for(int j=oddin;j<odd.size();j++)
				{ 
					printf("%d ", odd[oddin++]);
				}
				for(int i=0;i<ev;i++)
					printf("%d ", even[evenin++]);	
				printf("\n");
			}
		}
		else if(k-p-1>=0)
		{
			printf("1 %d\n", odd[oddin++]);	
		}

		for(int i=0;i<p-1;i++)
		{
			if(evenin==even.size())
			{
				// take 2 odds
				printf("2 %d %d\n", odd[oddin++] , odd[oddin++]);
			}
			else
			{
				printf("1 %d\n", even[evenin++]);	
			}
		}
		if(int(odd.size()-oddin+even.size()-evenin)>0)
		{
			printf("%d",int(odd.size()-oddin+even.size()-evenin));
			for(int j=oddin;j<odd.size();j++)
				printf(" %d",odd[j]);

			// printf("\n%d %d\n", evenin,(int)even.size());
			for(int j=evenin;j<even.size();j++)
				printf(" %d",even[j]);
		}

	}
	else
	{
		cout<<"NO";
	}
	// if(-1)
	// 	printf("neg\n");
}