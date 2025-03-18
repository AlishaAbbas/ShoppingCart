using System;
using System.Data;
using System.Data.SqlClient;

namespace Assignment3.DAL
{
    public class ManagerDAL
    {
        private string connectionString = "Server=DESKTOP-7A7UDP6\\SQLEXPRESS;Database=OwnerDB;Integrated Security=True;";

        // Get all managers
        public DataTable GetManagers()
        {
            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                string query = "SELECT * FROM Manager";
                SqlDataAdapter adapter = new SqlDataAdapter(query, conn);
                DataTable dt = new DataTable();
                adapter.Fill(dt);
                return dt;
            }
        }

        // Insert a new manager
        public bool InsertManager(string name, int age, string position)
        {
            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                string query = "INSERT INTO Manager (Name, Age, Position) VALUES (@Name, @Age, @Position)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@Name", name);
                cmd.Parameters.AddWithValue("@Age", age);
                cmd.Parameters.AddWithValue("@Position", position);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }
    }
}
