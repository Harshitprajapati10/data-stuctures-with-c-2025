package Graph.ShortestPath;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class AllAlgos {

    static class Edge {
        int src;
        int dest;
        int weight;

        public Edge(int s, int d, int w) {
            this.src = s;
            this.dest = d;
            this.weight = w;
        }
    }

    public static class Pair implements Comparable<Pair> {
        int Node;
        int dist;

        public Pair(int n, int d) {
            this.Node = n;
            this.dist = d;
        }

        @Override
        public int compareTo(Pair p) {
            return this.dist - p.dist; // sort in order of distance in ascending order
        }
    }

    public static void CreateGraph(ArrayList<Edge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        /*
        
        */
        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));
        graph[1].add(new Edge(1, 2, 1));
        graph[1].add(new Edge(1, 3, 7));
        graph[2].add(new Edge(2, 4, 3));
        graph[3].add(new Edge(3, 5, 1));
        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 5));
    }

    public static void showNeighbours(ArrayList<Edge>[] graph, int V) {
        for (int i = 0; i < graph[V].size(); i++) {
            Edge e = graph[V].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }

    // dijstra's algorthm -> not work for -ve weight
    public static void Dijstras(ArrayList<Edge>[] graph, int src, int V) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int[] dist = new int[V];
        for (int i = 0; i < V; i++) {
            if (i != src) {
                dist[i] = Integer.MAX_VALUE;
            }
        }
        boolean[] vis = new boolean[V];
        pq.add(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.remove();
            if (!vis[curr.Node]) {
                vis[curr.Node] = true;
                for (int i = 0; i < graph[curr.Node].size(); i++) {
                    Edge e = graph[curr.Node].get(i);
                    int u = e.src;
                    int v = e.dest;
                    if (dist[u] + e.weight < dist[v]) { // relaxation
                        dist[v] = dist[u] + e.weight;
                        pq.add(new Pair(v, dist[v]));
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            System.out.print(dist[i] + " ");
        }
        System.out.println();
    }

    // Bellman ford -> DP , perform relaxation V-1 times
    // Not works for -ve weight cycles
    public static void BellmanFord(ArrayList<Edge>[] graph, int src, int V) {
        int[] dist = new int[V];
        for (int i = 0; i < V; i++) {
            if (i != src) {
                dist[i] = Integer.MAX_VALUE;
            }
        }

        for (int k = 0; k < V-1; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < graph[i].size(); j++) {
                    Edge e = graph[i].get(j);
                    int u = e.src;
                    int v = e.dest;
                    if(dist[u] + e.weight < dist[v] && dist[u]!=Integer.MAX_VALUE){
                        dist[v] = dist[u] + e.weight;
                    }
                }
            }
        }
        for (int i = 0; i < dist.length; i++) {
            System.out.print(dist[i] + " ");
        }
    }

    public static void main(String[] args) {
        System.out.println("All shortest path algos");
        int V = 6;
        ArrayList<Edge>[] graph = new ArrayList[V];
        CreateGraph(graph);
        for (int i = 0; i < V; i++) {
            showNeighbours(graph, i);
        }
        Dijstras(graph, 0, V);
        BellmanFord(graph, 0, V);
    }
}
