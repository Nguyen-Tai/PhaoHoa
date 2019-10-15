using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace PhaoHoaDemo01
{
    /*
     * Pháo hoa chạy (hàm CapNhat) sẽ giải qua 2 giai đoạn
     * GIAI ĐOẠN 1. Một hạt được bắn lên
     * GIAI ĐOẠN PHÁT NỔ. Phát sinh các hạt sáng ngẫu nhiên
     * GIAI ĐOẠN 2. Lan tỏa các hạt sáng được sinh ra
     * */
    class PhaoHoa
    {
        static Random ra = new Random();
        Graphics g;

        Hat hatBan;             // GIAI ĐOẠN 1. Hạt bắn lên
        List<Hat> listHat;      // GIAI ĐOẠN 2. Danh sách các hạt phát nổ được sinh ra khi hạt bắn lên đã chết


        public PhaoHoa(Graphics g)
        {
            this.g = g;

            PointF hatBan_toado = new PointF(ra.Next(100, Global.WindowWidth - 100), Global.WindowHeight);
            PointF hatBan_vantoc = new PointF(0, -10);
            int hatBan_thoigiansong = ra.Next(25, 40);

            hatBan = new Hat(hatBan_toado, hatBan_vantoc, hatBan_thoigiansong, Brushes.White);
        }


        // khi phát nổ, khởi tạo danh sách các hạt sáng ngẫu nhiên
        void PhatNo()
        {
            int n = ra.Next(40, 80);
            listHat = new List<Hat>(n);

            // cọ vẽ chung
            Brush coVeChung = Global.DsCoVe[ra.Next(Global.DsCoVe.Length)];

            for (int i = 0; i < n; i++)
            {
                // vận tốc (X, Y) ngẫu nhiên nằm trong đoạn [-5, 5], với X và Y là một số thực
                PointF vantoc = new PointF(-5f + ra.Next(110) / 10f, -5f + ra.Next(110) / 10f);
                int thoigiansong = ra.Next(20, 30);

                Hat hat = new Hat(hatBan.ToaDo, vantoc, thoigiansong, coVeChung);
                listHat.Add(hat);
            }
        }


        
        public bool CapNhat()
        {
            if (hatBan.ThoiGianSong > 0)
                return CapNhatGiaiDoan1();
            else
                return CapNhatGiaiDoan2();
        }

        bool CapNhatGiaiDoan1()
        {
            bool ret = hatBan.CapNhat(this.g);

            if (ret == false)
            {
                // hạt sáng bắn lên đã chết, đến giai đoạn pháo hoa nổ
                PhatNo();
            }

            return true;
        }


        // trả về true nếu pháo hoa còn sống, trả về false nếu pháo hoa đã chết
        // pháo hoa còn sống nghĩa là còn tồn tại các hạt sáng do nó phát ra
        bool CapNhatGiaiDoan2()
        {
            for (int i = listHat.Count - 1; i >= 0; i--)
            {
                Hat hat = listHat[i];
                bool ret = hat.CapNhat(g);

                if (ret == false)
                {
                    listHat.RemoveAt(i);
                }
            }

            if (listHat.Count > 0)
                return true;

            return false;
        }
    }
}
