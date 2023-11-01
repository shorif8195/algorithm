#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e5+5;
vector<int>adj[N];
bool visited[N];
int level[N];
vector<int>ans;

void bfs(int u){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    level[u]=0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y:adj[x]){
            if(visited[y])continue;

            q.push(y);
            visited[y]=true;
            level[y] = level[x] + 1;


        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        int a,b;cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int l;cin>>l;

    bfs(0);

//    queue<int>s;
    
    // int h=0;
    // for(int i=0;i<=n;i++){
    //     if(level[i]>h)h=level[i];
    // }

    // if(h<l)cout<<"-1\n";
    
        for(int i=0;i<=n;i++){
                
            if(level[i]==l)ans.push_back(i);
    }

    sort(ans.begin(),ans.end());

    if(ans.empty())cout<<"-1\n";
    else {
        for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    }
    
   
//    if(s.empty())cout<<-1;
//    else{

//         for(int i=0;i<sizeof(s);i++){
//             if(s.empty()){
//                 break;
//             }
//             cout<<s.front()<<" ";
//             s.pop();
//         }

//    }
   

    return 0;
}