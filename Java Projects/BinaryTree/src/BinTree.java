public class BinTree {
	private Node root;
	BinTree(){
		root = null;
	}
	BinTree(Node x) {
		root = x;
	}
	public Node addTree(Node n, Node t) {
		if (t == null){
			t = n;
			return t;
		}
		else{
			if (n.compareTo(t) < 0) {
				t.setLeft(addTree(n, t.getLeft()));
				return t;
			}
			else{
				if (n.compareTo(t) > 0) {
					t.setRight(addTree(n, t.getRight()));
					return t;
				}
				else{
					t.incCount();
					return t;
				}
			}
		}		
	}
	public void addInt(int x) {
		Node n = new Node(x);
		root = addTree(n, root);
	}
	public int search(int x, Node n) {
		if (n == null){
			return -1;
		}
		if (x < n.getKey()) {
			return search(x, n.getLeft());
		}
		else{
			if (x > n.getKey()) {
				return search(x, n.getRight());
			}
			else{
				return n.getCount();
			}
		}
	}
	public int searchInt(int x) {
		return search(x, root);
	}
	public void goInc(Node n) {
		if (n == null){
			return;
		}
		else{
			goInc(n.getLeft());
			for (int i = 0; i < n.getCount(); i++)
				System.out.print(n.getKey()+" ");
			goInc(n.getRight());
		}
	}
	public void goIncInt() {
		goInc(root);
	}
	public void goDec(Node n) {
		if (n == null){
			return;
		}
		else{
			goDec(n.getRight());
			for (int i = 0; i < n.getCount(); i++)
				System.out.print(n.getKey()+" ");
			goDec(n.getLeft());
		}
	}
	public void goDecInt() {
		goDec(root);
	}
}
