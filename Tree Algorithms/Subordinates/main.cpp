
// Solved using intime and outtime dfs based approach, 
// mark in time for a node when you visit it for the first time and out time of the 
// node when you have visited all their children and you are exiting this node.
// Now number of children or descendant of a node can be found by (outtime - intime - 1)/2
// This apporach gives us result in O(1) with O(n) precomputation. So, it will work in case of multiple queries.
// 
// Using intime and out time approach, we can also find if a node u is ancestor of node v or not.
// If node u is ancestor of node v then Intime(u) < Intime(v) < Outtime(v) < Outtime(v) 


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

void go(int n, vi & I, vi & O, int &time, vector <vi> &Tree ){
    
    time++; // visited while entering the node
    I[n] = time;
    for(auto x:Tree[n]){
        go(x,I,O,time,Tree);
    }
    time++; // visited while exiting the node
    O[n] = time;

    return ;
}

int main(){

    int n;cin>>n; // take input n;
    vi v(n+1,0);  // n+1 for one indexing
    for(int i=2;i<=n;i++) cin>>v[i]; // since 1 is the company boss
    vector <vi> Tree(n+1); // 2-d array for storing tree
    for(int i=2;i<=n;i++){
        int parent = v[i];
        Tree[parent].push_back(i);
    }
    vi Intime(n+1,-1), Outtime(n+1,-1);
    int time = 0;
    go(1,Intime,Outtime,time,Tree);
    for(int i=1;i<=n;i++){
        cout<<(Outtime[i]-Intime[i]-1)/2<<" ";
    }
    cout<<endl;
    return 0;
}

