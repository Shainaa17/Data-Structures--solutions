#include <iostream>
using namespace std;

int adj[100][100];
int visited[100];
int queue[100];
int front=0,rear=-1;
void enqueue(int x){
    queue[++rear]=x;
}
int dequeue(){
    return queue[front++];
}
bool isEmpty(){
    return front>rear;
}
void BFS(int start,int n){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[start]=1;
    enqueue(start);
    while(!isEmpty()){
        int u=dequeue();
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v]=1;
                enqueue(v);
            }
        }
    }
    cout<<endl;
}
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    adj[0][1] = adj[1][0] = 1; // A-B
    adj[0][2] = adj[2][0] = 1; // A-C
    adj[0][3] = adj[3][0] = 1; // A-D
    adj[1][4] = adj[4][1] = 1; // B-E
    adj[3][4] = adj[4][3] = 1; // D-E
    
    BFS(0,n);
}