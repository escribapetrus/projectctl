#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

#include "db.hpp"

using namespace std;

class Project {
private:
  string id;
  string name;
  string location;

public:
  Project(const string &id, const string &name, const string &location);

  string toString() const;
  string get_id();
  string get_name();
  string get_location();

  static vector<Project> list(Database db);

  static void add(const string &, const string &, Database db);
};

#endif
