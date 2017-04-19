package prolab3;
public class trey implements Comparable<trey> {
	private Double x1, x2, x3, y1, y2, y3, square;
	trey(double a, double b, double c, double d, double e, double f)
	{
		x1 = a; x2 = b; x3 = c; y1 = d; y2 = e; y3 = f;
		double l1, l2, l3;
		l1 = Math.sqrt(Math.pow((x1 - x2), 2) +  Math.pow((y1 - y2), 2));
		l2 = Math.sqrt(Math.pow((x1 - x3), 2) +  Math.pow((y1 - y3), 2));
		l3 = Math.sqrt(Math.pow((x2 - x3), 2) +  Math.pow((y2 - y3), 2));
		double p;
		p = (l1 + l2 + l3) / 2;
		square = Math.sqrt((p - l1)*(p - l2)*(p - l3)*p);
	}
	public double getX1()
	{
		return x1;
	}
	public double getX2()
	{
		return x2;
	}
	public double getX3()
	{
		return x3;
	}
	public double getY1()
	{
		return y1;
	}
	public double getY2()
	{
		return y2;
	}
	public double getY3()
	{
		return y3;
	}
	public double getSquare()
	{
		return square;
	}
	public int compareTo(trey X){
		 return square.compareTo(X.square);
		}

}