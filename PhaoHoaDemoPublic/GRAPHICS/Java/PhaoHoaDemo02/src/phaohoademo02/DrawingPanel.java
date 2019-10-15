package phaohoademo02;

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
    
    
    PhaoHoaManager manager = new PhaoHoaManager();
    Timer timer;
    
    
    private void initComponents() {
        this.setBackground(Color.BLACK);
        
        manager = new PhaoHoaManager();
        timer = new Timer(30, this);
        
        
        timer.start();
    }
    
    
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        manager.CapNhatUI(g);
    }
    
    
    @Override
    public void actionPerformed(ActionEvent e) {
        manager.CapNhat();
        this.repaint();
    }
}
