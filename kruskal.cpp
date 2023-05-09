#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdge(Edge e1, Edge e2) {
    return (e1.weight < e2.weight);
}

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdge);
    DisjointSet disjointSet(n);
    vector<Edge> mst;
    int mstWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (disjointSet.find(e.src) != disjointSet.find(e.dest)) {
            disjointSet.merge(e.src, e.dest);
            mst.push_back(e);
            mstWeight += e.weight;
        }
    }
    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (int i = 0; i < mst.size(); i++) {
        Edge e = mst[i];
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
    }
}


int main() {
    int n = 6;
    vector<Edge> edges = { {0, 1, 4}, {0, 2, 3}, {1, 2, 1}, {1, 3, 2}, {2, 3, 4}, {3, 4, 2}, {4, 5, 6} };
    kruskal(edges, n);
    return 0;
}
