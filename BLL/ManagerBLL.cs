using System.Data;
using Assignment3.DAL;

namespace Assignment3.BLL
{
    public class ManagerBLL
    {
        private ManagerDAL managerDAL = new ManagerDAL();

        // Get all managers
        public DataTable GetAllManagers()
        {
            return managerDAL.GetManagers();
        }

        // Add new manager (Validation check)
        public bool AddManager(string name, int age, string position)
        {
            if (!string.IsNullOrWhiteSpace(name) && age > 0 && !string.IsNullOrWhiteSpace(position))
            {
                return managerDAL.InsertManager(name, age, position);
            }
            return false;
        }
    }
}
