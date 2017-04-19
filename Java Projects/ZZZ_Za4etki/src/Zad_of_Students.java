import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
public class Zad_of_Students {
	static MyScanner in;
	static PrintWriter out;
	public static void menu(){
		System.out.println("1. Show of losers.");
		System.out.println("2. Sort by average score.");
		System.out.println("3. Show Top-3.");
		System.out.println("4. Show the Container.");
		System.out.println("5. Exit.");
	}
	public static void main(String[] args) {
		int n; // count of students
		int count; // count of session
		int numOfS; // number of session
		int countOfE; // count of exams
		String nameOfT; // name of the teacher
		String nameOfS; // name of subject
		int scoreOfE; // score of exam			
		String firstNameIn, lastNameIn; // for input
		RecordBook []arrayOfStudents;
		try{
			in = new MyScanner(new FileReader("Input.txt"));
			out = new PrintWriter("Output.txt");						
			n = in.nextInt();
			arrayOfStudents = new RecordBook[n];
			for (int i = 0; i < n; i++){
				firstNameIn = in.nextToken();
				lastNameIn = in.nextToken();
				count = in.nextInt();
				arrayOfStudents[i] = new RecordBook(firstNameIn, lastNameIn, count);
				for (int j = 0; j < count; j++){
					numOfS = in.nextInt();
					countOfE = in.nextInt();
					Session session = new Session(numOfS, countOfE); // for input					
					for (int k = 0; k < countOfE; k++){
						nameOfS = in.nextToken();
						nameOfT = in.nextToken();
						scoreOfE = in.nextInt();						
						Subject sub = new Subject(nameOfS, nameOfT, scoreOfE);
						session.add(sub);
					}
					session.toCountAverageScore();
					arrayOfStudents[i].arrayOfSession[j] = session;
				}
			}
			for (int i = 0; i < arrayOfStudents.length; i++){
				Arrays.sort(arrayOfStudents[i].arrayOfSession);
			}
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			String s1;
			int v;
			do{
				menu();
				s1 = br.readLine();
				int t = 0;
				v = Integer.parseInt(s1);
				if (v == 1){
					System.out.print("Enter a number of session: ");
					s1 = br.readLine();
					v = Integer.parseInt(s1);
					for (int i = 0; i < arrayOfStudents.length; i++){
						for (int j = 0; j < arrayOfStudents[i].countOfSession; j++){
							if ( arrayOfStudents[i].arrayOfSession[j].numberOfSession == v){
								for (int k = 0; k < arrayOfStudents[i].arrayOfSession[j].countOfExams; k++){
									if ( arrayOfStudents[i].arrayOfSession[j].arrayOfSubjects[k].scoreOfExam < 4){
										if (t == 0){
											System.out.println("Losers in "+v+"-th session.");
											t = 1;
										}
										System.out.println(arrayOfStudents[i].firstName+" "+arrayOfStudents[i].lastName);										
										break;
									}
								}
								break;
							}
						}
					}
					if (t == 0)
						System.out.println("In "+v+"-th session are no losers.");
				}
				else{
					if (v == 2){
						System.out.print("Enter a number of session: ");
						s1 = br.readLine();
						v = Integer.parseInt(s1);
						RecordBook []mass;
						mass = new RecordBook[arrayOfStudents.length];
						for (int i = 0; i < arrayOfStudents.length; i++){
							mass[i] = new RecordBook(arrayOfStudents[i].firstName, arrayOfStudents[i].lastName, 1);						
							mass[i].arrayOfSession[0] = arrayOfStudents[i].arrayOfSession[v-1];							
						}
						Arrays.sort(mass, Collections.reverseOrder());	
						for (int i = 0; i < mass.length; i++)
							System.out.println(mass[i].firstName+" "+mass[i].lastName);
					}
					else{
						if (v == 3){
							System.out.print("Enter a number of session: ");
							s1 = br.readLine();
							v = Integer.parseInt(s1);
							RecordBook []mass;
							mass = new RecordBook[arrayOfStudents.length];
							for (int i = 0; i < arrayOfStudents.length; i++){
								mass[i] = new RecordBook(arrayOfStudents[i].firstName, arrayOfStudents[i].lastName, 1);						
								mass[i].arrayOfSession[0] = arrayOfStudents[i].arrayOfSession[v-1];							
							}
							Arrays.sort(mass, Collections.reverseOrder());	
							System.out.println("Top - 3:");
							int q = 3;
							if (mass.length < 3)
								q = mass.length;
							for (int i = 0; i < q; i++)
								System.out.println(mass[i].firstName+" "+mass[i].lastName);
						}
						else{
							if (v == 4){
								for (int i = 0; i < arrayOfStudents.length; i++){
									System.out.println(arrayOfStudents[i]);
								}
							}
						}
					}
				}
			}
			while(v != 5);
			System.out.println("The End.");
		}
		catch(IOException ioe){
			out.print("Error");
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

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }
    }
}
