#include<bits/stdc++.h>
using namespace std;

void printHelper(vector<vector<bool>> &adjMatrix, vector<bool> &visited, int currVertex) {
    cout << currVertex << " ";
    visited[currVertex] = true;
    for(int i=0; i<visited.size(); i++) {
        if(i != currVertex && visited[i] == false && adjMatrix[currVertex][i] == true) {
            printHelper(adjMatrix, visited, i);
        }
    }
}

void print(vector<vector<bool>> &adjMatrix) {
    vector<bool> visited(adjMatrix.size(), false);
    for(int i=0; i<adjMatrix.size(); i++) {
        if(visited[i] == false) {
            printHelper(adjMatrix, visited, i);
        }
    }
    
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
