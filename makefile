SRC = src
INC = inc
OBJ = obj
BIN = bin
LIB = lib

CXX = g++ -g -O2
CPPFLAGS = -ansi -pedantic -Wall -Wextra -Wwrite-strings -Werror -g -c -std=c++0x -I$(INC)

# ************ Program Compilation ************

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libpuzzle.a
	$(CXX) $(OBJ)/main.o -lpuzzle -o $(BIN)/main  -L$(LIB)

# ************ Objects Creation ************

$(OBJ)/piece.o: $(SRC)/piece.cpp $(INC)/piece.h 
	$(CXX) $(CPPFLAGS) $(SRC)/piece.cpp -o $(OBJ)/piece.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/piece.h
	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

# ************ Library Creation ************

$(LIB)/libpuzzle.a : $(OBJ)/piece.o
	ar rvs $(LIB)/libpuzzle.a $(OBJ)/piece.o

# ************ Clean ************

clean:
	echo "Cleaning..."
	rm $(OBJ)/* $(BIN)/* $(LIB)/*
