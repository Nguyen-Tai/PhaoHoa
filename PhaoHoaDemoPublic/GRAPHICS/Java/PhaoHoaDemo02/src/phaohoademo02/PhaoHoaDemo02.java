package phaohoademo02;

import javax.swing.SwingUtilities;

public class PhaoHoaDemo02 {

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
