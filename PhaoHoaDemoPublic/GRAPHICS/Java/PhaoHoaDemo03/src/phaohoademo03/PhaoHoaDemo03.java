package phaohoademo03;

import javax.swing.SwingUtilities;

public class PhaoHoaDemo03 {

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
