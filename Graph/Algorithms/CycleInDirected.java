package Graph.Algorithms;

import java.util.ArrayList;

public class CycleInDirected {
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
         0--->1<---2<-------
                    |       |    
                   |    --> 4
                   |    |
                   --->3
         */
        graph[0].add(new Edge(0, 1));
        graph[2].add(new Edge(2, 1));
        graph[2].add(new Edge(2, 3));
        graph[3].add(new Edge(3, 4));
        graph[4].add(new Edge(4, 2));
        
    }

    // findneighbours all
    public static void findNeighbours(ArrayList<Edge>[] graph, int v){
        for(int i=0; i<graph[v].size(); i++){
            Edge e = graph[v].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }

    // Detect cycle in directed graph using DFS
    public static boolean hasCycle(ArrayList<Edge>[] graph, int curr, boolean[] visited, boolean[] recStack){
        visited[curr] = true;
        recStack[curr] = true;

        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(recStack[e.dest]){
                return true;
            }
            if(!visited[e.dest]){
                if(hasCycle(graph, e.dest, visited, recStack)){
                    return true;
                }
            }
        }
        recStack[curr] = false;
        return false;
    }

    public static boolean detectCycle(ArrayList<Edge>[] graph, int V){
        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];

        for(int i = 0; i < V; i++){
            if(!visited[i]) {
                if(hasCycle(graph, i, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int V = 5;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        for(int i=0; i<V; i++){
            findNeighbours(graph, i);
        }

        System.out.println("Cycle exists? " + detectCycle(graph, V));
    
    }
}
