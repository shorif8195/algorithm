#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
vector<int>ans;

void dfs(int u){
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v])return;
        ans.push_back(v);
        dfs(v);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(v);
    }

    int x;cin>>x;

    if(x<0 || x>200){
        cout<<"-1\n";
        return 0;
    }
    dfs(x);

    if(ans.empty())cout<<"-1\n";
    else cout<<ans.size();
    return 0;
}