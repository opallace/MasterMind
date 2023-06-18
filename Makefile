#OBJS specifies which files to compile as part of the project
OBJS = main.cpp MasterMind.cpp Jogador.cpp CodeMaker.cpp CodeBreaker.cpp Bot.cpp Cores.cpp

#CC specifies which compiler we're using
CC = g++

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)