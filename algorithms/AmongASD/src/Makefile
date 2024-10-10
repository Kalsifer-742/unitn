all: amogasd.cpp
	g++ -o amogasd -std=gnu++11 -g amogasd.cpp

release: amogasd.cpp
	g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o amogasd amogasd.cpp

amogasd.cpp: main.cpp *.hpp
	cat *.hpp main.cpp > amogasd.cpp
