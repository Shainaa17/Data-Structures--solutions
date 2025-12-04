#include <iostream>
using namespace std;
int main(){
    int V;
    cin>>V;
    int graph[10][10];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    int src;
    cin>>src;
    int dist[10],vis[10];
    for(int i=0;i<V;i++){
        dist[i]=99999;
        vis[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=-1;
        for(int i=0;i<V;i++){
            if(!vis[i] && (u==-1 || dist[i]<dist[u])){
                u=i;
            }
        }
        vis[u]=1;
        for(int v=0;v<V;v++){
            if(graph[u][v] !=0 && !vis[v] && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<"Shortes to "<<i<<"="<<dist[i]<<endl;
    }
}