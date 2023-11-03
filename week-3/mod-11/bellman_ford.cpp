#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

const int N = 1e5+5;
const int INF = 1e9+5;
vector<pii>adj[N];
int dist[N];

int n,m;

void bellman_ford(int s){
    for(int i=1;i<=n;i++){
        dist[i] = INF;

    }

    dist[s] = 0;

    for(int i =0;i<n;i++){

        for(int i=1;i<=n;i++){

            for(pii vpair:adj[i]){

                int w = vpair.first;
                int v = vpair.second;

                if(dist[i]!=INF && dist[v]>dist[i]+w){
                    dist[v] = dist[i] + w;
                }

            }
        }

    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){

        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({w,v});


    }

    bellman_ford(1);

    for(int i=1;i<=n;i++){
        cout<<"Distance of "<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}