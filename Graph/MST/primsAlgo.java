package Graph.MST;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class primsAlgo {
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
        int cost;

        public Pair(int n, int d) {
            this.Node = n;
            this.cost = d;
        }

        @Override
        public int compareTo(Pair p) {
            return this.cost - p.cost; // sort in order of cost in PQ in ascending order
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


    // prims algo for MST
    
    public static void PrimsMST(ArrayList<Edge>[] graph, int V){
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean vis[] = new boolean[V];
        pq.add(new Pair(0,0));
        int mstcost = 0;

        while (!pq.isEmpty()) {
            Pair curr = pq.remove();
            if(!vis[curr.Node]){
                vis[curr.Node] = true;
                mstcost += curr.cost;

                for (int i = 0; i < graph[curr.Node].size(); i++) {
                    Edge e = graph[curr.Node].get(i);
                    if(!vis[e.dest]){
                        pq.add(new Pair(e.dest, e.weight));
                    }
                }
            }
        }

        System.out.println("Min cost of mst : " + mstcost);
    }

    public static void findAllNeighbours(ArrayList<Edge>[] graph, int V) {
        for (int i = 0; i < graph[V].size(); i++) {
            Edge e = graph[V].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int V = 4;
        ArrayList<Edge>[] graph = new ArrayList[V];
        CreateGraph(graph);
        for (int i = 0; i < V; i++) {
            findAllNeighbours(graph, i);
        }

        PrimsMST(graph, V);
    }
}
