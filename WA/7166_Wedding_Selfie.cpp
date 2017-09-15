#include "bits/stdc++.h"
using namespace std;
class point {
	public :
	double X;
	double Y;
	point(double x,double y)
	{
		this->X=x;
		this->Y=y;			
	}
};

point polyginCentroid(vector<point> &polygon) {
	point res(0, 0);
	long double a = 0;
	//cout<<polygon.size()<<endl;
	for (int i = 0; i < (int) polygon.size(); i++) {
		int j = (i + 1) % polygon.size();
		res.X += (polygon[i].X + polygon[j].X) * (polygon[i].X* polygon[j].Y	- polygon[j].X * polygon[i].Y);
		res.Y += (polygon[i].Y + polygon[j].Y) * (polygon[i].X* polygon[j].Y- polygon[j].X * polygon[i].Y);
		a += polygon[i].X * polygon[j].Y - polygon[i].Y *polygon[j].X;
		//cout<<a<<endl;
	}

	a *= 0.5;
	//cout<<a<<" "<<res.X<<" "<<res.Y<<endl;
	res.X /= 6 * a;
	res.Y /= 6 * a;
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	int N,x,y;
	vector<point>polygon;
	for(int i=1;i<=T;i++)
	{
		polygon.clear();
		cin>>N;
		//cout<<N<<endl;
		for(int j=0;j<N;j++)
		{
			cin>>x>>y;
			polygon.push_back(point(x,y));
		}		
		point center=polyginCentroid(polygon);
		//cout<<center.X<<" "<<center.Y<<endl;
		double d=sqrt((center.X*center.X)+(center.Y*center.Y));
		double m=sqrt((center.X*center.X)+( (center.Y+d)*(center.Y+d) ) );
		double rotation=acos(1- ((m*m)/(2*d*d)) );
		if(center.X>0)rotation*=-1;
		//cout<<180*rotation/3.14<<endl;
		cout<<"Case "<<i<<": "<<endl;
		//print the origin
		cout<<"0.000000 0.000000"<<endl;
		for(int j=1;j<N;j++)
		{
			double r=sqrt((polygon[j].X*polygon[j].X)+(polygon[j].Y*polygon[j].Y));
			double m=sqrt((polygon[j].Y*polygon[j].Y)+( (polygon[j].X-r)*(polygon[j].X-r) ) );
			double old_angle=acos(1- ((m*m)/(2*r*r)) );
			if(polygon[j].Y<0)old_angle*=-1;
			//cout<<old_angle*180/3.14<<endl;
			//cout<<acos(0)<<endl;
			double new_angle=+rotation+old_angle;
			new_angle=new_angle+(4*acos(0));
			//cout<<new_angle*180/3.14<<endl;
			//cout<<new_angle*180/3.14<<endl;
			cout<<std::fixed;
			double x=r*cos(new_angle),y=r*sin(new_angle);
			if(x<0 && x>-0.000001)cout<<"0.000000 ";
			else cout<<setprecision(6)<<x<<" ";
			if(y<0 && y>-0.000001)cout<<"0.000000"<<endl;
			else cout<<setprecision(6)<<y<<endl;
		}

	}

}