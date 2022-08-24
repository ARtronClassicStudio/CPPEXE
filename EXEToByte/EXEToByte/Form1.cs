using System;
using System.IO;
using System.Windows.Forms;

namespace EXEToByte
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void OpenFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog
            {
                FileName = "",
                Filter = "*.exe|*.exe"
            };
            if (open.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Text = "const byte data[]\n{" +"\n"+ ToArry(File.ReadAllBytes(open.FileName))+"\n};";
                richTextBox1.Enabled = true;
            }
        }

        string ToArry(byte[] value)
        {

            return string.Join(",\n",value);
        }

        private void openConvertToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog
            {
                FileName = "",
                Filter = "*.exe|*.exe"
            };
            if (open.ShowDialog() == DialogResult.OK)
            {
                var data = "#include <Windows.h>\n\n" + "const byte data[]\n{" + "\n" + ToArry(File.ReadAllBytes(open.FileName)) + "\n};";
                SaveFileDialog save = new SaveFileDialog
                {
                    FileName = "",
                    Filter = "*.h|*.h"
                };
                if(save.ShowDialog() == DialogResult.OK)
                {
                    File.WriteAllText(save.FileName,data);
                }
            }
        }
    }
}
