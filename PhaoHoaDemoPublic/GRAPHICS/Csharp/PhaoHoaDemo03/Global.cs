using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;


namespace PhaoHoaDemo03
{
    class Global
    {
        public static int WindowWidth;
        public static int WindowHeight;

        public static PointF GiaToc = new PointF(0, 0.15f);

        public static readonly Brush[] DsCoVe = { Brushes.White, Brushes.Red, Brushes.Green, Brushes.Blue,
                                                Brushes.Yellow, Brushes.Orange, Brushes.Violet,
                                                Brushes.LightCyan, Brushes.LightPink, Brushes.Snow,
                                                Brushes.FloralWhite, Brushes.Linen, Brushes.LemonChiffon,
                                                Brushes.Azure, Brushes.SpringGreen, Brushes.LawnGreen,
                                                Brushes.GreenYellow, Brushes.PaleTurquoise, Brushes.Khaki,
                                                Brushes.Orchid, Brushes.Plum, Brushes.Thistle, Brushes.Honeydew};
    }
}
