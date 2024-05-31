package projects

import (
    "database/sql"
    
  _ "github.com/mattn/go-sqlite3"
)

type Project struct {
    id string
    name string
    location string
}

func FindByName(name string, db *sql.DB) *Project {
    var project Project = Project{}
    row :=  db.QueryRow(`
        SELECT name, location FROM projects
        WHERE name=?`,
        name)
    
    row.Scan(&project.name, &project.location)
    return &project
}

