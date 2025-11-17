package Graph.Algorithms;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {

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
        // 1 --- 3
        //  /       |\
        // 0        | 5---6
        //  \       |/
        //   2 --- 4
        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 2));
        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 3));
        graph[2].add(new Edge(2, 0));
        graph[2].add(new Edge(2, 4));
        graph[3].add(new Edge(3, 1));
        graph[3].add(new Edge(3, 4));
        graph[3].add(new Edge(3, 5));
        graph[4].add(new Edge(4, 2));
        graph[4].add(new Edge(4, 3));
        graph[4].add(new Edge(4, 5));
        graph[5].add(new Edge(5, 3));
        graph[5].add(new Edge(5, 4));
        graph[5].add(new Edge(5, 6));
        graph[6].add(new Edge(6,5));
        
    }

    // findneighbours all
    public static void findNeighbours(ArrayList<Edge>[] graph, int v){
        for(int i=0; i<graph[v].size(); i++){
            Edge e = graph[v].get(i);
            System.out.print(e.dest + " ");
        }
        System.out.println();
    }


    // Breadth First Search traversal -> 0123456
    public static void BreadthFirstSearch(ArrayList<Edge>[] graph,int V){
        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0] = true;
        while(!queue.isEmpty()){
            int curr = queue.remove();
            if(visited[curr] == false){
                System.out.print(curr + " ");
                visited[curr] = true;
            }
            for(int i=0; i<graph[curr].size(); i++){
                Edge e = graph[curr].get(i);
                if(visited[e.dest] == false){
                    queue.add(e.dest);
                }
            }
        }
    }


    // Depth First Search traversal -> 0134256
    public static void DepthFirstSearch(ArrayList<Edge>[] graph, int curr, boolean[] visited){
        System.out.print(curr + " ");
        visited[curr] = true;
        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(visited[e.dest] == false){
                DepthFirstSearch(graph, e.dest, visited);
            }
        }
    }

    // Print all paths from source to destination
    public static void printALLPaths(ArrayList<Edge>[] graph, int curr, int dest, boolean[] visited, String pathSoFar){
        if(curr == dest){
            System.out.println(pathSoFar);
            return;
        }
        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(!visited[e.dest]){
                visited[curr] = true;
                printALLPaths(graph, e.dest, dest, visited, pathSoFar + curr);
                visited[curr] = false;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("BFS Algorithm Implementation");
        int V = 7;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        for(int i=0; i<V; i++){
            findNeighbours(graph, i);
        }

        System.out.println("BFS Traversal of the graph:");
        BreadthFirstSearch(graph, V);

        System.out.println("\nDFS Traversal of the graph:");
        boolean[] visited = new boolean[V];
        DepthFirstSearch(graph, 0, visited);

        System.out.println("\nAll Paths from source to destination (0 to 6):");
        boolean[] visitedForPaths = new boolean[V];
        printALLPaths(graph, 0, 6, visitedForPaths, "");
    }
}
