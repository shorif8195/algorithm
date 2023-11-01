#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
bool visited[N];
vector<int>ans;
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        q.pop();
       for(int v:adj[u]){
             if(visited[v])continue;
        
            q.push(v);

            visited[v]=true;
       }
    }

    
}
int main(){
    int n,m;cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}