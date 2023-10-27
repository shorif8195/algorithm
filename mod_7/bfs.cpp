#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>adj[N];
int level[N];
bool visited[N];

void bfs(int s){
    queue<int>q;
    q.push(s);

    visited[s]=true;
    level[s]=0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<"visiting node:"<<u<<endl;

        for(int v:adj[u]){
            if(visited[v]==true)continue;

            q.push(v);
            visited[v]=true;
            level[v]= level[u]+1;
        }

    }


}
int main(){
    int n,m;cin>>n>>m;  // taking n for number of node and m for number edge;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v; // taking u and v which are connected each other
        adj[u].push_back(v);
        adj[v].push_back(u);

    }    
    bfs(1);

    for(int i=1;i<=n;i++){
        cout<<i<<"'s level: "<<level[i]<<endl;
    }
    return 0;
}