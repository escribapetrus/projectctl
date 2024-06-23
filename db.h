#ifndef DATABASE_H
#define DATABASE_H

#include <functional>
#include <iostream>
#include <sqlite3.h>

using namespace std;

class Database {
private: 
    sqlite3* db = nullptr;
    static int callbackWrapper(void* data, int argc, char** argv, char** azColName);

public: 
    Database(const string&);
    ~Database();

    void query(
        const string&, 
        function<int(void*, int, char**, char**)>
        );
}; 

#endif // DATABASE_H