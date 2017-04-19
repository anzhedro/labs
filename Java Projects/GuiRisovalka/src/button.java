

import java.awt.Button;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class button extends Canvas implements MouseListener{  

private boolean isDown=false;  

public button(){ 

super(); 

setBackground(this.getBackground()); 

addMouseListener(this);  

} 
public void drawFlower(Graphics g, int x, int y, int w, int h){  
g.drawOval(x+ 2*w/5 - 6, y, w/5, w/5);
g.drawLine(x+w/2-6,y+10,x+w/2-6,y+h);
//g.drawOval(x+ 3*w/10 -6, y + h/3 - 4, w/5, w/5);
//g.drawOval(x+ w/2 - 6, y + h/3 - 4, w/5, w/5);
//g.drawLine();
g.drawOval(x+3*w/10-6,y+h/3-4,w/5,w/5);
g.drawOval(x+w/2-6,y+h/3-4,w/5,w/5);
}
public void paint(Graphics g){ 

	int w = getSize().width, h = getSize().height; 

	int d = Math.min(w, h);      // Диаметр круга 

	Color с = g.getColor();      // Сохраняем текущий цвет 

	g.setColor(Color.lightGray); // Устанавливаем серый цвет 

	g.fillArc(0, 0, d, d, 0, 360); // Заливаем круг серым цветом 

	g.setColor(с);               // Восстанавливаем текущий цвет 

	if (isDown){ 

	g.drawArc(0, 0, d, d, 43, 180); 

	g.drawArc(1, 1, d - 2, d - 2, 43, 180); 

	drawFlower(g, 8, 10, d, d); 

	}else{ 

	g.drawArc(0, 0, d, -d, 229, 162); 

	g.drawArc(1, 1, d - 2, d - 2, 225, 170); 

	drawFlower(g, 6, 8, d, d);  

	}  

	}  

	public Dimension getPreferredSize(){ 

	return new Dimension(30,30);  

	} 

	public Dimension getMinimumSize() 

	{ 

	return getPreferredSize(); }  

	public Dimension getMaximumSize(){ 

	return getPreferredSize();  

	} 




public void mousePressed(MouseEvent e){  

	isDown=true; repaint(); } 

	public void mouseReleased(MouseEvent e){  

	isDown=false; repaint(); } 

	public void mouseEntered(MouseEvent e){}  

	public void mouseExited(MouseEvent e) {}  

	public void mouseClicked(MouseEvent e){}  

	} 
	
	class DrawButton extends Frame{  

		DrawButton(String s) {  

		super (s) ;  

		setLayout(null); 

		Button b = new Button("OK");  

		b.setBounds(200, 50, 100, 60); add(b); 

		button d = new button();  
	
		d.setBounds(50, 50, 60, 60); add(d); 

		setSize(400, 150);  

		setVisible(true); 

		}
		
		public static void main(String[] args){ 

			Frame f= new DrawButton(" Кнопка с рисунком");  

			f.addWindowListener(new WindowAdapter(){ 

			public void windowClosing(WindowEvent ev){ 

			System.exit(0);   

			} 
			});  

			}  

			} 





