#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<bool>> &adjMatrix, vector<bool> &visited, int nV) {
    int vertices = adjMatrix.size();
    queue<int> remainingVertices;
    remainingVertices.push(nV);
    visited[nV] = true;
    while(!remainingVertices.empty()) {
        int currVertex = remainingVertices.front();
        cout << currVertex << " ";
        remainingVertices.pop();
        for(int i=0; i<vertices; i++) {
            if(visited[i] == false && adjMatrix[currVertex][i] == true && i != currVertex) {
                remainingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    for(int i=0; i<vertices; i++) {
        if(visited[i] == false) {
            BFS(adjMatrix, visited, i);
        }
    }
}

void print(vector<vector<bool>> &adjMatrix) {
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    BFS(adjMatrix, visited, 0);
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<bool>> adjMatrix(vertices, vector<bool>(vertices, false));
    
    for(int i=0; i<edges; i++) {
        int m, n;
        cin >> m >> n;
        adjMatrix[m][n] = true;
        adjMatrix[n][m] = true;
    }

    print(adjMatrix);
    cout << endl;
    return 0;
}