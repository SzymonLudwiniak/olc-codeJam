CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -pthread
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(SRC)/tiles/*.cpp $(SRC)/tileMap/*.cpp $(SRC)/logic/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/shapes -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
