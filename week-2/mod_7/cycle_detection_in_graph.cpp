#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N]={0};
bool dfs(int s,int p=-1){
    visited[s]=1;
    bool iscycle = false;
    for(int v:adj[s]){
        if(v==p)continue;

        if(visited[v])return true;
        iscycle |= dfs(v,s);

    }
    return iscycle;
    
}
int main(){
    int n,m;cin>>n,m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }
    bool cycle=false;

    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        if(cycle)break;
        cycle |= dfs(i);
    }

    if(cycle)cout<<"Cycle Detected.";
    else cout<<"Cycle is not detected";

    return 0;
}


