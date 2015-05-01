default: main.exe

#----------------Complie main.cpp-----------------------------
main.o: main.cpp convert.h parse.h command.h word.h 
	g++ -std=c++11 -c main.cpp 
#------------------------------------------------------------

#---------------Compile command.cpp---------------------------
command.o: command.cpp command.h
	   g++ -std=c++11 -c command.cpp 
#-------------------------------------------------------------

#------------------Compile convert.cpp----------------------------
convert.o: convert.cpp convert.h
	   g++ -std=c++11 -c convert.cpp  
#----------------------------------------------------------------  


#-------------------Compile parse.cpp-----------------------------
parse.o: parse.cpp 
	 g++ -std=c++11 -c parse.cpp
#-----------------------------------------------------------------

#--------------------Compile word.cpp------------------------------
word.o: word.cpp convert.h word.h
	g++ -std=c++11 -c word.cpp
#------------------------------------------------------------------

#--------------link object files to executables--------------------
main.exe: main.o parse.o command.o word.o convert.o
	  g++ main.o parse.o command.o word.o convert.o -o main.exe
#-------------------------------------------------------------------




