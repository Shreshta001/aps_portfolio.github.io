import java.util.PriorityQueue;
import java.util.*;

public class UniformCostSearch {

    private static final int INF = Integer.MAX_VALUE;

    /**
     * Finds the shortest path from the source vertex to the destination vertex in the given graph.
     *
     * @param edges The edges of the graph.
     * @param n The number of vertices in the graph.
     * @param source The source vertex.
     * @param destination The destination vertex.
     * @return The minimum cost of the shortest path.
     */
    public static int findShortestPath(int[][] edges, int n, int source, int destination) {
        // Create a priority queue to store the nodes to be expanded.
        // The priority queue is sorted in ascending order of the cost of the nodes.
        PriorityQueue<Node> queue = new PriorityQueue<>((a, b) -> a.cost - b.cost);

        // Initialize the visited array.
        boolean[] visited = new boolean[n];

        // Create a graph.
        // The graph is represented as a hash map, where the key is the vertex and the value is a set of adjacent nodes.
        HashMap<Integer, HashSet<Node>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new HashSet<Node>());
        }
        for (int i = 0; i < edges.length; i++) {
            graph.get(edges[i][0]).add(new Node(edges[i][1], edges[i][2]));
        }

        // Create a node for the source vertex.
        Node startNode = new Node(source, 0);

        // Add the source vertex to the queue.
        queue.add(startNode);

        // Initialize the minimum cost to infinity.
        int minCost = INF;

        while (!queue.isEmpty()) {
            // Get the node with the minimum cost from the queue.
            Node curNode = queue.poll();
            int cst = curNode.cost;

            // If the current node is the destination, then we have found the shortest path.
            if (curNode.vertex == destination) {
                minCost = Math.min(minCost, cst);
            } else {
                // Mark the current node as visited.
                visited[curNode.vertex] = true;

                // Iterate over the adjacent nodes of the current node.
                for (Node neighbor : graph.get(curNode.vertex)) {
                    // If the neighbor is not visited, then add it to the queue with the updated cost.
                    if (!visited[neighbor.vertex]) {
                        queue.add(new Node(neighbor.vertex, neighbor.cost + cst));
                    }
                }
            }
        }

        return minCost;
    }

    /**
     * A node in the graph.
     */
    private static class Node implements Comparable<Node> {
        int vertex;
        int cost;

        /**
         * Creates a new node with the given vertex and cost.
         *
         * @param vertex The vertex of the node.
         * @param cost The cost of the node.
         */
        public Node(int vertex, int cost) {
            this.vertex = vertex;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return this.cost - other.cost;
        }
    }

    public static void main(String[] args) {
        // Create the graph.
        int[][] graph = new int[][]{
            {0, 3, 10},
            {0, 1, 5},
            {1, 5, 15},
            {1, 2, 4},
            {2, 4, 8},
            {3,5,11},
            {5,4,4}
        };

        // The source vertex.
        int source = 0;

        // The destination vertex.
        int destination = 4;

        // Find the shortest path from the source vertex to the destination vertex.
        int minCost = UniformCostSearch.findShortestPath(graph, 6, source, destination);
