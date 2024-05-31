-- setup tables
CREATE TABLE projects (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    location TEXT NOT NULL
);

-- seed tables
INSERT INTO projects (name, location)
VALUES
    ("ankicli", "/Users/pedroschreiber/Code/ankicli"),
    ("cli", "/Users/pedroschreiber/Code/cli"),
    ("anki", "/Users/pedroschreiber/Code/anki");
