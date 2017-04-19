public class Node implements Comparable<Node>{
	private Integer key;
	private Integer count;
	private Node left, right;
	Node() {
		key = new Integer(-1);
		count = new Integer(-1);
		left = right = null;
	}
	Node(int x) {
		key = new Integer(x);
		count = new Integer(1);
		left = right = null;
	}
	Node(int x, int c, Node l, Node r) {
		key = new Integer(x);
		count = new Integer(c);
		left = l;
		right = r;
	}
	Node(Node x) {
		key = x.getKey();
		count = x.getCount();
		left = x.getLeft();
		right = x.getRight();
	}
	public int getKey() {
		return key;
	}
	public int getCount() {
		return count;
	}
	public Node getLeft() {
		return left;
	}
	public void setRight(Node y) {
		right = y;
	}
	public void setLeft(Node y) {
		left = y;
	}
	public Node getRight() {
		return right;
	}
	public void incCount() {
		count++;
	}	
	public int compareTo(Node n) {
		return this.key.compareTo(n.key);
	}
}