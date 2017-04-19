package prolab3;
import java.io.*;
import java.util.*;
public class STROKI {
	static MyScanner in;
    static PrintWriter out;
    public static void main(String[] args) throws IOException {
        in = new MyScanner(new FileReader("inp.in"));
        out = new PrintWriter("outp.out");
        int n = Integer.parseInt(in.nextWord());
    	System.out.println(n);
    	trey Mass[] = new trey[n];
    	for (int i = 0; i < n; i++)
    	{
    		Mass[i] = new trey(Double.parseDouble(in.nextWord()), Double.parseDouble(in.nextWord()), Double.parseDouble(in.nextWord()), Double.parseDouble(in.nextWord()), Double.parseDouble(in.nextWord()), Double.parseDouble(in.nextWord()));
    	}
    	Arrays.sort(Mass);
    	for (int i = 0; i < n; i++) {
    		System.out.println(Mass[i].getX1() + " " + Mass[i].getX2() + " " + Mass[i].getX3() + " " + Mass[i].getY1() + " " + Mass[i].getY2() + " " + Mass[i].getY3() + " " + Mass[i].getSquare());
    		out.println(Mass[i].getX1() + " " + Mass[i].getX2() + " " + Mass[i].getX3() + " " + Mass[i].getY1() + " " + Mass[i].getY2() + " " + Mass[i].getY3() + " " + Mass[i].getSquare());
        }        
        out.close();
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