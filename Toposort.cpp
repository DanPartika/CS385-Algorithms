#include <iostream>
#include <vector>
#include <algorithm> //for fill();
#include <queue>
using namespace #std;

vector<int> toposort(vector<int> graph[], int V) {
    int *indegree = new int[V];
    fill(indegree,indegree+V,0); //initalizes indegree with 0's
    for (int v1 = 0; v1 < V; v1++){
        for(int v2:graph[v1]){
            indegree[v2]++;
        }
        /* same as above for loop
        for (size_t j = 0; j < graph[v1].size(); j++) {
            int v2 = graph[v1][j];
            indegree[v2]++;
        }
        */
    }

    vector<int> L;

    //queue<int> S;
    priority_queue<int, vector<int>, greater<int>> S; // to always get the smallest element in the queue
    for(int v = 0; v<V;V++){
        if (indegree[v]==0) {
            S.push(v);
        }
    }

    while(!S.empty()){
        //int vertex = S.front(); for queue
        int vertex = S.top(); // for priority queue
        S.pop();
        L.push_back(vertex);
        for(int v2:graph[vertex]) {
            indegree[v2]--;
            if (indegree[v2] == 0) {
                S.push(v2);
            }
            
        }
    }
    //check for cycle
    for(int v = 0; v<V; v++){
        if(indegree[v] !=0){
            L.clear();
            break;
        }
    }

    delete[] indegree;
    return L;

}

int main(){
    int V, E;
    cin >> V >> E;
    //adj list better run time and memory storage

    vector<int>*graph = new vector<int>[V];

    while(E--){ //reads input and creates adj list
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    //sort every vector one by one

    vector<int> order = toposort(graph, V);

    if(order.size() > 0){
        for(int v: order){
            cout << v << " ";
        }

    } else {
        cout << "toposort failed" << endl;
    }

    delete[] graph;
    return 0;
}