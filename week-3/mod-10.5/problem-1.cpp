#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<pair<int,int>>adj[N];
const int INF = 1e9+5;
vector<int>dist(N,INF);
vector<bool>visited(N,false);

void dijkstra(int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[source] = 0;
    pq.push({dist[source],source});

    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();
        int node = u.second;
        visited[node] = true;

        for(auto vpair:adj[node]){
            int w = vpair.first;
            int v = vpair.second;

            if(visited[v])continue;

            if(dist[v]> dist[node]+w){
                dist[v] = dist[node] + w;
                pq.push({dist[v],v});
            }
        }




    }


}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;

        adj[u].push_back({w,v});
        // adj[v].push_back({w,u});

    }
    int s,d;cin>>s>>d;
    dijkstra(s);
    cout<<dist[d]<<endl;
    for(int i =1;i<=n;i++){
        cout<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}