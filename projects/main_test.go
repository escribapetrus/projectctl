package projects

import (
  //  "encoding/json"
    "fmt"
    "testing"
    "database/sql"

  _ "github.com/mattn/go-sqlite3"
)

func Test_List(t *testing.T){
    file := "../projects.db"
    db, err := sql.Open("sqlite3", file)

    if err != nil {
        t.Fatalf("Error opening database")
    }

    projects, err := List(db)
    
    if err != nil {
        t.Fatalf("Error listing projects")
    }

    fmt.Printf("PROJECTS: %+v", projects)
    t.Cleanup(func(){
        db.Close()
    })
}

func Test_FindByName(t *testing.T) {
    // success: found project in the database
    file := "../projects.db"
    expected := "anki"
    db, err := sql.Open("sqlite3", file)

    project := FindByName(expected, db)

    if err != nil {
        t.Fatalf("Error opening database")
    }
    if project == nil {
        t.Fatalf("Project not found")
    }
    if project.name != expected {
        t.Fatalf("Project name incorrect")
    }
    // failure: project not found
    project = FindByName("invalid", db)
   if project != nil {
        t.Fatal("Invalid find failed")
    }
    t.Cleanup(func(){
        db.Close()
    })
}

func Test_Add(t *testing.T){
    name, location := "newproject", "/path/to/project"
    file := "../projects.db"
    db, err := sql.Open("sqlite3", file)
    defer db.Close()

    if err != nil {
        t.Fatalf("Error opening database") 
    }

    _, err = Add(name, location, db)
    
    if err != nil {
        t.Fatalf("Error inserting data")
    }
    t.Cleanup(func(){
        db.Exec("DELETE FROM projects WHERE name=?", name)
        db.Close()
    })

}
