package Graph.MST;

import java.util.ArrayList;
import java.util.Collections;

public class kruskal {

    static class Edge implements Comparable<Edge> {
        int src;
        int dest;
        int wt;

        Edge(int s, int d, int w) {
            this.src = s;
            this.dest = d;
            this.wt = w;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.wt, other.wt); // sort by weight
        }
    }

    public static void CreateGraph(ArrayList<Edge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        /*
         * (15)
         * 0 -------- 2
         * |\ |
         * (10)| \ (30) |(50)
         * | \ |
         * 1 -------- 3
         * (40)
         * 
         */
        graph[0].add(new Edge(0, 1, 10));
        graph[0].add(new Edge(0, 2, 15));
        graph[0].add(new Edge(0, 3, 30));
        graph[1].add(new Edge(1, 0, 10));
        graph[1].add(new Edge(1, 3, 40));
        graph[2].add(new Edge(2, 0, 15));
        graph[2].add(new Edge(2, 3, 50));
        graph[3].add(new Edge(3, 0, 30));
        graph[3].add(new Edge(3, 1, 40));
        graph[3].add(new Edge(3, 2, 50));

    }

    public static void findAllNeighbours(ArrayList<Edge>[] graph, int V) {
        for (int i = 0; i < graph[V].size(); i++) {
            Edge e = graph[V].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }

    static class DSU {
        int[] parent;
        int[] rank;

        DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i; // each node is its own parent initially
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }

        void union(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb)
                return; // already in same set

            // union by rank
            if (rank[pa] < rank[pb]) {
                parent[pa] = pb;
            } else if (rank[pa] > rank[pb]) {
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    }

    public static int kruskalMST(ArrayList<Edge>[] graph, int V) {
        // 1. Collect all edges (but avoid duplicates like 0-1 and 1-0)
        ArrayList<Edge> edges = new ArrayList<>();

        for (int u = 0; u < V; u++) {
            for (Edge e : graph[u]) {
                // Take each undirected edge only once:
                if (e.src < e.dest) {
                    edges.add(e);
                }
            }
        }

        // 2. Sort edges by weight
        Collections.sort(edges);

        // 3. Kruskal using DSU
        DSU dsu = new DSU(V);
        int mstWeight = 0;
        int edgesUsed = 0;

        for (Edge e : edges) {
            int u = e.src;
            int v = e.dest;

            // If u and v are in different components, take this edge
            if (dsu.find(u) != dsu.find(v)) {
                dsu.union(u, v);
                mstWeight += e.wt;
                edgesUsed++;

                // Stop once we have V-1 edges in MST
                if (edgesUsed == V - 1)
                    break;
            }
        }

        return mstWeight;
    }

    public static void main(String[] args) {
        int V = 4;
        ArrayList<Edge>[] graph = new ArrayList[V];
        CreateGraph(graph);
        for (int i = 0; i < V; i++) {
            findAllNeighbours(graph, i);
        }
        System.out.println("mst weight is : " + kruskalMST(graph, V));
    }
}
