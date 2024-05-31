package projects

import (
  //  "encoding/json"
  //  "fmt"
    "testing"
    "database/sql"

  _ "github.com/mattn/go-sqlite3"
)

func Test_FindByName(t *testing.T) {
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
}
