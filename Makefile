CC = g++
CFLAGS = -std=c++11

default: main.exe

#----------------Complie main.cpp----------------------------------
main.o: main.cpp convert.h parse.h command.h word.h rate.h time.h 
	$(CC) $(CFLAGS) -c main.cpp 
#-----------------------------------------------------------------

#---------------Compile command.cpp---------------------------
command.o: command.cpp command.h
	   $(CC) $(CFLAGS) -c command.cpp 
#-------------------------------------------------------------

#------------------Compile convert.cpp----------------------------
convert.o: convert.cpp convert.h
	   $(CC) $(CFLAGS) -c convert.cpp  
#----------------------------------------------------------------  


#-------------------Compile parse.cpp-----------------------------
parse.o: parse.cpp parse.h
	 $(CC) $(CFLAGS) -c parse.cpp
#-----------------------------------------------------------------

#-------------------Compile rate.cpp------------------------------
rate.o: rate.cpp rate.h
	$(CC) $(CFLAGS) -c rate.cpp
#-----------------------------------------------------------------

#-------------------Compile time.cpp------------------------------
time.o: time.cpp rate.h time.h
	$(CC) $(CFLAGS) -c time.cpp
#-----------------------------------------------------------------

#--------------------Compile word.cpp------------------------------
word.o: word.cpp convert.h word.h
	$(CC) $(CFLAGS) -c word.cpp
#------------------------------------------------------------------

#--------------link object files to executables-----------------------------------
main.exe: main.o parse.o command.o word.o rate.o time.o convert.o
	  g++ main.o parse.o command.o word.o rate.o time.o convert.o -o main.exe
#-------------------------------------------------------------------------------

#--------------Clean object files and main.exe-----------------------------------
clean: 
	rm *.o *~ main.exe results.log


