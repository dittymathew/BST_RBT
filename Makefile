all : hello
hello : main.o
		g++ main.o -o run
main.o : main.cpp tree.h rbt.o bst.o
		g++ -c main.cpp rbt.cpp bst.cpp
rbt.o : rbt.cpp tree.h
		g++ -c rbt.cpp
bst.o : bst.cpp tree.h
		g++ -c bst.cpp
clean:
	rm -rf run
	rm -rf main.o
	rm -rf bst.o
	rm -rf rbt.o
