build: 
	mkdir -p bin
	go build -o bin/projectctl

run:
	./bin/projectctl

test: 
	go test ./...

clean: 
	rm -rf bin
