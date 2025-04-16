CXX = g++
CXXFLAGS = -Wall

main: main.cpp
	$(CXX) $(CXXFLAGS) -g main.cpp matrix.cpp -o maincpp