using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DrawingTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int[] parameters = new int[18];
        Random rnd = new Random();
        double t = 0.0001;
        int bufferRefreshInterval = 5;
        int paramsRefreshInterval = 7000;
        Color[] colors = {
            Color.FromArgb(255, 0, 0),
            Color.FromArgb(255, 128, 0),
            Color.FromArgb(255, 255, 0),
            Color.FromArgb(128, 255, 0),
            Color.FromArgb(0, 255, 0),
            Color.FromArgb(0, 255, 128),
            Color.FromArgb(0, 255, 255),
            Color.FromArgb(0, 128, 255),
            Color.FromArgb(0, 0, 255),
            Color.FromArgb(128, 0, 255),
            Color.FromArgb(255, 0, 255),
            Color.FromArgb(255, 0, 128),
            Color.FromArgb(128, 128, 128),
            Color.FromArgb(228, 229, 224),
            Color.FromArgb(255, 255, 240),
            Color.FromArgb(255, 255, 255),
        };
        SolidBrush brush = new SolidBrush(Color.White);

        private void Form1_Load(object sender, EventArgs e)
        {
            Timer bufferRefresh = new Timer();
            bufferRefresh.Tick += new EventHandler(bufferRefresh_Tick);
            bufferRefresh.Interval = bufferRefreshInterval;
            bufferRefresh.Enabled = true;
            bufferRefresh.Start();

            Timer paramsRefresh = new Timer();
            paramsRefresh.Tick += new EventHandler(paramsRefresh_Tick);
            paramsRefresh.Interval = paramsRefreshInterval;
            paramsRefresh.Enabled = true;
            paramsRefresh.Start();

            paramsRefresh_Tick(null, null);
        }

        void bufferRefresh_Tick(object sender, EventArgs e)
        {
            this.Refresh();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            double[] cords = new double[2];
            double[] transformedCords;

            cords[0] = t; //x
            cords[1] = t; //y
            for (int i = 0; i < 100000; i++)
            {
                cords = calcNextCords(cords[0], cords[1], t);

                transformedCords = transformCords(cords[0], cords[1], t);

                brush.Color = colors[i % 16];
                if (transformedCords[0] < 1073741951 && transformedCords[0] > -1073741760 && transformedCords[1] < 1073741951 && transformedCords[1] > -1073741760)
                {
                    e.Graphics.FillRectangle(brush, (float)transformedCords[0], (float)transformedCords[1], 1, 1);
                }

            }
            t += 0.0001;
        }

        public double[] calcNextCords(double x, double y, double t)
        {
            double[] cords = new double[2];
            double oldx = x;

            double xx = oldx * oldx;
            double yy = y * y;
            double tt = t * t;
            double xy = oldx * y;
            double xt = oldx * t;
            double yt = y * t;

            cords[0] = xx*parameters[0] + yy*parameters[1] + tt*parameters[2] + xy*parameters[3] + xt*parameters[4] + yt*parameters[5] + oldx*parameters[6] + y*parameters[7] + t*parameters[8];
            cords[1] = xx*parameters[9] + yy*parameters[10] + tt*parameters[11] + xy*parameters[12] + xt*parameters[13] + yt*parameters[14] + oldx*parameters[15] + y*parameters[16] + t*parameters[17];

            return cords;
        }

        public double[] transformCords(double x, double y, double t)
        {
            double[] cords = new double[2];
            double s = this.Size.Height * 2.5; //2.5 * (this.Size.Height / 2)
            cords[0] = this.Size.Width / 2 + x * s;
            cords[1] = this.Size.Height / 2 + y * s;
            
            return cords;
        }

        void paramsRefresh_Tick(object sender, EventArgs e)
        {
            t = 0.0001;

            for (int i = 0; i < parameters.Length; i++) //modificare le probabilitá non é stato utile a niente
            {
                parameters[i] = rnd.Next(-1, 2);
            }
            paramsRefreshScreen();
        }

        public void paramsRefreshScreen()
        {
            string functionX = paramsToString(0, parameters.Length / 2);
            string functionY = paramsToString(parameters.Length / 2 - 1, parameters.Length);

            functionToScreen.Text = $"X: {functionX} \nY: {functionY}";
        }

        public string paramsToString(int parametersNS, int parametersNE)
        {
            string result = "";
            for (int i = parametersNS; i < parametersNE; i++)
            {
                if (parameters[i] != 0)
                {
                    if (parameters[i] == 1)
                    {
                        result += " + ";
                    }
                    else
                    {
                        result += " - ";
                    }

                    if (i == 0 || i == 9)
                    {
                        result += " xx ";
                    }
                    if (i == 1 || i == 10)
                    {
                        result += " yy ";
                    }
                    if (i == 2 || i == 11)
                    {
                        result += " tt ";
                    }
                    if (i == 3 || i == 12)
                    {
                        result += " xy ";
                    }
                    if (i == 4 || i == 13)
                    {
                        result += " xt ";
                    }
                    if (i == 5 || i == 14)
                    {
                        result += " yt ";
                    }
                    if (i == 6 || i == 15)
                    {
                        result += " x ";
                    }
                    if (i == 7 || i == 16)
                    {
                        result += " y ";
                    }
                    if (i == 8 || i == 17)
                    {
                        result += " t ";
                    }
                }
            }
            return result;
        }
    }
}
