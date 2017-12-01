// WA
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define rot(a,th) a * exp(Point(0,1)*th)

// class Point {
// 	public :
// 	double X;
// 	double Y;
// 	Point(double x,double y)
// 	{
// 		this->X=x;
// 		this->Y=y;			
// 	}
// };
#define EPS 0.0000001
#define ADD 1e-9
void output(Point P)
{
	long double x = P.X;
	long double y = P.Y;
	x = round(x*1000000)/1000000;
	y = round(y*1000000)/1000000;
	if (abs(x)<=EPS)
		x=0;
	if (abs(y)<=EPS)
		y=0;
	x += ADD;
	y += ADD;
	cout<<fixed<<setprecision(6)<<x<<" "<<y<<endl;
}

Point polyginCentroid(vector<Point> &polygon) {
	long double a = 0;
	long double x = 0;
	long double y = 0;
	//cout<<polygon.size()<<endl;
	for (int i = 0; i < (int) polygon.size(); i++) {
		int j = (i + 1) % polygon.size();
		long double dx = (polygon[i].X + polygon[j].X) * (polygon[i].X* polygon[j].Y- polygon[j].X * polygon[i].Y);
		long double dy = (polygon[i].Y + polygon[j].Y) * (polygon[i].X* polygon[j].Y- polygon[j].X * polygon[i].Y);
		x += dx;
		y += dy;
		a += polygon[i].X * polygon[j].Y - polygon[i].Y *polygon[j].X;
		//cout<<a<<endl;
	}
	
	Point res(x, y);
	a *= 0.5;
	res /= 6 * a;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	int N,x,y;
	vector<Point>polygon;
	for(int i=1;i<=T;i++)
	{
		polygon.clear();
		cin>>N;
		// //cout<<N<<endl;
		for(int j=0;j<N;j++)
		{
			cin>>x>>y;
			polygon.push_back(Point(x,y));
		}		
		Point center=polyginCentroid(polygon);
		long double angle = arg(center);
		long double rotation_angle = -angle - acos(0);
		// Point new_center = rot(center, rotation_angle);

		// //cout<<center.X<<" "<<center.Y<<endl;
		// double d=sqrt((center.X*center.X)+(center.Y*center.Y));
		// double m=sqrt((center.X*center.X)+( (center.Y+d)*(center.Y+d) ) );
		// double rotation=acos(1- ((m*m)/(2*d*d)) );
		// if(center.X>0)rotation*=-1;
		// //cout<<180*rotation/3.14<<endl;
		cout<<"Case "<<i<<":\n";
		// //print the origin
		cout<<"0.000000 0.000000"<<endl;
		for(int j=1;j<N;j++)
		{
			// double r=sqrt((polygon[j].X*polygon[j].X)+(polygon[j].Y*polygon[j].Y));
			// double m=sqrt((polygon[j].Y*polygon[j].Y)+( (polygon[j].X-r)*(polygon[j].X-r) ) );
			// double old_angle=acos(1- ((m*m)/(2*r*r)) );
			// if(polygon[j].Y<0)old_angle*=-1;
			//cout<<old_angle*180/3.14<<endl;
			//cout<<acos(0)<<endl;
			// double new_angle=+rotation+old_angle;
			// new_angle=new_angle+(4*acos(0));
			//cout<<new_angle*180/3.14<<endl;
			//cout<<new_angle*180/3.14<<endl;
			cout<<std::fixed;
			// double x=r*cos(new_angle),y=r*sin(new_angle);
			// if(x<0 && x>-0.000001)cout<<"0.000000 ";
			// else cout<<setprecision(6)<<x<<" ";
			// if(y<0 && y>-0.000001)cout<<"0.000000"<<endl;
			// else cout<<setprecision(6)<<y<<endl;
			Point new_point = rot(polygon[j],rotation_angle);
			output(new_point);
		}

	}

}