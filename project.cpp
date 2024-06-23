#include <string>
#include <iostream>
#include <format>

#include "project.h"

using namespace std;

Project::Project(
        const string& id, 
        const string& name, 
        const string& location) :
    id(id), name(name), location(location) {}

string Project::toString() const {
    return format("ID: {}\nNAME: {}\nLOCATION: {}", id, name, location);    
}

std::vector<Project> list(Database db){
    std::vector<Project> projects;
    std::string query = "SELECT * FROM PROJECTS;";
    auto callback = [](void* firstArg, int argc, char** argv, char** azColName) -> int {
        for (int i = 0; i < argc; i++) {
            // Project p;
            // Create project with params from query and add to vector
            //std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
        }
        return 0;     
    };
    db.query(query, callback);
    return projects;
}

