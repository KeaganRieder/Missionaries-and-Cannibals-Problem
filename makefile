# Makefile for  missionaries and cannibals problem solver program 

# programs and their associated classes
PROGRAM_NAME = MC_Solver

CLASS = State
MAIN = Main

#compiler info
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

#files for Projects
HEADER_1 = $(CLASS).h
OBJS_1 = $(CLASS).0  $(Main).0 $(MC_Solver).0

# Default goal
.DEFAULT_GOAL := all

all: $(PROGRAM_NAME) 

$(PROGRAM_NAME): $(CLASS).o $(MAIN).o
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(CLASS).o $(MAIN).o

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CC) $(CFLAGS) -c $(CLASS).cpp

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CC) $(CFLAGS) -c $(MAIN).cpp

clean:
	$(RM) -f $(PROGRAM_NAME) $(CLASS).o $(MAIN).o

clean-all: clean
	rm -rf ${PROGRAM_NAME1} 




