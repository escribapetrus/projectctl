build: 
	mkdir -p bin
	g++ -std=c++20 \
		-Iinclude \
			main.cpp \
			project.cpp \
			db.cpp \
		-l sqlite3 \
		-o bin/projectctl 
run:
	./bin/projectctl

test: 
	go test ./...

clean: 
	rm -rf bin
