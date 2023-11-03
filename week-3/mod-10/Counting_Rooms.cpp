#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 +4;
char adj[N][N];
int visited[N][N];
int n,m;

int invalied(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m )return true;
    else return false;
}
void dfs(int i,int j){
    if(invalied(i,j)==false)return;
    if(visited[i][j])return;

    if(adj[i][j]=='#')return;

    visited[i][j] = true;
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i+1,j);

}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char s;
            cin>>s;
            adj[i][j] = s;
        }
    }

    int cc =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='#')continue;
            if(visited[i][j])continue;
            dfs(i,j);
            cc++;
        }
    }

    cout<<cc<<endl;
    return 0;
}