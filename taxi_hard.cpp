#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Line{
    int idx,m,b;
    int eval(int X){
        return m*X+b;
    }
    Line(int _idx,int _m,int _b) : idx(_idx), m(_m), b(_b){}
    bool firstbetter(Line A,Line B){
        return (B.m-m)*(b-A.b)>=(A.m-m)*(b-B.b);
    }
    bool operator<(Line other){
        return idx<other.idx;
    }
};
int N,Q;
int C[200005],W[200005];
int down[200005];
vector<Line> v;
vector<tuple<int,int,int>> Query;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<N;i++) cin >> W[i];
    for(int i=0;i<N;i++) cin >> C[i];
    
    for(int i=N-1;i>=0;i--) down[i]=W[i+1]*C[i+1], down[i]+=down[i+1];
    for(int i=1;i<N;i++) W[i]+=W[i-1];
    for(int i=0;i<N;i++){
        cout << C[i] << " " << down[i]-C[i]*W[i] << '\n';
        Line New=Line(i,C[i],down[i]-C[i]*W[i]);
        while(v.size()>=2&&v[v.size()-2].firstbetter(New,v.back())) 
            v.pop_back();
        v.emplace_back(New);
    }
    for(int i=0;i<Q;i++){
        int a,b;
        cin >> a >> b;
        Query.emplace_back(a,b,i);
    }
    sort(Query.begin(),Query.end(),greater<tuple<int,int,int>>);
    for(int i=0;!Query.empty();i++){
        
        while(get<0>(Query.back())<=i){
            
        }
    }
        // if(a>=b){
        //     cout << down[b]-down[a] << '\n';
        //     continue;
        // }
        // int mn=1e18;
        // for(int i=0;v[i].idx<=a;i++) mn=min(mn,v[i].eval(W[b]));
        // int L=0,R=lower_bound(v.begin(),v.end(),Line(a+1,0,0))-v.begin();
        // while(L+1<R){
        //     int mid=(L+R)/2;
        //     if(mid==0) break;
        //     if(v[mid-1].eval(W[b])>=v[mid].eval(W[b])) L=mid;
        //     else R=mid;
        // }
        // cout << min(v[L].eval(W[b])-down[a],C[a]*(W[b]-W[a])) << '\n';
        // cout << mn-down[a] << '\n';
    return 0;
}
