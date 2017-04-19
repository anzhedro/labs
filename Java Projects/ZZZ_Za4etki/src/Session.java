public class Session implements Comparable<Session>{
	Integer numberOfSession;
	Integer countOfExams;
	Subject []arrayOfSubjects;
	Double averageScore;
	Integer count;
	Session(){
		numberOfSession = new Integer(0);
		countOfExams = new Integer(0);
		arrayOfSubjects = new Subject[12];
		averageScore = new Double(0.0);
		count = new Integer(0);
	}
	Session(int numberOfS, int countOfE){
		numberOfSession = new Integer(numberOfS);
		countOfExams = new Integer(countOfE);
		arrayOfSubjects = new Subject[countOfE];
		averageScore = new Double(0.0);
		count = new Integer(0);
	}
	Session(Session x){
		numberOfSession = new Integer(x.numberOfSession);
		countOfExams = new Integer(x.countOfExams);
		arrayOfSubjects = new Subject[countOfExams];
		arrayOfSubjects = (Subject[])x.arrayOfSubjects.clone();
		averageScore = new Double(x.averageScore);
		count = new Integer(x.count);
	}
	public void toCountAverageScore(){
		for (int i = 0; i < countOfExams; i++)
			this.averageScore += arrayOfSubjects[i].getScoreOfExam();
		this.averageScore /= countOfExams;
	}
	public int compareTo(Session x){
		return this.numberOfSession.compareTo(x.numberOfSession);
	}
	public double getAverageScore(){
		return this.averageScore;
	}
	public void setNumberOfSession(int x){
		numberOfSession = x;
	}
	public void setNumberOfExams(int x){
		countOfExams = x;
	}
	public void add(Subject x){
		arrayOfSubjects[count] = x;
		count++;
	}
	public String toString(){
		String s = new String();
		for (int i = 0; i < countOfExams; i++){
			s += arrayOfSubjects[i].toString();
			s += '\n';			
		}
		return s;
	}
}