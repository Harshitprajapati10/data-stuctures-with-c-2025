package Graph.Algorithms;

import java.util.ArrayList;

public class CycleInUndirected {
    static class Edge {
        int src;
        int dest;

        Edge(int s, int d) {
            this.src = s;
            this.dest = d;
        }
    }

    static void createGraph(ArrayList<Edge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        /*
         * 0 --- 1----2----3
         * |    |
         * --- 4 ----5
         */
        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 4));
        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 2));
        graph[1].add(new Edge(1, 4));
        graph[2].add(new Edge(2, 1));
        graph[2].add(new Edge(2, 3));
        graph[3].add(new Edge(3, 2));
        graph[4].add(new Edge(4, 0));
        graph[4].add(new Edge(4, 1));
        graph[4].add(new Edge(4, 5));
        graph[5].add(new Edge(5, 4));
    }

    static void findAllNeighbours(ArrayList<Edge>[] graph, int V){
        for (int i = 0; i < graph[V].size(); i++) {
            Edge e = graph[V].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }


    static boolean hasCycle(ArrayList<Edge>[] graph, boolean vis[], int curr, int parent){
        vis[curr] = true;
        for (int i = 0; i < graph[curr].size(); i++) {
            Edge e = graph[curr].get(i);
            // condition for cycle -> if dest is visted and not parent
            if(vis[e.dest] && e.dest != parent){
                return true;
            }
            else if(!vis[e.dest]){
                if(hasCycle(graph, vis, e.dest, curr)){
                    return true;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        for (int i = 0; i < V; i++) {
            findAllNeighbours(graph, i);
        }
        System.out.println(hasCycle(graph, new boolean[V], 0, -1));
    }
}
