#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
vector<int>adj[N];
bool visited[N];
// int depth[N];
int height[N];
void dfs(int u){

    visited[u]= true;
    for(int v:adj[u]){
        if(visited[v]==false){
            // depth[v] = depth[u]+1;
            dfs(v);
            if(height[v]+1>height[u]){
                height[u] = height[v]+1;
            }
        }
    }
}
int main(){
    int n,m;cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int a;cin>>a;

    cout<<"Height of "<<a<<"="<<height[a];
    
    return 0;
}