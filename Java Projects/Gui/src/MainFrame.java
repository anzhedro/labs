import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Container;
import java.awt.HeadlessException;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.Panel;
import java.awt.ScrollPane;
import java.awt.Toolkit;
import java.awt.event.MouseEvent;
import java.awt.geom.Point2D;
import java.util.ArrayList;

import javax.swing.JFrame;


public class MainFrame extends JFrame {
	public MainFrame() throws HeadlessException {
		super();
		
		MenuBar mb = new MenuBar();  
		setMenuBar(mb);  
		Menu f = new Menu("Τΰιλ");  
		mb.add(f);
		
		setSize(WIDTH, HEIGHT);
		setLocation((int)(Toolkit.getDefaultToolkit().getScreenSize().width/2 - WIDTH/2),
					(int)(Toolkit.getDefaultToolkit().getScreenSize().height/2 - HEIGHT/2));
		setTitle("Test frame");
		
		Container content = getContentPane();
		TestPanel tp = new TestPanel(list, this);
		content.add(tp);
	}
	
	public void addPoint(Point2D p) {
		list.add(p);
		//System.out.println(p.getX() + " " + p.getY());
	}
	public void mousePressed(MouseEvent e){ 
		setTitle("1");
		}  
	
	private final int WIDTH = 300;
	private final int HEIGHT = 300;
	private ArrayList list = new ArrayList();
}