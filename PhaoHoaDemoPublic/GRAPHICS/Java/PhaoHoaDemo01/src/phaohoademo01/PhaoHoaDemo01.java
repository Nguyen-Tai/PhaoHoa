package phaohoademo01;

import javax.swing.SwingUtilities;

public class PhaoHoaDemo01 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new MainWindow();
            }
        });
    }
    
}
