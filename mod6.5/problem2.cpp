#include<bits/stdc++.h>
using namespace std;
const int N=100;
// int adjmet[N][N];
// vector<int>adjlist[N];
int main(){
    
    int n;cin>>n;
    int adjmet[N][N];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adjmet[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adjmet[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int>adjlist[N];

     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adjmet[i][j]==1){
                adjlist[i].push_back(j); 
            }
        }
    }
    
   
   for(int i=1;i<=n;i++){
     cout<<"List"<<i<<":";
     for(auto j:adjlist[i]){
        cout<<j<<" ";
     }
     cout<<endl;
   }
    return 0;
}