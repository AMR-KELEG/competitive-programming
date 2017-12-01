//AC
#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
void update(int node,int l,int r,int in,int val)
{
    if(l==r && l==in)
    {
        tree[node]=val;
        return ;
    }
    if(l>in || r<in)return ;
    int mid=(l+r)>>1;
    update(2*node,l,mid,in,val);
    update(2*node+1,1+mid,r,in,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int l,int r,int rl,int rr)
{
    if(rl>rr)return 0;
    if(l>rr || r<rl)return 0;
    if(l>=rl && r<=rr)return tree[node];
    int mid=(l+r)>>1;
    return max(
        query(2*node,l,mid,rl,rr),
        query(2*node+1,1+mid,r,rl,rr)
    );
}

int main()
{
    ios::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    vector<long long int> orig_h(n);
    vector<pair<long long int,int> > h(n);
    for(int i=0;i<n;i++)
    {
        h[i].second=i;
        cin>>h[i].first;
        orig_h[i]=h[i].first;
    }
    sort(h.begin(),h.end());
    vector<int> pos_in_tree(n);
    for(int j=0;j<n;j++)
        pos_in_tree[h[j].second]=j;
    tree = vector<int>(4*n,0);
    int max_ans=0;
    int start_index = -1;

    for(int i=n-1;i>=0;i--)
    {
        long long int hei = orig_h[i];
        // Find range of applicable heights
        int hl=
            lower_bound(h.begin(),h.end(),pair<long long int,int>(1+hei-d,-1))-h.begin();
        int hr=
            lower_bound(h.begin(),h.end(),pair<long long int,int>(hei+d,-1))-h.begin();
        if(h[hl].first>hei-d)hl--;
        if(hr<n && h[hr].first<hei+d)hr++;
        int ans = 1+max(query(1,0,n-1,0,hl),query(1,0,n-1,hr,n-1));
        max_ans=max(ans,max_ans);
        if(ans==max_ans)start_index=i;
        update(1,0,n-1,pos_in_tree[i],ans);
    }
    printf("%d\n",max_ans);
    while(max_ans--)
    {
        printf("%d ",1+start_index);
        for(int i=start_index+1;i<n;i++)
        {
            if(query(1,0,n-1,pos_in_tree[i],pos_in_tree[i])==max_ans
                && abs(orig_h[start_index]-orig_h[i])>=d)
            {
                start_index=i;
                break;
            }
        }
    }
    return 0;
}
