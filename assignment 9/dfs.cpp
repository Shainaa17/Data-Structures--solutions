#include <iostream>
using namespace std;
int adj[100][100];
int visited[100];
int stack[100];
int top=-1;
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
bool isEmpty(){
    return top==-1;
}
void DFS(int start,int n){
    for(int i=0;i<n;i++){
        visited[i]=0;
        push(start);
        while(!isEmpty()){
            int u=pop();
            if(!visited[u]){
                visited[u]=1;
                cout<<u<<" ";

                for(int v=n-1;v>=0;v--){
                    if(adj[u][v] && !visited[v]){
                        push(v);
                    }
                }
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
    
    DFS(0,n);
}