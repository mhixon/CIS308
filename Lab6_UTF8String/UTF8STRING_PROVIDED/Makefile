all: utf8test
	
utf8test: utf8test.cpp utf8string.o ksu_utf8.o ksu_unicode.o
	g++ -o utf8test utf8test.cpp utf8string.o ksu_utf8.o ksu_unicode.o 

clean: 
	rm *.o utf8test
