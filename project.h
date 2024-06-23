#include <string>
#include <vector>

#include "db.h"

using namespace std;

class Project {
private:
    string id;
    string name;
    string location;
public:
    Project(
            const string& id, 
            const string& name, 
            const string& location);

    string toString() const;

    vector<Project> list(Database db);

};
