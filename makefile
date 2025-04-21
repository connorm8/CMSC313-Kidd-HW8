CPPFLAGS = -O0
CFLAGS = -std=c99 -m32 -O0

maincpp: main.cpp
	g++ $(CPPFLAGS) main.cpp matrix.cpp -o maincpp

mainc: main.c
	gcc $(CFLAGS) main.c matrix.c -o mainc

testcpp: test.cpp
	g++ $(CPPFLAGS) test.cpp matrix.cpp -o testcpp

testc: test.c
	gcc $(CFLAGS) test.c matrix.c -o testc