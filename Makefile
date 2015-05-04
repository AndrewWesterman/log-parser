default: main.exe

#----------------Complie main.cpp----------------------------------
main.o: main.cpp convert.h parse.h command.h word.h rate.h time.h 
	g++ -std=c++11 -c main.cpp 
#-----------------------------------------------------------------

#---------------Compile command.cpp---------------------------
command.o: command.cpp command.h
	   g++ -std=c++11 -c command.cpp 
#-------------------------------------------------------------

#------------------Compile convert.cpp----------------------------
convert.o: convert.cpp convert.h
	   g++ -std=c++11 -c convert.cpp  
#----------------------------------------------------------------  


#-------------------Compile parse.cpp-----------------------------
parse.o: parse.cpp parse.h
	 g++ -std=c++11 -c parse.cpp
#-----------------------------------------------------------------

#-------------------Compile rate.cpp------------------------------
rate.o: rate.cpp rate.h
	g++ -std=c++11 -c rate.cpp
#-----------------------------------------------------------------

#-------------------Compile time.cpp------------------------------
time.o: time.cpp rate.h time.h
	g++ -std=c++11 -c time.cpp
#-----------------------------------------------------------------

#--------------------Compile word.cpp------------------------------
word.o: word.cpp convert.h word.h
	g++ -std=c++11 -c word.cpp
#------------------------------------------------------------------

#--------------link object files to executables-----------------------------------
main.exe: main.o parse.o command.o word.o rate.o time.o convert.o
	  g++ main.o parse.o command.o word.o rate.o time.o convert.o -o main.exe
#-------------------------------------------------------------------------------

#--------------Clean object files and main.exe-----------------------------------
clean: 
	rm *.o *~ main.exe


