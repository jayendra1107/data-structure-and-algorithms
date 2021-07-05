#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<bool>> &adjMatrix, int from, int to) {
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    vector<int> distance(vertices, 0);
    queue<int> remainingVertices;
    remainingVertices.push(from);
    while(!remainingVertices.empty()) {
        int curr = remainingVertices.front();
        remainingVertices.pop();
        for(int i=0; i<vertices; i++) {
            if(!visited[i] && adjMatrix[curr][i] && i!=curr) {
                visited[i] = true;
                distance[i] = distance[curr]+1;
                remainingVertices.push(i);
                if(i==to) {
                    return distance;
                }
            }
        }
    }
    return distance;
}

int main() {
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    vector<vector<bool>> adjMatrix(vertices, vector<bool>(vertices, false));
    for(int i=0; i<edges; i++) {
        int from;
        int to;
        cin >> from >> to;
        adjMatrix[from][to] = true;
        adjMatrix[to][from] = true;
    }
    int from , to;
    cin >> from >> to;
    vector<int> res = shortestPath(adjMatrix, from, to);
    cout << res[to] << endl;
    return 0;
}