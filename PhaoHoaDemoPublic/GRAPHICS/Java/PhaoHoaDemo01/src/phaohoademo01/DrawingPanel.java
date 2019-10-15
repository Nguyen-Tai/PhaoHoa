package phaohoademo01;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class DrawingPanel extends JPanel implements ActionListener {
    public DrawingPanel() {
        super(true);
        initComponents();
    }
    
    
    PhaoHoa phaoHoa;
    Timer timer;
    
    
    private void initComponents() {
        this.setBackground(Color.BLACK);
        
        phaoHoa = new PhaoHoa();
        
        timer = new Timer(30, this);
        timer.start();
    }
    
    
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        phaoHoa.CapNhatUI(g);
    }
    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        boolean ret = phaoHoa.CapNhat();
        this.repaint();
        
        if (ret == false) {
            timer.stop();
        }
    }
}
