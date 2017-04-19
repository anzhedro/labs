package pro4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Four {

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
		int[][] M = new int[n][m];
		try
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					{
					M[i][j] = Integer.parseInt(br.readLine());
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
				System.out.print(M[i][j] + " ");
			}
			System.out.println();
		  }
		
		for (int a = 0; a < m; a++)
		  {
			for (int b = 0; b < m - 1; b++)
			{
				if (M[0][b] > M[0][b + 1])
				{
					for (int c = 0; c < n; c++)
					{
						int test = M[c][b];
						M[c][b] = M[c][b + 1];
						M[c][b + 1] = test;
					}
				}					
			}
		  }
		
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < m; j++)
			{
				System.out.print(M[i][j] + " ");
			}
			System.out.println();
		  }
	}
}
