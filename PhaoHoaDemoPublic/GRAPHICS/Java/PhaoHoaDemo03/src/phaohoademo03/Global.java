package phaohoademo03;

import java.awt.Color;
import java.awt.geom.Point2D;

public class Global {
    public static final int WindowWidth = 700;
    public static final int WindowHeight = 500;
    
    public static Point2D.Double GiaToc = new Point2D.Double(0, 0.15);
    
    public static Color[] ListColors = {
        Color.WHITE, Color.RED, Color.GREEN, Color.BLUE,
        Color.PINK, Color.MAGENTA, Color.YELLOW,
        new Color(0xF0FFFF), new Color(0xFFFAF0), new Color(0xE0FFFF),
        new Color(0xFFD700), new Color(0xFAFAD2)
    };
}
