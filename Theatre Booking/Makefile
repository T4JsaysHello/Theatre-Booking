TheatreBookingSystem: Events.o main.o
	g++ Events.o main.o -o TheatreBookingSystem

Events.o: Events.cpp Events.h
	g++ -c Events.cpp

main.o: main.cpp
	g++ -c main.cpp

.PHONY : clean
clean :
	rm *.o
	rm TheatreBookingSystem
