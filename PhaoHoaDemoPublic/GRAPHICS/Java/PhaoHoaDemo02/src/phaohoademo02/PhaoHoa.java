package phaohoademo02;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.geom.Point2D;
import java.util.LinkedList;
import java.util.List;

/*
* Pháo hoa chạy (hàm CapNhat) sẽ giải qua 2 giai đoạn
* GIAI ĐOẠN 1. Một hạt được bắn lên
* GIAI ĐOẠN PHÁT NỔ. Phát sinh các hạt sáng ngẫu nhiên
* GIAI ĐOẠN 2. Lan tỏa các hạt sáng được sinh ra
* */
public class PhaoHoa {
    Hat hatBan;             // GIAI ĐOẠN 1. Hạt bắn lên
    List<Hat> listHat;      // GIAI ĐOẠN 2. Danh sách các hạt phát nổ được sinh ra khi hạt bắn lên đã chết
    Color mauSac;            // màu sắc chung của các hạt sáng trong listHat


    public PhaoHoa() {
        mauSac = Global.ListColors[Helper.GetRandomInt(Global.ListColors.length)];
        
        Point2D.Double hatBan_toado = new Point2D.Double(
                Helper.GetRandomInt(100, Global.WindowWidth - 100), Global.WindowHeight);
        
        Point2D.Double hatBan_vantoc = new Point2D.Double(0, -10);
        int hatBan_thoigiansong = Helper.GetRandomInt(25, 45);

        hatBan = new Hat(hatBan_toado, hatBan_vantoc, hatBan_thoigiansong);
    }


    // khi phát nổ, khởi tạo danh sách các hạt sáng ngẫu nhiên
    void PhatNo() {
        int n = Helper.GetRandomInt(40, 80);
        listHat = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            // vận tốc (X, Y) ngẫu nhiên nằm trong đoạn [-5, 5], với X và Y là một số thực
            Point2D.Double vantoc = new Point2D.Double(
                    -5.0 + Helper.GetRandomInt(110) / 10.0,
                    -5.0 + Helper.GetRandomInt(110) / 10.0
            );
            int thoigiansong = Helper.GetRandomInt(20, 30);

            Hat hat = new Hat(hatBan.ToaDo, vantoc, thoigiansong);
            listHat.add(hat);
        }
    }
    
    
    public void CapNhatUI(Graphics g) {
        if (hatBan.ThoiGianSong > 0) {
            g.setColor(Color.WHITE);
            hatBan.CapNhatUI(g);
        }
        else {
            g.setColor(this.mauSac);
            
            for (Hat hat: listHat) {
                hat.CapNhatUI(g);
            }
        }
    }



    public boolean CapNhat() {
        if (hatBan.ThoiGianSong > 0)
            return CapNhatGiaiDoan1();
        else
            return CapNhatGiaiDoan2();
    }

    boolean CapNhatGiaiDoan1() {
        boolean ret = hatBan.CapNhat();

        if (ret == false) {
            // hạt sáng bắn lên đã chết, đến giai đoạn pháo hoa nổ
            PhatNo();
        }

        return true;
    }


    // trả về true nếu pháo hoa còn sống, trả về false nếu pháo hoa đã chết
    // pháo hoa còn sống nghĩa là còn tồn tại các hạt sáng do nó phát ra
    boolean CapNhatGiaiDoan2() {
        for (int i = listHat.size() - 1; i >= 0; i--) {
            Hat hat = listHat.get(i);
            boolean ret = hat.CapNhat();

            if (ret == false) {
                listHat.remove(i);
            }
        }

        if (listHat.size() > 0)
            return true;

        return false;
    }
}
