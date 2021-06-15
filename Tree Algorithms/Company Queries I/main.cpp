/**
 *
 * Use Binary Lifting for this question.
 * Store 2^k th parent for every node where k = 0,1,2,...,ceil(log2(N)).
 * Binary Lifting uses the property that, 2^(i+1)th parent of a node u is same as
 * 2^i th parent of node v, where node v is 2^i th parent of node u.
 * So, we use 2D DP array, parent[n][i] denoted 2^ith parent of node n.
 * populate parent[u][0] using dfs(in case it is not given) and direct parent of root node is -1.
 * Now, the recursive relationship is parent[n][i+1] = parent[parent[n][i]][i].
 * Storing 2^ith parents helps us solve for any kth parent in logk time as we can simply represent k in binary. 
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
ostream& operator<< ( ostream &os,vector <T> &v){
    for(auto x:v) os<<x<<" ";
    return os;
}


int main(){

    int n,q;
    cin>>n>>q;
    int K = ceil(1.0*log2(1.0*n));
    // deb(K);
    vector <vi> parent(n+1,vi(K+1,-1));
    for(int i=2;i<=n;i++) cin>>parent[i][0];
    for(int j=1;j<=K;j++){
        for(int i=2;i<=n;i++){
            /** CAUTION: 
             * !!!!!!!!!!!! CAUTION !!!!!!!!!!!!!
             * Mind that the code below will not work in the situations where
             * parent[i][j-1] is  -1.
        
            parent[i][j] = parent[parent[i][j-1]][j-1];
            
            **/

           int tempParent = parent[i][j-1];
           if(tempParent == -1){
               parent[i][j] = -1;
           }
           else{
               parent[i][j] = parent[tempParent][j-1];
           }  
        }
    }
    /**
     * 
     * Querying
     * 
     */
    while(q--){
        int a,b;
        cin>>a>>b;
        int i = 0;
        if ( b > ((1<<(K+1)) -1) ){
            cout <<-1<<endl;
            continue;
        }
        while(b){
            if(b&1){
                a = parent[a][i];
            }
            /** CAUTION: Never Forget this condition
             * VVVIMP CAUTION!!!
             * Missing This condition will get you a one way ticket to hell
             * */
            if(a==-1){ 
                break;
            }
            i++;
            b>>=1;
        }
        cout<<a<<endl;
    }
    
    return 0;
}