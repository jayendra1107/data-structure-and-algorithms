// Using Kruskal's Algorithm

#include<bits/stdc++.h>
using namespace std;

class edge {
public:
    int weight;
    int source;
    int destination;
};

bool comparator(edge e1, edge e2) {
    return (e2.weight > e1.weight);
}

int findParent(int edge, vector<int> &parent) {
    if(parent[edge] == edge) {
        return edge;
    }
    return findParent(parent[edge], parent);
}

vector<edge> kruskals(vector<edge> &graph, int vertices, int edges) {
    sort(graph.begin(), graph.end(), comparator);
    vector<int> parent(vertices);
    for(int i=0; i<vertices; i++) {
        parent[i] = i;
    }
    vector<edge> res(vertices-1);
    int count=0;
    int i=0;
    while(count != vertices-1) {
        int source = graph[i].source;
        int destination = graph[i].destination;
        int p1 = findParent(source, parent);
        int p2 = findParent(destination, parent);
        if(p1 != p2) {
            res[count] = graph[i];
            parent[p1] = p2;
            count++;
        }
        i++;
    }
    return res;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<edge> graph(edges);
    for(int i=0; i<edges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[i].source = source;
        graph[i].destination = destination;
        graph[i].weight = weight;
    }

    vector<edge> res = kruskals(graph, vertices, edges);

    for(int i=0; i<vertices-1; i++) {
        cout << res[i].source << " ";
        cout << res[i].destination << " ";
        cout << res[i].weight << endl;
    }

    return 0;
}