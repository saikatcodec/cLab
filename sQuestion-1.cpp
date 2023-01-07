#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int>> gp;

    void dfs(unordered_map<int, bool> &visited, int st, int dest, bool &track) {
        visited[st] = true;
        if (st == dest) {
            track = true;
            return;
        }

        for (auto node : gp[st]) {
            if (!visited[node]) {
                dfs(visited, node, dest, track);
            }
        }
    }

   public:
    void addEdge(int a, int b) {
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    bool hasPath(int st, int dest) {
        unordered_map<int, bool> visited;
        for (auto node : gp) {
            visited[node.first] = false;
        }

        bool track = false;
        dfs(visited, st, dest, track);

        return track;
    }
};

int main() {
    Graph g;
    int n;
    cout << "Number of nodes: ";
    cin >> n;
    int edges;
    cout << "Number of edges: ";
    cin >> edges;

    cout << "Enter edge: " << endl;
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cout << "Enter source - destination: ";
    int a, b;
    cin >> a >> b;

    if (g.hasPath(a, b))
        cout << "Path exits" << endl;
    else
        cout << "Path does not exits" << endl;

    return 0;
}