#include "bits/stdc++.h"
using namespace std;

typedef complex <long double> point;
const double eps = 1e-10;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())
#define X                   real()
#define Y                   imag()
#define cross(a, b)         ((conj(a)*(b)).imag())
#define vec(a, b)           ((b) - (a))

struct cmp{
    point about;
    cmp(point c){
        about = c;
    }
    bool operator()(const point &p, const point &q)const{
        double c = cross(vec(about, p), vec(about, q));
        if(fabs(c) < eps)
            return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
        return c > 0;
    }
};

void sortAntiClockWise(vector <point> &pnts)
{
    point about = pnts[0];
    for(int i = 0; i < sz(pnts); i++){
        if(make_pair(pnts[i].Y, pnts[i].X) < make_pair(about.Y, about.X))
            about = pnts[i];
    }
    sort(all(pnts), cmp(about));
}

long double convexHull(vector <point> pnts)
{
    std::vector<point> convex;
    sortAntiClockWise(pnts);
    convex.push_back(pnts[0]);
    if(sz(pnts) == 1)
        return 0;

    convex.push_back(pnts[1]);
    pnts.push_back(pnts[0]);
    
    for(int i = 2; i < sz(pnts); i++){
        point c = pnts[i];
        while(sz(convex) > 1){
            point b = convex.back();
            point a = convex[sz(convex) - 2];
            
            if(cross(vec(b, a), vec(b, c)) < -eps)
                break;
            convex.pop_back();
        }
        if(i != sz(pnts) - 1)
            convex.push_back(pnts[i]);
    }
    pnts.pop_back();
    // cout<<endl<<endl;
    // for (int i=0;i<convex.size();i++)
    // {
    //     cout<<convex[i].X<<" "<<convex[i].Y<<endl;
    // }
    // cout<<endl<<endl;
    long double ans = 0;
    for (int i=0;i<convex.size()-1;i++)
    {
        ans += 0.5 * (convex[i].X - convex[i+1].X) * 
                (convex[i].Y + convex[i+1].Y);
    }
    int i= convex.size()-1;
    ans += 0.5 * (convex[i].X - convex[0].X) * 
            (convex[i].Y + convex[0].Y);
    return abs(ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int N;
    cin>>N;
    long double ans = 0;
    for (int j=0;j<N;j++)
    {
        int n;
        cin>>n;
        std::vector<point> pts(n);
        for (int i=0;i<n;i++)
        {
            long double x,y;
            cin>>x>>y;
            pts[i] = point(x,y);
        }
        if (j == 0)
        {
            ans = convexHull(pts);
        }
        else
        {
            ans = max(ans, convexHull(pts));
        }
    }
    printf("%0.2LF\n", ans);
}