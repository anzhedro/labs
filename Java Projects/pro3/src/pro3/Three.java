package pro3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Three {

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
		
		int max = -10000, key = 0;
		boolean k = false;
		
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < m; j++)
			{
				if (M[i][j] > max)
				{
					
					for (int a = 0; a < n; a++)
					  {
						
						for (int b = 0; b < m; b++)
						{
							if (M[a][b] == M[i][j])
							{
								key++;																
							}
						}
						if (key > 2) 
							{
							key = -1;
							break;
							}
						
					  }
					if (key == 2)
					{
						max = M[i][j];
						k = true;
					}
					else
						key = 0;		
				}
			}
		  }
		if (k)
			System.out.println("Max (2) = " + max);
		else
			System.out.println("No max");
	}
}
