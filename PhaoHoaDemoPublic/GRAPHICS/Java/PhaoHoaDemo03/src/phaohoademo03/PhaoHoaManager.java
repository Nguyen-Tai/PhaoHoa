package phaohoademo03;

import java.awt.Graphics;
import java.util.LinkedList;
import java.util.List;

public class PhaoHoaManager {
    public List<PhaoHoa> ListPhaoHoa = new LinkedList<>();
    

    public PhaoHoaManager() {
        PhaoHoa phaohoa = new PhaoHoa();
        this.ListPhaoHoa.add(phaohoa);
    }
    
    
    public final int SoLuongPhaoHoa() {
        return ListPhaoHoa.size();
    }
    
    
    public void CapNhatUI(Graphics g) {
        for (PhaoHoa phaohoa: ListPhaoHoa) {
            phaohoa.CapNhatUI(g);
        }
    }


    public void CapNhat() {
        // BƯỚC 1. Cập nhật nội bộ
        if (this.SoLuongPhaoHoa() < 3 && Helper.GetRandomInt(10) == 0) {
            PhaoHoa phaohoa = new PhaoHoa();
            this.ListPhaoHoa.add(phaohoa);
        }


        // BƯỚC 2. Cập nhật từng pháo hoa bên trong
        for (int i = ListPhaoHoa.size() - 1; i >= 0; i--) {
            PhaoHoa phaohoa = ListPhaoHoa.get(i);
            boolean ret = phaohoa.CapNhat();

            // nếu pháo hoa đã chết, xóa khỏi danh sách
            if (ret == false) {
                ListPhaoHoa.remove(i);
            }
        }
    }
}
