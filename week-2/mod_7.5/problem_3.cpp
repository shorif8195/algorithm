#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+6;
vector<int>adj[N];
bool visited[N];

bool dfs(int s,int p=-1){
            visited[s]=true;
            bool iscycle = false;
            for(int v:adj[s]){
                if(v==p)continue;
                if(visited[v])return true;
               iscycle = iscycle || dfs(v,s);
            }
            return iscycle;
}
int main(){
    int n,m;cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    bool isc = false;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;

        isc = isc || dfs(i);
    }
    if(isc){
        cout<<"YES\n";
    }
    else cout<<"NO";

    return 0;
}