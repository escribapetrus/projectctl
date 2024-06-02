package projects

import (
  //  "encoding/json"
    "fmt"
    "testing"
    "database/sql"

  _ "github.com/mattn/go-sqlite3"
)

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
}

func Test_Add(t *testing.T){
    name, location := "newproject", "/path/to/project"
    file := "../projects.db"
    db, err := sql.Open("sqlite3", file)
   
    if err != nil {
        t.Fatalf("Error opening database") 
    }

    int, err := Add(name, location, db)
    
    if err != nil {
        t.Fatalf("Error inserting data")
    }
  fmt.Printf("Inserted %d entries", int)

   fmt.Printf("added project: +v", FindByName("name", db))

}
