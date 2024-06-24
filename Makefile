build: 
	mkdir -p bin
	g++ -g -std=c++20 \
		-Iinclude \
			main.cpp \
			project.cpp \
			db.cpp \
		-l sqlite3 \
		-o bin/projectctl 

build-debug: 
	mkdir -p bin
	g++ -g -std=c++20 \
		-Iinclude \
			main.cpp \
			project.cpp \
			db.cpp \
		-l sqlite3 \
		-o bin/projectctl 

debug: build-debug
	lldb ./bin/projectctl

run:
	./bin/projectctl

test: 
	go test ./...

clean: 
	rm -rf bin
