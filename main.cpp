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
       pqxx::connection c("dbname = handpi  user = PC password = raspberrydbpi \
      hostaddr = 192.168.1.100 port = 5432");
       std::cout << "Connected to " << c.dbname() << '\n';
       if (c.is_open()) {
         cout << "Opened database successfully: " << c.dbname() << endl;
        } else {
         cout << "Can't open database" << endl;
         return 1;
        }
    
   }
    catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;

    }
}