import java.util.*;
import java.io.*;

public class Pravila {
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new FileReader("markovc.09.in"));
			String []Arg;
			String []Val;
			int beforeCycle;
			int length;
			int flag;
			int n = 0;
			String temp;
			Arg = new String[50];
			Val = new String[50];
			String src;
			TreeMap<String, Integer> map;
			map = new TreeMap<String, Integer>();
			int index = 0;
			src = in.nextLine();
			
			while (in.hasNextLine()) {
				StringTokenizer t = new StringTokenizer(in.nextLine(), " ->");
				Arg[index] = t.nextToken();
				Val[index] = t.nextToken();
				index++;
			}
			
			n = index;
			index = 0;
			do {
				map.put(src, index);
				flag = 0;
				for (int j = 0; j < n; j++){
					if (src.indexOf(Arg[j]) != -1){
						src = src.replaceFirst(Arg[j], Val[j]);
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					temp = null;
				else
					temp = new String(src);
				if (temp == null) {
					beforeCycle = index;
					length = 0;
					System.out.println("BeforeCycle: " + beforeCycle + '\n' + "Length: " + length);
					return;
				}
				else {
					if (map.containsKey(temp)) {
						beforeCycle = map.get(temp);
						length = index - beforeCycle + 1;
						System.out.println("BeforeCycle: " + beforeCycle + '\n' + "Length: " + length);
						return;
					}
					else {
						src = temp;
						index++;
					}
				}
			}
			while (index > -1);			
		}
		catch (IOException ioe){
			System.out.println("Error.");
		}
	}
}