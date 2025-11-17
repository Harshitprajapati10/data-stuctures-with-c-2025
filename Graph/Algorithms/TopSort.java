package Graph.Algorithms;

import java.util.ArrayList;
import java.util.Stack;

public class TopSort { // applicable in DAGs
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
          5 --> 0 <-- 4
          |           |
          v           v  
          2 --> 3 --> 1
         */
     
        graph[5].add(new Edge(5, 0));
        graph[5].add(new Edge(5, 2));
        graph[4].add(new Edge(4, 0));
        graph[4].add(new Edge(4, 1));
        graph[3].add(new Edge(3, 1));
        graph[2].add(new Edge(2, 3));
    
    }   

    // Topological Sort using DFS
    public static void TopologicalSort(ArrayList<Edge>[] graph, int V){
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<V; i++){
            if(!visited[i]){
                TopologicalSortUtil(graph, i, visited, stack);
            }
        }
        while(!stack.isEmpty()){
            System.out.print(stack.pop() + " ");
        }
    }
    public static void TopologicalSortUtil(ArrayList<Edge>[] graph, int curr, boolean[] visited, Stack<Integer> stack){
        visited[curr] = true;
        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(!visited[e.dest]){
                TopologicalSortUtil(graph, e.dest, visited, stack);
            }
        }
        stack.push(curr); 
    }


    public static void main(String[] args) {
        int V = 6;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        System.out.println("Topological Sort of the given graph:");
        TopologicalSort(graph, V);
    }
}
