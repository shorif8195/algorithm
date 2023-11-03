#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adj[N];
int visited[N];

void dfs(int s){
    visited[s] = true;
    for(int i:adj[s]){
        if(visited[i])continue;
        dfs(i);

    }
}
int main(){
    int n,m;cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<int>ans;
    int cc=0;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        ans.push_back(i);
        dfs(i);
        cc++;
    }

    cout<<cc-1<<endl;

    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;

    }
    return 0;
}