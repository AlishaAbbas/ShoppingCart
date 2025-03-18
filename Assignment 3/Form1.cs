using Assignment3.BLL;
using System;
using System.Data;
using System.Windows.Forms;

namespace Assignment3
{
    public partial class Form1 : Form
    {
        private ManagerBLL managerBLL = new ManagerBLL();

        public Form1()
        {
            InitializeComponent();
            this.Load += new System.EventHandler(this.Form1_Load);  // Form Load Event Handler
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            LoadData();  // Data Load Karna
        }

        private void LoadData()
        {
            dataGridView1.DataSource = managerBLL.GetAllManagers();
        }

        private void btnAddManager_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            int age = int.TryParse(txtAge.Text, out int parsedAge) ? parsedAge : 0;
            string position = txtPosition.Text;

            if (managerBLL.AddManager(name, age, position))
            {
                MessageBox.Show("Manager Added Successfully!");
                LoadData();
            }
            else
            {
                MessageBox.Show("Invalid Input or Error Occurred.");
            }
        }
    }
}
