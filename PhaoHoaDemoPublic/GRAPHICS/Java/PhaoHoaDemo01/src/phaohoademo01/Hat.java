package phaohoademo01;

import java.awt.Graphics;
import java.awt.geom.Point2D;

// hạt sáng
public class Hat {
    public Point2D.Double ToaDo;        // tọa độ
    public Point2D.Double VanToc;       // vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn

    public int ThoiGianSong;            // thời gian sống, thời gian sống <= 0 tức là đã chết
    
    
    public Hat(Point2D.Double toado, Point2D.Double vantoc, int thoigiansong) {
        this.ToaDo = (Point2D.Double)toado.clone();
        this.VanToc = (Point2D.Double)vantoc.clone();
        this.ThoiGianSong = thoigiansong;
    }


    public void CapNhatUI(Graphics g) {
        g.fillRect((int)ToaDo.x - 1, (int)ToaDo.y - 1, 2, 2);
    }


    // trả về true nếu hạt còn sống, trả về false nếu hạt đã chết (hết thời gian sống)
    public boolean CapNhat() {
        if (ThoiGianSong <= 0)
            return false;

        ToaDo.x += VanToc.x;
        ToaDo.y += VanToc.y;

        ThoiGianSong--;

        //CapNhatUI(g);

        return (ThoiGianSong > 0);
    }
}
