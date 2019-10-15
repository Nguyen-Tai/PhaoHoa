﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace PhaoHoaDemo01
{
    // hạt sáng
    class Hat
    {
        public PointF ToaDo { get; protected set; }     // tọa độ
        public PointF VanToc { get; protected set; }    // vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn
        public Brush CoVe { get; protected set; }       // cọ vẽ, hỗ trợ tạo màu


        public int ThoiGianSong { get; protected set; } // thời gian sống, thời gian sống <= 0 tức là đã chết


        public Hat(PointF toado, PointF vantoc, int thoigiansong, Brush cove)
        {
            this.ToaDo = toado;
            this.VanToc = vantoc;
            this.ThoiGianSong = thoigiansong;
            this.CoVe = cove;

            if (this.CoVe == null)
                this.CoVe = Brushes.Red;
        }


        public virtual void Ve(Graphics g)
        {
            g.FillRectangle(this.CoVe, ToaDo.X - 1, ToaDo.Y - 1, 2, 2);
        }


        // trả về true nếu hạt còn sống, trả về false nếu hạt đã chết (hết thời gian sống)
        public virtual bool CapNhat(Graphics g)
        {
            if (ThoiGianSong <= 0)
                return false;

            ToaDo = new PointF(ToaDo.X + VanToc.X, ToaDo.Y + VanToc.Y);

            ThoiGianSong--;
            
            Ve(g);

            return (ThoiGianSong > 0);
        }
    }
}
