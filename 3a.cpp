
#include <bits/stdc++.h>

using namespace std;


int v = 9;

int mindistance(int dist[], bool visited[]){
    int mn = INT_MAX;
     int ve = -1;

    for(int i=0;i<v;i++){

        if(visited[i] != true && mn <= dist[i]){
            mn = dist[i];
            ve = i;
        }
    }

    return ve;

}

void dijkstra(int graph[v][v], int  v){

    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;


    bool visited[v] = {false};

    for(int i=0;i<v;i++){

        int u = mindistance(dist,visited);

        if(u == -1){
            break;
        }
        visited[u] = true;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && graph[u][j] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }

    }



}




int main() {
    int graph[v][v] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,0,10,0,2,0,0},
        {0,0,0,14,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    dijkstra(graph, 0);
    return 0;
}
