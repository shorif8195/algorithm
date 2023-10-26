#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
bool visited[N];
int depth[N]={0};
void dfs(int u){
    visited[u]=true;

    for(int v:adj[u]){
        if(visited[v]==false){
            depth[v]=depth[v]+1;
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    for(int i=0;i<=n;i++){
        cout<<"node "<<i<<":"<<depth[i]<<endl;
    }
    return 0;
}