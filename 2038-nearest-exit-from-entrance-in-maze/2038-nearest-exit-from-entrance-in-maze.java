class Solution {
     public boolean check(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    public int nearestExit(char[][] maze, int[] entrance) {
         int m = maze.length;
        int n = maze[0].length;
        int x = entrance[0];
        int y = entrance[1];

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        maze[x][y] = '+';
        int step = 0;

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] current = q.poll();
                int p = current[0];
                int r = current[1];

                if (p == 0 || r == 0 || p == m - 1 || r == n - 1) {
                    if (p != entrance[0] || r != entrance[1]) {
                        return step;
                    }
                }

                for (int j = 0; j < 4; j++) {
                    int nx = p + dx[j];
                    int ny = r + dy[j];

                    if (check(nx, ny, m, n) && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
            step++;
        }
        return -1;
    }
}