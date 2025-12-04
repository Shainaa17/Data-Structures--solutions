#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V = 5, E = 7;
    Edge edges[] = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8},
        {1,4,5}, {2,4,7}, {3,4,9}
    };

    bool inMST[100] = {false};
    inMST[0] = true;   // start from node 0

    cout << "Prim MST:\n";

    int count = 0;

    while (count < V - 1) {

        int pick = -1;
        int minW = 999999;

        // -------- find minimum edge connecting MST ↔ non-MST --------
        for (int i = 0; i < E; i++) {
            bool u_in = inMST[edges[i].u];
            bool v_in = inMST[edges[i].v];

            // select valid Prim edge: exactly one side in MST
            if (u_in != v_in) {
                if (edges[i].w < minW) {
                    minW = edges[i].w;
                    pick = i;
                }
            }
        }

        // Add that edge to MST
        cout << edges[pick].u << " -- " 
             << edges[pick].v << " (w=" 
             << edges[pick].w << ")\n";

        inMST[edges[pick].u] = true;
        inMST[edges[pick].v] = true;

        count++;
    }

    return 0;
}
