public class Subject implements Comparable<Subject> {
	String nameOfSubject;
	String nameOfTeacher;
	Integer scoreOfExam;
	Subject(){
		nameOfSubject = new String("");
		nameOfTeacher = new String("");
		scoreOfExam = new Integer(0);
	}
	Subject(String nameOfS, String nameOfT, int scoreOfE){
		nameOfSubject = new String(nameOfS);
		nameOfTeacher = new String(nameOfT);
		scoreOfExam = new Integer(scoreOfE);
	}
	Subject(Subject x){
		nameOfSubject = x.nameOfSubject;
		nameOfTeacher = x.nameOfTeacher;
		scoreOfExam = x.scoreOfExam;
	}
	public int compareTo(Subject x){
		return this.scoreOfExam.compareTo(x.scoreOfExam);
	}
	public int getScoreOfExam(){
		return this.scoreOfExam;
	}
	public String toString(){
		String s = new String();
		s += nameOfSubject;
		s += " ";
		s += nameOfTeacher;
		s += " ";
		s += scoreOfExam.toString();
		return s;
	}
}