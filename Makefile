# Makefile
auction: ./Authentication/Authentication.cpp ./Users/User.cpp ./Users/Admin/Admin.cpp ./Users/BuyStandard/BuyStandard.cpp \
./Users/SellStandard/SellStandard.cpp ./Users/FullStandard/FullStandard.cpp \
./TransactionWriter/TransactionWriter.cpp main.cpp
	g++ -std=c++0x -o auction ./Authentication/Authentication.cpp ./Users/Admin/Admin.cpp ./Users/BuyStandard/BuyStandard.cpp \
./Users/SellStandard/SellStandard.cpp ./Users/FullStandard/FullStandard.cpp \
./Users/User.cpp ./TransactionWriter/TransactionWriter.cpp main.cpp