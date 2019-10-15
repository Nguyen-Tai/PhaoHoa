using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PhaoHoaDemo01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Global.WindowWidth = this.Width;
            Global.WindowHeight = this.Height - 40;

            g = this.CreateGraphics();

            phaohoa = new PhaoHoa(g);

            timer.Start();
        }


        Graphics g;
        PhaoHoa phaohoa;


        private void timer_Tick(object sender, EventArgs e)
        {
            g.Clear(Color.Black);

            bool ret = phaohoa.CapNhat();

            if (ret == false)
            {
                // pháo hoa đã chết
                g.Clear(Color.Black);
                timer.Stop();
            }
        }
    }
}
