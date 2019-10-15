package phaohoademo03;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.geom.Point2D;

public class HatBan extends Hat {
    public HatBan(Point2D.Double toado, Point2D.Double vantoc, int thoigiansong, Color mausac) {
            super(toado, vantoc, thoigiansong, mausac);
    }


    @Override
    public void CapNhatUI(Graphics g) {
        g.setColor(Color.WHITE);
        g.fillOval((int)ToaDo.x - 4, (int)ToaDo.y - 4, 8, 8);
        
        g.setColor(MauSac);
        g.fillOval((int)ToaDo.x - 3, (int)ToaDo.y - 3, 6, 6);
    }
}
