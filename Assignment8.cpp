#include<bits/stdc++.h>

using namespace std;

#define nl "\n"
#define inf INT_MAX
#define int long long
const int N = 1e4;

int cost[N][N];
int dist[N];
int visited[N];

void djikstra(int src, int v){
    dist[src] = 0;
    
    int cur = src, mn = inf; 

    for(int iteration = 1; iteration <= v; iteration++){
        mn = inf;
        visited[cur] = 1;

        for(int i = 0; i < v; i++){
            if (visited[i]==0){
                dist[i] = min(dist[i], dist[cur]+cost[cur][i]);
            }
        }
        for(int i = 0; i < v; i++){
            if (visited[i]==0 and dist[i] <= mn){
                mn = dist[i];
                cur = i;
            }
        }

    }

    // For displaying the result
    for(int i = 0; i < v; i++){
        cout<<"Shortest Distance from Vertex "<<src<<" to Vertex "<<i<<" = "<<dist[i]<<nl;
    }
}

signed main(){
    int v = 0, op = 0, op1 = 1, src = 0, dest = 0, weight = 0;

    do{
        cout<<"\n******* Djikstra's Algorithm *******"<<nl<<nl;
        cout<<"Choose The Desired Option:\n";
        cout<<"1. Add a New Graph\n";
        cout<<"2. Calculate Shortest Distance from any Vertex\n";
        cout<<"*. Press any other numeric key to exit\n";

        cin>>op;

        switch(op){
            case 1:
                cout<<"Enter the number of vertices in the graph : ";
                cin>>v;

                for(int i = 0; i <= v; i++){
                    for(int j = 0; j <= v; j++){
                        cost[i][j]=inf;
                    }
                }

                while(op1!=0){
                    cout<<"1. Add Edge"<<nl;
                    cout<<"2. Delete Edge"<<nl;
                    cout<<"0. Go Back To The Main Menu"<<nl;
                    cin>>op1;

                    switch(op1){
                        case 1:
                            cout<<"Enter the source vertex : ";
                            cin>>src;
                            cout<<"Enter the destination vertex : ";
                            cin>>dest;
                            cout<<"Enter the length of the edge : ";
                            cin>>weight;

                            cost[src][dest] = weight;
                            cost[dest][src] = weight;
                            break;
                        case 2:
                            cout<<"Enter the source vertex : ";
                            cin>>src;
                            cout<<"Enter the destination vertex : ";
                            cin>>dest;

                            cost[src][dest] = inf;
                            cost[dest][src] = inf;
                            break;
                        default:
                            op1 = 0;
                            break;
                    }
                }
                break;
            case 2:
                fill(dist, dist+v, inf);
                fill(visited, visited+v, 0);
                
                cout<<"Enter the vertex from which you want to calculate the shortest distance to other vertices : ";
                cin>>src;
                djikstra(src, v);
                break;
            
            default:
                op = 0;
                break;
        }
    }while(op != 0);
}