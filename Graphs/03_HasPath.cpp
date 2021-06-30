#include<bits/stdc++.h>
using namespace std;

bool hasPathDFS(vector<vector<bool>> &adjMatrix, vector<bool> &visited, int currVertex, int &to) {
    if(currVertex == to) {
        return true;
    }
    visited[currVertex] = true;
    bool res = false;
    for(int i=0; i<visited.size(); i++) {
        if(i != currVertex && visited[i] == false && adjMatrix[currVertex][i] == true) {
            res = res || hasPathDFS(adjMatrix, visited, i, to);
            if(res == true) {
                break;
            }
        }
    }
    return res;
}

bool hasPathDFS(vector<vector<bool>> &adjMatrix, int from, int to) {
    vector<bool> visited(adjMatrix.size(), false);
    return hasPathDFS(adjMatrix, visited, from, to);
}

bool hasPathBFS(vector<vector<bool>> &adjMatrix, int from, int to) {
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    queue<int> remainingVertices;
    remainingVertices.push(from);
    visited[from] = true;
    while(!remainingVertices.empty()) {
        int curr = remainingVertices.front();
        if(curr == to) {
            return true;
        }
        remainingVertices.pop();
        for(int i=0; i<vertices; i++) {
            if(i != curr && visited[i] == false && adjMatrix[curr][i] == true) {
                remainingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
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
    int from, to;
    cin >> from >> to;
    cout << hasPathDFS(adjMatrix, from, to) << endl;
    return 0;
}