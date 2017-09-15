//WA
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	long double a,b;
	cin>>a>>b;
	set<long long int>s;
	s.insert(0);
	long double x1,y1,x2,y2,c1,c2;
	bool found=0;
	for(x1=1;x1<=10000 && x1*x1<=(a*a);x1++)
	{
		y1=floor(sqrt((a*a)-(x1*x1)));
		if(s.find(y1)==s.end() && s.find(x1)==s.end() && (a*a)==((x1*x1)+(y1*y1)))
		{
			//check x2,y2
			c1=(b*b)/x1;
			c2=y1/x1;
			long double sqr=((2*c1*c2)*(2*c1*c2))-((4)*(1+(c2*c2))*((c1*c1)-(a*a)-(b*b)));
			if(sqr<0)
				continue;
			sqr=sqrt(sqr);
			y2=((2*c1*c2)+sqr)/(2*(1+(c2*c2)));
			x2=sqrt((a*a)+(b*b)-(y2*y2));
			y2=floor(y2);
			x2=floor(x2);
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			y2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2--;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
		}
		y1++;
		if(s.find(y1)==s.end() && s.find(x1)==s.end() && (a*a)==((x1*x1)+(y1*y1)))
		{
			//check x2,y2
			c1=(b*b)/x1;
			c2=y1/x1;
			long double sqr=((2*c1*c2)*(2*c1*c2))-((4)*(1+(c2*c2))*((c1*c1)-(a*a)-(b*b)));
			if(sqr<0)
				continue;
			sqr=sqrt(sqr);
			y2=((2*c1*c2)+sqr)/(2*(1+(c2*c2)));
			x2=sqrt((a*a)+(b*b)-(y2*y2));
			y2=floor(y2);
			x2=floor(x2);
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			y2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2--;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
		}
	}

	if(found)
	{
		cout<<"YES\n";
		cout<<0<<" "<<0<<endl;
		cout<<x1<<" "<<y1<<endl;
		cout<<x2<<" "<<y2<<endl;
	}
	else
	{
		swap(a,b);
		for(x1=1;x1<=10000 && x1*x1<=(a*a);x1++)
	{
		y1=floor(sqrt((a*a)-(x1*x1)));
		if(s.find(y1)==s.end() && s.find(x1)==s.end() && (a*a)==((x1*x1)+(y1*y1)))
		{
			//check x2,y2
			c1=(b*b)/x1;
			c2=y1/x1;
			long double sqr=((2*c1*c2)*(2*c1*c2))-((4)*(1+(c2*c2))*((c1*c1)-(a*a)-(b*b)));
			if(sqr<0)
				continue;
			sqr=sqrt(sqr);
			y2=((2*c1*c2)+sqr)/(2*(1+(c2*c2)));
			x2=sqrt((a*a)+(b*b)-(y2*y2));
			y2=floor(y2);
			x2=floor(x2);
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			y2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2--;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
		}
		y1++;
		if(s.find(y1)==s.end() && s.find(x1)==s.end() && (a*a)==((x1*x1)+(y1*y1)))
		{
			//check x2,y2
			c1=(b*b)/x1;
			c2=y1/x1;
			long double sqr=((2*c1*c2)*(2*c1*c2))-((4)*(1+(c2*c2))*((c1*c1)-(a*a)-(b*b)));
			if(sqr<0)
				continue;
			sqr=sqrt(sqr);
			y2=((2*c1*c2)+sqr)/(2*(1+(c2*c2)));
			x2=sqrt((a*a)+(b*b)-(y2*y2));
			y2=floor(y2);
			x2=floor(x2);
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			y2++;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
			x2--;
			if(s.find(y2)==s.end() && s.find(x2)==s.end() && (a*a)+(b*b)==(x2*x2)+(y2*y2) && x2!=x1 && x2!=y1 && y2!=x1 && y2!=y1)
			{
				found=1;
				break;
			}
		}
	}
	if(found)
	{
		cout<<"YES\n";
		cout<<0<<" "<<0<<endl;
		cout<<x1<<" "<<y1<<endl;
		cout<<x2<<" "<<y2<<endl;
	}
	else
		cout<<"NO\n";
	}
}