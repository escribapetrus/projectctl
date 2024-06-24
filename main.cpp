#include <iostream>
#include <string>

#include "db.hpp"
#include "project.hpp"

using namespace std;

int main() {
  {
    Database db = Database("projects.db");

    //    Project::add("someproj", "/loc/someproj", db);

    vector<Project> projects = Project::list(db);

    for (auto p : projects) {
      cout << p.toString() << endl;
    }
  }

  return 0;
}
