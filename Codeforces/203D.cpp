//AC
//12:12
//12:45
#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000
#define ep 0.0000001
struct point
{
	long double x,y,z;
	point(long double x=0,long double y=0,long double z=0)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b,m;
	long double vx,vy,vz;
	cin>>a>>b>>m>>vx>>vy>>vz;	
	std::vector<long double> hitTime(5);
	std::vector<point> hitPoints(5);
	std::vector<point> hitVectors(5);
	point curPoint(0.5*a,m,0);
	point curVector(vx,vy,vz);
	bool done=0;
	while(!done)
	{
		// cout<<curPoint.x<<" "<<curPoint.y<<" "<<curPoint.z<<endl;
		// cout<<(hitTime[0]=INF)<<endl;
		if(abs(curVector.y)<ep)
		{
			hitTime[0]=INF;
		}
		else
		{
			//DONE
			hitTime[0]=-curPoint.y/curVector.y;
			hitPoints[0].x=curPoint.x+hitTime[0]*curVector.x;
			hitPoints[0].y=0;
			hitPoints[0].z=curPoint.z+hitTime[0]*curVector.z;
			// cout<<cu
		}
		if(abs(curVector.z)<ep)
		{
			hitTime[1]=INF;
			hitTime[2]=INF;
		}
		else
		{
			hitTime[1]=(b-curPoint.z)/curVector.z;
			hitTime[2]=-curPoint.z/curVector.z;
			hitVectors[1]=curVector;
			hitVectors[2]=curVector;
			hitVectors[1].z*=-1;
			hitVectors[2].z*=-1;

			hitPoints[1].x=curPoint.x+hitTime[1]*curVector.x;
			hitPoints[1].y=curPoint.y+hitTime[1]*curVector.y;
			hitPoints[1].z=b;

			hitPoints[2].x=curPoint.x+hitTime[2]*curVector.x;
			hitPoints[2].y=curPoint.y+hitTime[2]*curVector.y;
			hitPoints[2].z=0;
		}
		if(abs(curVector.x)<ep)
		{
			hitTime[3]=INF;
			hitTime[4]=INF;
		}
		else
		{
			hitTime[3]=(a-curPoint.x)/curVector.x;
			hitTime[4]=-curPoint.x/curVector.x;
			hitVectors[3]=curVector;
			hitVectors[4]=curVector;
			hitVectors[3].x*=-1;
			hitVectors[4].x*=-1;

			hitPoints[3].x=a;
			hitPoints[3].y=curPoint.y+hitTime[3]*curVector.y;
			hitPoints[3].z=curPoint.z+hitTime[3]*curVector.z;
			
			hitPoints[4].x=0;
			hitPoints[4].y=curPoint.y+hitTime[4]*curVector.y;
			hitPoints[4].z=curPoint.z+hitTime[4]*curVector.z;
		}

		int minind=0;
		for(int i=1;i<5;i++)
		{
			// cout<<hitTime[i]<<" ";
			if(hitTime[i]<hitTime[minind] && abs(hitTime[i])>ep && hitTime[i]>0)
				minind=i;
		}
		if(minind==0)
		{
			//DONE
			done=1;
			curPoint=hitPoints[0];
		}
		else
		{
			// cout<<minind<<endl;
			curPoint=hitPoints[minind];
			curVector=hitVectors[minind];
		}
	}
	cout<<fixed<<setprecision(6)<<curPoint.x<<" "<<curPoint.z;
}