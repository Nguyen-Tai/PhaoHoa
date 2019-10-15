using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace PhaoHoaDemo03
{
    class HatBan : Hat
    {
        public HatBan(PointF toado, PointF vantoc, int thoigiansong, Brush cove):
            base(toado, vantoc, thoigiansong, cove)
        {

        }


        public override void Ve(Graphics g)
        {
            g.FillEllipse(Brushes.White, ToaDo.X - 4, ToaDo.Y - 4, 8, 8);
            g.FillEllipse(this.CoVe, ToaDo.X - 2, ToaDo.Y - 2, 4, 4);
        }
    }
}
