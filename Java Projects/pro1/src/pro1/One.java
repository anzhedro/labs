package pro1;

import java.io.*;
import java.text.*;

public class One {

	public static void main(String[] args) {
		
		int k = 0, n, x = 0;
		double l, s1, s2;
		
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		try	{
			String line = br.readLine();
			k =  Integer.parseInt(line);
			line = br.readLine();
			x =  Integer.parseInt(line);
		}
		catch (NumberFormatException q) {
			System.out.println("Не целое число!");
		}
		catch (IOException q) {
			System.out.println("Ошибка чтения с клавиатуры!");
		}
	
		double e = Math.pow(10, -k);
		
		
		NumberFormat formatter = NumberFormat.getNumberInstance();
		formatter.setMaximumFractionDigits(k + 1);
		System.out.println("Epsilon = " + formatter.format(e));
		System.out.println("Exp1 = " + formatter.format(Math.pow(Math.E, x)));
		s1 = 1;
		s2 = s1 + x;
		n = 1;
		l = x;
		while (Math.abs(s2 - s1) > e / 10.0) 
		{
			s1 = s2;
			n++;
			l = (l * x) / n;
			s2 += l;	
		}
		System.out.println("Exp2 = " + formatter.format(s2));
		System.out.println("Конец!");
	}
}
