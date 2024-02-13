#include <iostream>
#include <pqxx/pqxx>
#include <unistd.h> 

using namespace std; 


string takePasswdFromUser() 
{ 
    char *password;

    password = getpass("Enter password: ");
  
    return password; 
} 

int main(int, char**){
    //std::cout << "Hello, from DB_Reader!\n";

    std::string  dbName = "handpi";
    std::string  username = "PC";
    std::string  hostname = "192.168.1.100";
    std::string  port = "5433";

    string pswrd = "";

    
using namespace pqxx;

   pswrd = takePasswdFromUser();
   std::string connstring = "dbname = "+ dbName + "user = "+ username +" password = "+ pswrd +" hostname = "+ hostname + " port = "+ port;

   try {
      connection c("dbname = handpi  user = PC password = raspberrydbpi \
      hostaddr = 192.168.1.100 port = 5432");
       std::cout << "Connected to " << c.dbname() << '\n';
       if (c.is_open()) {
         cout << "Opened database successfully: " << c.dbname() << endl;
        } else {
         cout << "Can't open database" << endl;
         return 1;
        }
        std:: string sql = "SELECT * from patient_data";

      nontransaction N(c);
      
      result R( N.exec( sql ));
      
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
         cout << "ID = " << c[0].as<int>() << endl;
         cout << "exam_ID = " << c[1].as<int>() << endl;
         cout << "Gender = " << c[2].as<string>() << endl;
         cout << "Age = " << c[3].as<int>() << endl;
         cout << "mcsd = " << c[4].as<string>() << endl;
         cout << "Palm_size = " << c[5].as<float>() << endl;

      }
      cout << "Operation done successfully" << endl;
      //c.disconnect ();

    }
    catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;

    }


   } 
