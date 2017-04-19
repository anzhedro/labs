import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	public static class Hotel implements Comparable<Hotel>{
		String City;
		String HotelName;
		int Star;
		Hotel(String a, String b, int c)
		{
			City = new String(a);
			HotelName = new String(b);
			Star = c;
		}
		public Hotel() {
			City = new String("");
			HotelName = new String("");
			Star = 0;
		}
		
		public String getCity(){
			return City;
		}
		public String getHotelName(){
			return HotelName;
		}
		public int getStar(){
			return Star;
		}
		public int compareTo(Hotel X){
			return City.compareTo(X.City);
			}
	}
	
	public static void menu()
	{
		System.out.println("1 - Информация по городам;");
		System.out.println("2 - Отели в городе;");
		System.out.println("3 - Города в которых есть отель;");
		System.out.println("4 - Звезды по городам;");
		System.out.println("5 - Выход!");
	}
	
	static MyScanner in;
    static PrintWriter out;
	public static void main(String[] args) throws IOException {
		Hotel hot;
		in = new MyScanner(new FileReader("in.txt"));
		ArrayList<Hotel> Mass = new ArrayList<Hotel>();
		int n = Integer.parseInt(in.nextWord());
		for (int i = 0; i < n; i++)
		{
			hot = new Hotel(in.nextWord(), in.nextWord(), Integer.parseInt(in.nextWord()));
			Mass.add(hot);
		}  
		Collections.sort(Mass);
		int flag = -1;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		do {
		menu();
	    flag = Integer.parseInt(br.readLine());
		switch (flag)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				String key = ((Mass.get(i)).getCity());
				System.out.println(("      " + (Mass.get(i)).getCity())  + ":");
				int j = 0;
				for (int k = i; k < n; k++)
					if (key.equals((Mass.get(k)).getCity()))
					{
						j++;
						System.out.println("- " + (Mass.get(k)).getHotelName() + " " + (Mass.get(k)).getStar());

					}
					else
						break;
				i += j-1;
			}
			break;
		case 2:
			String gorod = br.readLine();
			for (int i = 0; i < n; i++)
			{			
				if ((Mass.get(i).getCity()).equals(gorod))
					System.out.println((Mass.get(i)).getHotelName() + " " + (Mass.get(i)).getStar());
			}
			
			break;
		case 3:
			String hote = br.readLine();
			for (int i = 0; i < n; i++)
			{
				if ((Mass.get(i).getHotelName()).equals(hote))
					System.out.println((Mass.get(i)).getCity() + " " + (Mass.get(i)).getHotelName() + " " + (Mass.get(i)).getStar());
			}
			
			break;
		case 4:
			for (int i = 0; i < n; i++)
			{
				int[] a = new int[6];
				for (int z = 0; z < 6; z++)
					a[z] = 1;
				
				String key = ((Mass.get(i)).getCity());
				int j = 0;
				for (int k = i; k < n; k++)
					if (key.equals((Mass.get(k)).getCity()))
					{
						a[(Mass.get(k)).getStar()] ++;
						j++;
					}
					else
						break;
				i += j-1;
				System.out.print(((Mass.get(i)).getCity())  + ": ");
				for (int z = 0; z < 6; z++)
					if (a[z] > 1)
						System.out.print(z  + " ");
				System.out.println();
			}
			break;
		}
		}
		while (flag !=5);		
	}
	
	static class MyScanner {
        private StringTokenizer st;
        private BufferedReader br;
        public MyScanner(Reader r) {
            br = new BufferedReader(r);
        }
        public String nextToken() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine(), " ;");
            }
            return st.nextToken();
        }
        public String nextWord() throws IOException {
            return nextToken();
        }
    }

}
