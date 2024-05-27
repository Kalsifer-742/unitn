got2: got2.cpp
	/usr/bin/g++ -std=gnu++11 -g -o got2 grader.cpp got2.cpp -Wall -Wno-sign-compare

release: got2.cpp
	/usr/bin/g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o got2 grader.cpp got2.cpp

run: got2 
	@time ./got2 > /tmp/got2output
	@echo "output.txt:"
	@cat output.txt
	@echo "stdout:"
	@cat /tmp/got2output
