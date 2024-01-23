# Makefile for  missionaries and cannibals problem solver program 

PROGRAM_NAME = MC_Solver
SOURCE = MCProblem

# Compiler information
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := all

# compilation targets
all: ${PROGRAM_NAME}

${PROGRAM_NAME}: ${SOURCE}.cpp
	$(CC) $(CC_FLAGS) -o $@ $^

clean:
	rm -rf ???*~ *.o

clean-all: clean
	rm -rf ${PROGRAM_NAME}