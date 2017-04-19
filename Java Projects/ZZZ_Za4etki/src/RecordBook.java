public class RecordBook implements Comparable<RecordBook>{
	String firstName;
	String lastName;
	Session []arrayOfSession;
	Integer countOfSession;
	RecordBook(){
		firstName = new String("");
		lastName = new String("");
		arrayOfSession = new Session[10];
		countOfSession = new Integer(0);
	}
	RecordBook(String firstN, String lastN, int countOfS){
		firstName = new String(firstN);
		lastName = new String(lastN);
		countOfSession = new Integer(countOfS);
		arrayOfSession = new Session[countOfS];
	}
	public int compareTo(RecordBook x){
		return this.arrayOfSession[0].averageScore.compareTo(x.arrayOfSession[0].getAverageScore());
	}
	public String toString(){
		String s = new String();
		s += firstName;
		s += " ";
		s += lastName;
		s += '\n';
		for (int i = 0; i < countOfSession; i++){
			s += Integer.toString(i+1);
			s += " session";
			s += '\n';
			s += arrayOfSession[i].toString();
		}
		return s;
	}
}
