#include <string>

#include "db.h"

using namespace std;

Database::Database(const string& name) {
    int rc = sqlite3_open(name.c_str(), &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
    } else {
        cout << "Opened database successfully" << endl;
    }
}

Database::~Database() {
    if (db) sqlite3_close(db);
}

void Database::query(
        const string& q, 
        function<int(void*, int, char**, char**)> callback) {
    char* errMsg; 
    int rc = sqlite3_exec(db, q.c_str(), callbackWrapper, &callback, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Operation successfull";
    }
}

int Database::callbackWrapper(void* data, int argc, char** argv, char** azColName) {
    auto* func = static_cast<std::function<int(int, char**, char**)>*>(data);
    return (*func)(argc, argv, azColName);
}
