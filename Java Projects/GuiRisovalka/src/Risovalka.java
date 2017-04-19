import java.awt.*;
import java.awt.event.*;

public class Risovalka extends Frame{  

public Risovalka(String s){  

super(s); 

ScrollPane pane = new ScrollPane(); 

pane.setSize(300, 300); 

add(pane, BorderLayout.CENTER); 

Scribble scr = new  Scribble(this, 500, 500);  

pane.add(scr); 

Panel p = new Panel();  

add(p, BorderLayout.SOUTH); 

Button bl = new Button("�������");  

p.add(bl); 

bl.addActionListener(scr); 

Button b2 = new Button("�������");  

p.add(b2); 

b2.addActionListener(scr) ; 

Button b3 = new Button("�����");  

p.add(b3); 

b3.addActionListener(scr) ; 

Button b4 = new Button("������");  

p.add(b4); 

b4.addActionListener(scr); 

Button b5 = new Button("��������");  

p.add(b5); 

b5.addActionListener(scr); 

MenuBar mb = new MenuBar();  

setMenuBar(mb);  

Menu f = new Menu("����");  

//Menu v = new Menu("���");  
mb.add(f);
//mb.add(f);
MenuItem open = new MenuItem("�������...",
		new MenuShortcut(KeyEvent.VK_0)); 

		MenuItem save = new MenuItem("���������", 

		new MenuShortcut(KeyEvent.VK_S)); 

		MenuItem saveAs = new MenuItem("��������� ���..."); 

		MenuItem exit = new MenuItem("�����", 

		new MenuShortcut(KeyEvent.VK_Q)); 

		f.add(open); f.add(save); f.add(saveAs); 
		f.addSeparator(); f.add(exit); 

		open.addActionListener(new ActionListener(){  

		public void actionPerformed(ActionEvent e){ 

		FileDialog fd = new FileDialog(new Frame(), 

		" ���������", FileDialog.LOAD);  

		fd.setVisible(true);  

		}  

		}); 

		saveAs.addActionListener(new ActionListener(){  

			public void actionPerformed(ActionEvent e){  

			FileDialog fd = new FileDialog(new Frame(), 

			" ���������", FileDialog.SAVE);  

			fd.setVisible(true);  

			}
		});

			exit.addActionListener(new ActionListener(){  

			public void actionPerformed(ActionEvent e){ 

				System.exit(0);  

			} 

			}); 
			


addWindowListener(new WindowAdapter() { 

public void windowClosing(WindowEvent e){  

System.exit(0); 

}  

}); 

pack(); 

setVisible(true);  

} 

public static void main(String[] args){  

new Risovalka(" \"���������\""); 

} 

} 

class Scribble extends Component implements ActionListener, MouseListener, MouseMotionListener{  

protected int lastX, lastY, w, h;  

protected Color currColor = Color.black;  

protected Frame f; 

public Scribble(Frame frame, int width, int height){ 

f = frame;  

w = width;  

h = height; 

enableEvents(AWTEvent.MOUSE_EVENT_MASK | AWTEvent.MOUSE_MOTION_EVENT_MASK); 

addMouseListener( this); 

addMouseMotionListener(this); }  

public Dimension getPreferredSize(){ 

return new Dimension(w, h); }  

public void actionPerformed(ActionEvent event){ 

String s = event.getActionCommand(); 

if (s.equals ("��������")) repaint(); 

else if (s.equals ("�������")) currColor = Color.red; 

else if (s.equals("�������")) currColor = Color.green; 

else if (s.equals("�����")) currColor = Color.blue; 

else if (s.equals("������")) currColor = Color.black; }  

public void mousePressed(MouseEvent e){ 

	if ( (e.getModifiers() & MouseEvent.BUTTON1_MASK) == 0)
		 return; 

lastX = e.getX(); lastY = e.getY(); }  

public void mouseDragged(MouseEvent e){ 

	if ( (e.getModifiers() & MouseEvent.BUTTON1_MASK) == 0)
		return; 

Graphics g = getGraphics(); 

g.setColor(currColor); 

g.drawLine(lastX, lastY, e.getX(), e.getY()); 

lastX = e.getX(); lastY = e.getY(); } 

public void mouseReleased(MouseEvent e){}  

public void mouseClicked(MouseEvent e){} 

public void mouseEntered(MouseEvent e){}  

public void mouseExited(MouseEvent e){}  

public void mouseMoved(MouseEvent e){}  

} 

