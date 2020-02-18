# Makefile
auction: ./Authentication/Authentication.cpp main.cpp
	g++ -o auction ./Authentication/Authentication.cpp main.cpp 