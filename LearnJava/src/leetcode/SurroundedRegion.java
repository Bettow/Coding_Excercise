package leetcode;

import java.util.LinkedList;
import java.util.Queue;

//Note: Mark the Point when enqueue, not pop out.

public class SurroundedRegion {
    public class Point {
        public int x, y;
        public Point(int i, int j) {
            this.x = i;
            this.y = j;
        }
    }
    
    public void solve(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int m = board.length;
        if (m ==0) return;
        int n = board[0].length;
        if (n ==0) return;
        
        final char MARK = 'M';
        Queue<Point> pq = new LinkedList<Point>();
        for (int i =0; i < m; ++i) {
            if (board[i][0] == 'O') {
                 board[i][0] = MARK;
                pq.add(new Point(i, 0));
            }
            if (board[i][n-1] == 'O') {
                 board[i][n-1] = MARK;
                pq.add(new Point(i, n-1));
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                 board[0][i] = MARK;
                pq.add(new Point(0, i));
            }
            if (board[m-1][i] == 'O') {
                 board[m-1][i] = MARK;
                pq.add(new Point(m-1, i));
            }
        }
        
        int d[][] = {{0, -1}, {-1,0}, {0,1}, {1, 0}};        
        while (!pq.isEmpty()) {
            Point p = pq.poll();
            int x = p.x;
            int y = p.y;
            for (int i =0;  i< 3; ++i) {
                int nx = x+d[i][0];
                int ny = y+d[i][1];
                if (nx >=0 && nx <m && ny >=0 && ny <n) {
                    if (board[nx][ny] == 'O') {
                        pq.add(new Point(nx, ny));
                        board[nx][ny] = MARK;
                    }   
                }
            }
        }
        
        for (int i = 0; i< m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == MARK)
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
                
            }
        }
            
    }

}
