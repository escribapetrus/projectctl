#include <iostream>
#include <string>

#include "db.h"
#include "project.h"

using namespace std;

int main() {
    {
        Database db = Database("projects.db");    
        vector<Project> projects = Project::list(db);

        for (auto p: projects) {
            cout << p.toString() << endl;
        }
    }
   
    return 0;
}
