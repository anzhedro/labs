/*1. Поменять местами строку, содержащую элемент с наибольшим значением в матрице со строкой, 
 * содержащей элемент с наименьшим значением. Вывести на экран полученную матрицу. 
 * Для каждой строки с нулевым элементом на главной диагонали вывести ее номер и значение наибольшего 
 * из элементов этой строки.*/
package pro2;

import java.io.*;

public class two {

	public static void main(String[] args) {
		
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		int n = 0, m = 0;
				
		try
		{
			n =  Integer.parseInt(br.readLine());
			m =  Integer.parseInt(br.readLine());
		}
		catch (NumberFormatException e) 
		{
			System.out.println("Не целое число");
		}
		catch (IOException e)
		{
			System.out.println("Ошибка чтения с клавиатуры");
		}
		int[][] Matrix = new int[n][m];
		try
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					{
					Matrix[i][j] = Integer.parseInt(br.readLine());
			    	}
		}
		catch (NumberFormatException e) 
		{
			System.out.println("Не целое число");
		}
		catch (IOException e)
		{
			System.out.println("Ошибка чтения с клавиатуры");
		}
		
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < m; j++)
			{
				System.out.print(Matrix[i][j] + " ");
			}
			System.out.println();
		  }
		
		int el = Matrix[0][0], el1 = Matrix[0][0], imin = 0, imax = 0; 

		
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < m; j++)
			{
				if (Matrix[i][j] < el) 
				{
					imin = i;
					el = Matrix[i][j]; 
				}
				if (Matrix[i][j] > el1) 
				{
					imax = i;
					el1 = Matrix[i][j];
				}
			}
		  }
		
		System.out.println("Меняем местами " + imin + " c " + imax + " cтрокой!");
		
		
		int key = 0;
		for (int i = 0; i < m; i++)
		{
			key = Matrix[imin][i];
			Matrix[imin][i] = Matrix[imax][i];
			Matrix[imax][i] = key;
		}
		
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < m; j++)
			{
				System.out.print(Matrix[i][j] + " ");
			}
			System.out.println();
		  }
		
		if (n > m)
			key = m;
		else
			key = n;
				
		for (int i = 0; i < key; i++)
		  {
			if (Matrix[i][i] == 0)
			{
				System.out.println("В " + i + " строчке, на главной диагонали 0");
				el = Matrix[i][0];
				for (int j = 0; j < m; j++)
				{
					if (Matrix[i][j] > el)
						el = Matrix[i][j];
				}
				System.out.println("Максимальный элемент в " + i + " строчке = " + el);				
			}
		  }
		
	}
}
