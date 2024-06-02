package projects

import (
    "database/sql"
   "fmt" 
  _ "github.com/mattn/go-sqlite3"
)

type Project struct {
    id string
    name string
    location string
}

func FindByName(name string, db *sql.DB) *Project {
    row :=  db.QueryRow(`
        SELECT name, location FROM projects
        WHERE name=?`,
        name)
        fmt.Printf("err: %+v", row.Err())
    project := Project{}
    row.Scan(&project.name, &project.location)
    
    if project.name == name { return &project }
    return nil

}

func Add(name string, location string, db *sql.DB) (int, error) {
    var project Project = Project{name: name, location: location}
    res, err := db.Exec(`INSERT INTO projects (name, location)
    VALUES (?,?)`,
    project.name, project.location)

    if err != nil { return 0, err}

    var rows int64
    rows, err = res.RowsAffected()
    return int(rows), err 
}
