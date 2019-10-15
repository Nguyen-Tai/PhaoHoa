using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;


namespace PhaoHoaDemo02
{
    class PhaoHoaManager
    {
        public List<PhaoHoa> ListPhaoHoa = new List<PhaoHoa>();
        public Graphics g { get; private set; }

        Random ra = new Random();


        public int SoLuongPhaoHoa
        {
            get { return ListPhaoHoa.Count; }
        }


        public PhaoHoaManager(Graphics g)
        {
            this.g = g;

            PhaoHoa phaohoa = new PhaoHoa(this.g);
            this.ListPhaoHoa.Add(phaohoa);
        }

        
        public void CapNhat()
        {
            // BƯỚC 1. Cập nhật nội bộ
            g.Clear(Color.Black);

            if (this.SoLuongPhaoHoa < 3 && ra.Next(10) == 0)
            {
                PhaoHoa phaohoa = new PhaoHoa(this.g);
                this.ListPhaoHoa.Add(phaohoa);
            }


            // BƯỚC 2. Cập nhật từng pháo hoa bên trong
            for (int i = ListPhaoHoa.Count - 1; i >= 0; i--)
            {
                PhaoHoa phaohoa = ListPhaoHoa[i];
                bool ret = phaohoa.CapNhat();

                // nếu pháo hoa đã chết, xóa khỏi danh sách
                if (ret == false)
                {
                    ListPhaoHoa.RemoveAt(i);
                }
            }
        }
    }
}
