default: main.exe

#----------------Complie main.cpp-----------------------------
main.o: main.cpp convert.h parse.h command.h word.h 
	g++ -c main.cpp 
#------------------------------------------------------------

#---------------Compile command.cpp---------------------------
command.o: command.cpp command.h
	   g++ -c command.cpp 
#-------------------------------------------------------------

#------------------Compile convert.cpp----------------------------
convert.o: convert.cpp convert.h
	   g++ -c convert.cpp  
#----------------------------------------------------------------  


#-------------------Compile parse.cpp-----------------------------
parse.o: parse.cpp 
	 g++ -c parse.cpp
#-----------------------------------------------------------------

#--------------------Compile word.cpp------------------------------
word.o: word.cpp convert.h word.h
	g++ -c word.cpp
#------------------------------------------------------------------

#--------------link object files to executables--------------------
main.exe: main.o parse.o command.o word.o convert.o
	  g++ main.o parse.o command.o word.o convert.o -o main.exe
#-------------------------------------------------------------------




