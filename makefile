CXX = g++
CXXFLAGS = -Wall

maincpp: main.cpp
	$(CXX) $(CXXFLAGS) -g main.cpp matrix.cpp -o maincpp

mainc: main.c
	$(CXX) $(CXXFLAGS) -g main.c matrix.c -o mainc
