#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adj[N];
int visited[N];
int level[N];
int perent[N];
void bfs(int u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    level[u] = 1;
    perent[u] = 0;

    while(!q.empty()){
        int i = q.front();
        q.pop();

        for(int v:adj[i]){
            if(visited[v])continue;

            q.push(v);
            visited[v]=true;
            level[v] = level[i] + 1;
            perent[v] = i;
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

    bfs(1);

    vector<int>ans;
    int current = n;
    while(current != 0){
        ans.push_back(current);
        current = perent[current];
    }

    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}