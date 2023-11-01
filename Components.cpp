#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
vector<int>ans;

void bfs(int u){
    visited[u]=true;

    queue<int>q;
    q.push(u);
    int c=0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        c++;
        for(int v:adj[x]){
            if(visited[v])continue;

            q.push(v);
            visited[v]= true;
        }
    }

    if(c>1)ans.push_back(c);
}
int main(){
    
    int n,e;cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    

    for(int i=0;i<N;i++){
        if(visited[i])continue;
         bfs(i);
        
    }

    sort(ans.begin(),ans.end());

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}