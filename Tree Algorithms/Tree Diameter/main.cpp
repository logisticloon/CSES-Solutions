/**
 * 
 * This code uses two DFS based apporach to find diameter, 
 * In the first DFS, we find the node farthest from any node you start DFS from.
 * From this node do another DFS to find the farthest node from this node.
 * 
**/

#include <bits/stdc++.h>

#define ll long long int
#define vll vector <ll>
#define vi vector <int>
#define pii pair<int,int>
#define deb(x) cout<<#x<<" = "<<x<<endl
#define inp(v,n) for(ll i=0;i<n;i++) cin>>v[i]

using namespace std;

template <typename T>
ostream operator<< (vector <T> &v,ostream &os){
    for(auto x:v) cout<<x<<" ";
    return os;
}
vi depth(2e5+2,0);
void go(int n, int p, int d, vector <vi> &adj){   // p is parent, so that we don't go in circles!
    depth[n] = d;
    for(auto x:adj[n]){                         
        if(x!=p)                        // dont forget to add this.
            go(x,n,d+1,adj);
    }
    return ;
}

int main(){

    int n,a,b;
    cin>>n;
    vector <vi> adj(n+1);
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b),adj[b].push_back(a);
    }
    
    go(1,-1,0,adj);
    int ans = 0, ansNode = 0;
    for(int i=1 ; i<=n;i++){
        if(depth[i] > ans){
            ans = depth[i];
            ansNode = i;
        }
    }
    go(ansNode,-1,0,adj);
    ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,depth[i]);
    cout<<ans<<endl;
    return 0;
}

