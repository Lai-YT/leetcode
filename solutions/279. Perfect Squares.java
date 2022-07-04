class Solution {
    /**
     * This is a breadth-first search approach which refers to
     * https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)/73744
     * @param n An positive integer
     * @return The least number of perfect square numbers that sum to n; 0 if n <= 0
     */
    public int numSquares(int n) {
        /* the nodes that have neighbors to be visited */
        final Queue<Integer> q = new LinkedList<>();
        final Set<Integer> visited = new HashSet<>();
        int depth = 0;
        
        q.offer(0);  /* start node */
        while (!q.isEmpty()) {
            int size = q.size();  /* same level nodes */
            ++depth;
            while (size-- > 0) {
                int node = q.poll();
                for (int i = 1; i * i <= n; i++) {
                    int neighbor = node + i * i;
                    if (neighbor == n) {
                        return depth;
                    }
                    if (neighbor > n) {
                        break;  /* all others in this loop will also exceed */
                    }
                    if (!visited.contains(neighbor)) {
                        q.offer(neighbor);
                        visited.add(neighbor);
                    }
                }
            }
        }
​
        return 0;
    }
}
