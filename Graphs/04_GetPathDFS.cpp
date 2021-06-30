#include<bits/stdc++.h>
using namespace std;

void getPathDFS(vector<vector<bool>> &adjMatrix, vector<bool> &visited, int from, int to, vector<int> &res) {
    if(from == to) {
        res.push_back(from);
        return ;
    }
    visited[from] = true;
    for(int i=0; i<visited.size(); i++) {
        if(i != from && visited[i] == false && adjMatrix[from][i]==true) {
            getPathDFS(adjMatrix, visited, i, to, res);
            if(res.size() > 0 && res[0] == to) {
                break;
            }
        }
    }
    if(res.size() > 0 && res[0] == to) {
        res.push_back(from);
    }

}

vector<int> getPathDFS(vector<vector<bool>> &adjMatrix, int from, int to) {
    vector<bool> visited(adjMatrix.size(), false);
    vector<int> res;
    getPathDFS(adjMatrix, visited, to, from, res);
    return res;
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

    vector<int> res = getPathDFS(adjMatrix, from, to);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}