#include  "bits/stdc++.h"
using namespace std;
int main()
{
	double x1,y1,x2,y2;
	double vx,vy,wx,wy;
	double vmax,t,current_t,deltax,deltay,dis;
	double vship,b,c;
	cin>>x1>>y1>>x2>>y2;
	cin>>vmax>>t;
	cin>>vx>>vy>>wx>>wy;
	vx=-vx;
	vy=-vy;
	wx=-wx;
	wy=-wy;
	deltax=x2-x1;
	deltay=y2-y1;
	dis=((deltax)*(deltax))+((deltay)*(deltay));
	dis=sqrt(dis);
	b=(2*vx*deltax)+(2*vy*deltay);
	b=b/dis;
	c=(vx*vx)+(vy*vy)-(vmax*vmax);
	vship=-b;
	vship+=sqrt((b*b)-(4*c));
	vship/=2;
	double vshipx,vshipy;
	vshipx=vship*deltax;
	vshipx/=dis;
	vshipy=vship*deltay;
	vshipy/=dis;
	if((x2-x1)/vshipx-t<-0.000001)
	{
		//end here
		cout<<(x2-x1)/vshipx;
		return 0;
	}
	x1=x1+(vshipx*t);
	y1=y1+(vshipy*t);
	b=(2*wx*deltax)+(2*wy*deltay);
	b=b/dis;
	c=(wx*wx)+(wy*wy)-(vmax*vmax);
	vship=-b;
	vship+=sqrt((b*b)-(4*c));
	vship/=2;
	vshipx=vship*deltax;
	vshipx/=dis;
	vshipy=vship*deltay;
	vshipy/=dis;
	cout<<t+((x2-x1)/vshipx);
	return 0;


}