package phaohoademo03;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.geom.Point2D;

// hạt sáng
public class Hat {
    public Point2D.Double ToaDo;        // tọa độ
    public Point2D.Double VanToc;       // vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn

    public int ThoiGianSong;            // thời gian sống, thời gian sống <= 0 tức là đã chết
    
    public Color MauSac;
    
    
    public Hat(Point2D.Double toado, Point2D.Double vantoc, int thoigiansong, Color mausac) {
        this.ToaDo = (Point2D.Double)toado.clone();
        this.VanToc = (Point2D.Double)vantoc.clone();
        this.ThoiGianSong = thoigiansong;
        this.MauSac = mausac;
    }


    public void CapNhatUI(Graphics g) {
        g.setColor(MauSac);
        g.fillRect((int)ToaDo.x - 1, (int)ToaDo.y - 1, 2, 2);
    }


    // trả về true nếu hạt còn sống, trả về false nếu hạt đã chết (hết thời gian sống)
    public boolean CapNhat() {
        if (ThoiGianSong <= 0)
            return false;
        
        VanToc.x += Global.GiaToc.x;
        VanToc.y += Global.GiaToc.y;

        ToaDo.x += VanToc.x;
        ToaDo.y += VanToc.y;

        ThoiGianSong--;
        
        MauSac = new Color(MauSac.getRed(), MauSac.getGreen(), MauSac.getBlue(), (int)(MauSac.getAlpha() * 0.97));
        //CapNhatUI(g);

        return (ThoiGianSong > 0);
    }
}
