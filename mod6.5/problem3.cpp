#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adjList[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adjList[u].push_back(v);
    }
    int adjmet[100][100];
    for(int i=1;i<=n;i++){
        for(auto v:adjList[i]){
            adjmet[i][v] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adjmet[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}