#include <format>
#include <iostream>
#include <string>

#include "db.hpp"
#include "project.hpp"

using namespace std;

Project::Project(const string &id, const string &name, const string &location)
    : id(id), name(name), location(location) {}

string Project::toString() const {
  return format("ID: {}, NAME: {}, LOCATION: {}", id, name, location);
}

string Project::get_id() { return id; }

string Project::get_name() { return name; }







string Project::get_location() { return location; }

vector<Project> Project::list(Database db) {
  vector<Project> projects;
  string query = "SELECT * FROM projects;";
  auto callback = [&](int argc, char **argv, char **azColName) -> int {
    string id, name, location;
    for (int i = 0; i < argc; i++) {
      if (i == 0)
        id = argv[i];
      if (i == 1)
        name = argv[i];
      if (i == 2)
        location = argv[i];
    }
    projects.push_back(Project(id, name, location));
    return 0;
  };
  db.query(query, callback);
  return projects;
}

void Project::add(const string &name, const string &location, Database db) {
  string query =
      format("INSERT INTO projects (name, location) VALUES ('{}', '{}');", name,
             location);
  db.exec(query);
}
