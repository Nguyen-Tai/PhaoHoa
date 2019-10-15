using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PhaoHoaDemo03
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Global.WindowWidth = this.Width;
            Global.WindowHeight = this.Height - 40;

            SetStyle(ControlStyles.UserPaint, true);
            SetStyle(ControlStyles.AllPaintingInWmPaint, true);
            SetStyle(ControlStyles.OptimizedDoubleBuffer, true);

            Graphics g = this.CreateGraphics();
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighSpeed;

            manager = new PhaoHoaManager(g);
            timer.Start();
        }


        PhaoHoaManager manager;


        private void timer_Tick(object sender, EventArgs e)
        {
            manager.CapNhat();
        }
    }
}
