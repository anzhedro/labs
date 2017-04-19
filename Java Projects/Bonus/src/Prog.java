import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;


public class Prog {
	
	static MyScanner in;
    static PrintWriter out;
	
	public static void main(String[] args) throws IOException {
        //in = new MyScanner(new FileReader("inp.in"));
        //out = new PrintWriter("outp.out");
        //out.close();
    }
	
	static class MyScanner {
        private StringTokenizer st;
        private BufferedReader br;
        public MyScanner(Reader r) {
            br = new BufferedReader(r);
        }
        public String nextToken() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }
        public String nextWord() throws IOException {
            return nextToken();
        }
    }

}
