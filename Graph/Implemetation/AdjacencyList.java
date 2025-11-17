// Implement graph using adjacency list 

import java.util.ArrayList;

public class AdjacencyList{
    static class Edge{
        int src;
        int dest;
        public Edge(int s, int d){
            this.src = s;
            this.dest = d;
        }
    }
    public static void createGraph(ArrayList<Edge>[] graph){
        for(int i=0; i<graph.length; i++){
            graph[i] = new ArrayList<Edge>();
        }
        /*
         0 -- 2----3 
            |   /
            1
         */
        graph[0].add(new Edge(0, 2));
        graph[1].add(new Edge(1, 2));
        graph[1].add(new Edge(1, 3));
        graph[2].add(new Edge(2, 0));
        graph[2].add(new Edge(2, 1));
        graph[2].add(new Edge(2, 3));
        graph[3].add(new Edge(3, 1));
        graph[3].add(new Edge(3, 2));
    }

    // findneighbours all
    public static void findNeighbours(ArrayList<Edge>[] graph, int v){
        for(int i=0; i<graph[v].size(); i++){
            Edge e = graph[v].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int V = 4;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        for(int i=0; i<V; i++){
            findNeighbours(graph, i);
        }
    }
}