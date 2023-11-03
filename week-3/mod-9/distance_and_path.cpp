#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int perent[N];
int level[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    perent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            if(visited[v])continue;
            q.push(v);

            visited[v]=true;
            level[v] = level[u] + 1;
            perent[v] = u;
        }

    }

}
int main(){
    int n,e;cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(v);

    }

    int s,d;cin>>s>>d;

    bfs(s);

    cout<<"Distance = "<< level[d]<<endl;

    vector<int>path;
    int current = d;
    while(current!=-1){
        path.push_back(current);
        current = perent[current];
    }

    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(int node:path){
        cout<<node<<" ";
    }

    return 0;
}