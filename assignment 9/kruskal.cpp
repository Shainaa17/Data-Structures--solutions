#include <iostream>
using namespace std;

struct Edge {
    int u, v, w; // from, to, weight
};

// Find parent with path compression
int findParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

// Union of two sets
void unionSet(int parent[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a != b) parent[b] = a;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100]; // array for edges

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // ---------- Step 1: Sort edges by weight ----------
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // ---------- Step 2: Create parent array for DSU ----------
    int parent[100];
    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "\nEdges in MST:\n";

    int mstWeight = 0;
    int count = 0; // number of edges added to MST

    // ---------- Step 3: Kruskal ----------
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {  
            cout << u << " - " << v << " : " << w << "\n";
            mstWeight += w;
            count++;

            unionSet(parent, pu, pv);
        }
    }

    cout << "\nTotal MST Weight = " << mstWeight << "\n";

    return 0;
}
