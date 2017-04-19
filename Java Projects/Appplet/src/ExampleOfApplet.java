import java.awt.Color;


public class ExampleOfApplet extends java.applet.Applet {
public void init(){}
public void start(){}
public void update(java.awt.Graphics g){}
public void paint(java.awt.Graphics g){
 g.setColor(Color.green);
 g.fillRect(0, 0, getSize().width - 1, getSize().height - 1);
 g.setColor(Color.black);
 g.drawString("Вас приветствует апплет", 20, 20);
 this.showStatus("Это пример апплета");
}
public void stop(){}
}