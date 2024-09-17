

class Solution {
    public int maxStarSum(int[] vals, int[][] edges, int k) {
        // Initialize adjacency list for the graph
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < vals.length; i++) {
            adj.add(new ArrayList<>());
        }

        // Build adjacency list from edges
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        int maxsum = Integer.MIN_VALUE;

        // Iterate through each node
        for (int i = 0; i < vals.length; i++) {
            int sum = vals[i];  // Start the sum with the current node's value
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

            // Add adjacent node values to the priority queue if they are positive
            for (int neighbor : adj.get(i)) {
                if (vals[neighbor] > 0) {
                    pq.offer(vals[neighbor]);
                }
            }

            // Take up to 'k' largest positive adjacent values
            int x = k;
            while (!pq.isEmpty() && x > 0) {
                sum += pq.poll();  // Add the largest positive value
                x--;
            }

            // Update the maximum sum
            maxsum = Math.max(maxsum, sum);
        }

        return maxsum;
    }
}
