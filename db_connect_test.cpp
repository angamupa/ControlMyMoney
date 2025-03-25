#include <iostream>
#include <string>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main(){

    try{/*
        std::string host = "localhost";
        int port = 3306;
        std::string user = "root";
        std::string password = "root";
        std::string schema = "ControlMyMoney";
        char url_buffer[256];
        snprintf(url_buffer, sizeof(url_buffer),"mysqlx://%s:%s@%s:%d/%s", user.c_str(), password.c_str(), host.c_str(), port, schema.c_str());
        std::string url = url_buffer;
        cout << "Connecting to " << url << endl << endl;
        cout << url << endl << url << endl;*/
        Session session1 = getSession("mysqlx://root:root@localhost:3306/ControlMyMoney");
        cout << "Succesfully connected to MySQL database!" << endl;
        session1.close();
        cout << "Connection closed." << endl;
    } /*catch (const mysqlx::abi2::r0::Result &err){
        cout << "ERROR: " << err.what() << endl;
        cout << "Error code: " << err.getErrorCode() << endl;
        cout << "SQL state: " << err.getSQLState() << endl;
        return 1;
    }*/catch (const std::exception &ex){
        cout << "STD EXCEPTION: " << ex.what() << endl;
        return 1;
    } catch(...){
        cout << "Unknown exception." << endl;
        return 1;
    }
    return 0;
}