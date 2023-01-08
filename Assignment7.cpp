#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define inf INT_MAX
const int N = 1e3;

int cost[N][N]; // Adjacency matrix having weights


void Prims(int v){ // Graph's vertex should start from 0
    int dist[v];
    int from[v];
    int visited[v];
    fill(dist, dist+v, inf);
    fill(visited, visited+v, 0);
    fill(from, from+v, 0);

    vector< pair<pair<int, int>, int> >MSTedges; // For output 
    
    dist[0] = 0;
    int cur = 0;

    for(int iteration = 1; iteration < v; iteration++){
        visited[cur] = 1;

        for(int i = 0; i < v; i++){
            if (!visited[i]){
                if (cost[cur][i] < dist[i]){
                    dist[i] = cost[cur][i];
                    from[i] = cur;
                }
            }
        }

        int mn = inf;
        for(int i = 0; i < v; i++){
            if (!visited[i]){
                if (dist[i] < mn){
                    mn = dist[i];
                    cur = i;
                }
            }
        }

        MSTedges.push_back({ {from[cur], cur}, mn});
    }

    // For displaying the result
    int sum = 0;

    cout<<"\n***** PRIM'S ALGORITHM *****\n";
    for(auto it : MSTedges){
        cout<<"Edge : "<<it.first.first<<" - "<<it.first.second<<" Length : "<<it.second<<nl;
        sum+=it.second;  
    }
    cout<<"Minimum Cost of Edges : "<<sum<<nl;
}

// Union-Find Algorithm is used for detection of cycle in Kruskal's Algorithm
void Union(int x, int y, int parent[], int v){ // Naive Implementation
    int tempx = parent[x];
    int tempy = parent[y];

    for(int i = 0; i < v; i++){
        if (parent[i] == tempx or parent[i] == tempy){
            parent[i] = tempx;
        }
    }
}

int find(int x, int parent[]){
    return parent[x];
}


void Kruskal(int v){
    int parent[v];
    for(int i = 0;i < v; i++) parent[i] = i;

    vector< pair<int, pair<int, int>> >edges;
    vector< pair<int, pair<int, int>> >MSTedges;

    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if (cost[i][j] != inf){
                edges.push_back({cost[i][j], {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(auto it : edges){
        if (find(it.second.first, parent) != find(it.second.second, parent)){
            Union(it.second.first, it.second.second, parent, v);

            MSTedges.push_back({it.first, {it.second.first, it.second.second}});
        }
    }

    // For displaying the output
    int sum = 0;

    cout<<"\n***** KRUSKAL'S ALGORITHM *****\n";
    for(auto it : MSTedges){
        cout<<"Edge : "<<it.second.first<<" - "<<it.second.second<<" Length : "<<it.first<<nl;
        sum+=it.first;
    }
    cout<<"Minimum Cost of Edges : "<<sum<<nl;
}


int main(){
    int v = 0, op = 0, op1 = 1, op2 = 0, src = 0, dest = 0, weight = 0;

    do{
        cout<<"\n\n*********** Minimum Spanning Tree ***********"<<nl<<nl;
        cout<<"Choose The Desired Option:\n";
        cout<<"1. Add a New Graph\n";
        cout<<"2. MST using Prim's Algorithm\n";
        cout<<"3. MST using Kruskal's Algorithm\n";
        cout<<"*. Press any other numeric key to exit\n";
        cout<<"*********************************************\n";

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
                    cout<<"1. Add Edges"<<nl;
                    cout<<"2. Delete Edge"<<nl;
                    cout<<"0. Go Back To The Main Menu"<<nl;
                    cin>>op1;

                    switch(op1){
                        case 1:
                            cout<<"Enter the number of edges you want to add : ";
                            cin>>op2;
                            for(int i = 0; i < op2; i++){
                                cout<<"Enter the source vertex : ";
                                cin>>src;
                                cout<<"Enter the destination vertex : ";
                                cin>>dest;
                                cout<<"Enter the length of the edge : ";
                                cin>>weight;

                                cost[src][dest] = weight;
                                cost[dest][src] = weight;
                            }
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
                op1 = 1;
                break;
            case 2:                
                Prims(v);
                break;
            case 3:                
                Kruskal(v);
                break;

            default:
                op = 0;
                break;
        }
    }while(op != 0);
}