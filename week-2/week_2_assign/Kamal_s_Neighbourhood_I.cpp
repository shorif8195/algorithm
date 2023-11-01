#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(v);
    }

    int x;cin>>x;
    int c=0;
    for(int u:adj[x]){
        c++;
    }
    cout<<c<<endl;
    return 0;
}