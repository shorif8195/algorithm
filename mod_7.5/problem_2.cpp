#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>adj[N];

int visited[N];
int level[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;

    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(int v:adj[n]){
            if(visited[v])continue;
            q.push(v);

            visited[v]=true;
            level[v]= level[n]+1;


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
    int x;cin>>x;
    cout<<"Level of "<<x<<" = "<<level[x];

    return 0;
}