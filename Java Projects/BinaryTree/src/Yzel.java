public class Yzel {

	public static void main(String[] args) {
		BinTree A;
		int x;
		A = new BinTree();
		for (int i = 0; i < 25; i++){
			x = (int)(Math.random() * 100);
			A.addInt(x);
			System.out.print(x + " ");
		}		
		System.out.println();
		A.goIncInt();
		System.out.println();
		A.goDecInt();
	}

}