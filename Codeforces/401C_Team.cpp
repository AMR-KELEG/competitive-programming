#include "iostream"
#include "cmath"
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	//swap(n,m);
	if(m<n-1 || m>(2*n)+2)
	{
		cout<<-1;
	}
	else
	{	
		if(n==1)
		{
			cout<<string(ceil(m/2.0),'1')<<"0"<<string(m/2,'1');
		}
		else if(m<(2*n)-2)
		{
			int numdou=m-(n-1);
			int numsin=(2*n)-2-m;
			
			for(int i=0;i<numdou;i++)
				cout<<"011";
			for(int i=0;i<numsin;i++)
				cout<<"01";
			cout<<"0";
				
		}
		else if(m<(2*n))
		{
			int numdou=m-(n);
			int numsin=(2*n)-m;
			
			
			//5 potions
			for(int i=0;i<numdou;i++)
				cout<<"110";
			for(int i=0;i<numsin;i++)
				cout<<"10";
		}
		else
		{
			
			int numdou=m-(n+1);
			int numsin=(2*n)+2-m;
			//cout<<numdou<<" sing:"<<numsin<<endl;
			for(numdou;numdou>1;numdou--)
				cout<<"110";
			for(numsin;numsin>1;numsin--)
				cout<<"10";
				
			if(numsin>0 && numdou>0)
			{
				cout<<"1011";
			}
			else if(numsin>0)
			{
				cout<<"1";
			}
			else if(numdou>0)
			{
				cout<<"11";
			}
			
				
		}

	}

	return 0;
}