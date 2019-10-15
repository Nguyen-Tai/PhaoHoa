package phaohoademo02;

import javax.swing.*;

public class MainWindow extends JFrame {
    JPanel panel;
    
    public MainWindow() {
        initComponents();
        initWindow();
    }
    
    
    private void initComponents() {
        panel = new DrawingPanel();
        this.setContentPane(panel);
    }
    
    
    private void initWindow() {
        this.setTitle("Phao hoa demo 02");
        
        this.getRootPane().setWindowDecorationStyle(JRootPane.NONE);
        
        this.setSize(Global.WindowWidth, Global.WindowHeight);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        
        this.setResizable(false);
    }
}
