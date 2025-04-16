CXX = g++
CXXFLAGS = -Wall

main: main.c
	$(CXX) $(CXXFLAGS) -g main.c matrix.c -o mainc