import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Point2D;

class MyMouseClick extends MouseAdapter {
	public MyMouseClick(MainFrame frame) {
		super();
		this.frame = frame;
	}
	
	public void mouseClicked(MouseEvent e) {
		super.mouseClicked(e);		
		frame.addPoint(new Point2D.Float((float)e.getX(),(float)e.getY()));
		frame.repaint();
	}
	
	private MainFrame frame;
}