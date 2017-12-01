/* AC
 - Find the four lines
 - Find their intersections
 - Check whether there exists a single unique intersection point	
*/

#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-9
#define Line pair<Point, Point> // base_point , slope_vector
#define cp(a,b) (conj(a)*(b)).Y

bool point_on_st_line(Point p, Line l)
{
	Point p1 = l.first;
	Point p2 = p1 + l.second;
	Point v1 = p2-p1;
	Point v2 = p2-p;
	return abs(cp(v1,v2))<EPS;
}	

pair<int,Point> line_line_intersection(Line l1, Line l2)
{
	Point p1 = l1.first;
	Point v1 = l1.second;
	Point p2 = l2.first;
	Point v2 = l2.second;
	if (point_on_st_line(p2,l1)|| point_on_st_line(p1,l2))
	{
		return {2,Point(0,0)};
	}
	long double a = v2.X;
	long double b = -v1.X;
	long double c = v2.Y;
	long double d = -v1.Y;
	long double det = (a*d) - (b*c);
	
	if (abs(det)<EPS)
		return {0,Point(0,0)};
	long double c1 = p1.X - p2.X;
	long double c2 = p1.Y - p2.Y;
	long double n = (d*c1 - b*c2)/det;
	long double m = (-c*c1 + a*c2)/det;
	return {1,p2 + (n*v2)};
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long double cx,cy;
	cin>>cx>>cy;
	long double s;
	cin>>s;
	long double x,y;
	cin>>x>>y;
	Point center(cx,cy);
	Point P(x,y);
	std::vector<Point> pts;
	long double dx[]={-s*0.5, -s*0.5, s*0.5, s*0.5};
	long double dy[]={-s*0.5, s*0.5, s*0.5, -s*0.5};
	for (int i=0;i<4;i++)
	{
		pts.push_back(center + Point(dx[i],dy[i]));
		// cout<<pts[i].X<<" "<<pts[i].Y<<endl;
	}

	std::vector<Line> lines;
	for (int i=0;i<4;i++)
	{
		Point vec = pts[(i+1)%4] - P;
		x = -vec.Y;
		y = vec.X;
		lines.push_back({pts[i], Point(x,y)});
		// cout<<"Line "<<i<<endl;
		// cout<<pts[i].X<<" "<<pts[i].Y<<endl;
		// cout<<x<<" "<<y<<endl<<endl;
	}
	// if (point_on_st_line(lines[1].first, lines[3]))
	// 	cout<<"OK!!";
	// return 0;
	std::vector<Point> inter_pts;
	for (int i=0;i<4;i++)
	{
		for (int j=i+1;j<4;j++)
		{
			pair<int,Point> cur_inter;
			cur_inter = line_line_intersection(lines[i],lines[j]);
			if (!cur_inter.first)
			{
				cout<<"NO";
				return 0;
			}
			else if(cur_inter.first==2)
				continue;
			inter_pts.push_back(cur_inter.second);
		}
	}
	for (int i=0;i<inter_pts.size();i++)
	{
		for (int j=i+1;j<inter_pts.size();j++)
		{
			if (abs(inter_pts[i]-inter_pts[j])<EPS)
			{
				inter_pts.erase(inter_pts.begin() + j);
				i=-1;
				break;
			}
		}
	}
	if (inter_pts.size()==1)
	{
		printf("YES\n%0.1LF %0.1LF", inter_pts[0].X,inter_pts[0].Y);
	}
	else
	{
		printf("NO\n");
	}

}