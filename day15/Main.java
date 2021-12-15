/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

import java.util.PriorityQueue;

class Main {
  public static void main(String[] args) {
    Kattio sc = new Kattio(System.in, System.out);    
    int[][] arr = new int[100][100];
    int[][] full = new int[500][500];
    int[][] dp = new int[500][500];
    int n = 500;

    int i = 0;
    while (sc.hasMoreTokens()) {
      String line = sc.getWord();
      for (int j = 0; j < 100; j++) {
        arr[i][j] = line.charAt(j)-'0';
      }
      i++;
    }
    for (i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 100; k++) {
          for (int l = 0; l < 100; l++) {
            int q = arr[k][l] + i + j;
            if (q > 9) q = q - 9;
            full[i*100+k][j*100+l] = q;
          }
        }
      }
    }
/*
    for (i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sc.print(full[i][j]);
      }
      sc.println();
    }
*/
/*
    for (i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sc.print(arr[i][j] + " ");
      }
      sc.println();
    }
*/
    PriorityQueue<triplet> heap = new PriorityQueue<>();
    heap.add(new triplet(0, 0, 0));

    while (true) {
      triplet cur = heap.poll();
      int dis = cur.dis;
      int x = cur.x;
      int y = cur.y;

      if (dp[x][y] != 0) continue;
      dp[x][y] = dis;
      if (x == n-1 && y == n-1) break;
      
      if (x-1 >= 0 && dp[x-1][y] == 0) heap.add(new triplet(dis + full[x-1][y], x-1, y));
      if (x+1 < n && dp[x+1][y] == 0) heap.add(new triplet(dis + full[x+1][y], x+1, y));
      if (y-1 >= 0 && dp[x][y-1] == 0) heap.add(new triplet(dis + full[x][y-1], x, y-1));
      if (y+1 < n && dp[x][y+1] == 0) heap.add(new triplet(dis + full[x][y+1], x, y+1));
    }
/*
    for (i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sc.print(dp[i][j] + " ");
      }
      sc.println();
    }
*/
    sc.println(dp[n-1][n-1]);

    sc.close();
  } 
}

class triplet implements Comparable<triplet> {
  int dis;
  int x;
  int y;
  public triplet(int a, int b, int c) {
    dis = a;
    x = b;
    y = c;
  }

  @Override
  public String toString() {
    return dis + " " + x + " " + y;
  }

  @Override
  public int compareTo(triplet other) {
    return this.dis - other.dis;
  }
}


class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
