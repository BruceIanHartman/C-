# define target dependencies and files
cruiseshipapp: cruiseshipapp.o passenger.o activity.o
	g++ -o cruiseshipapp cruiseshipapp.o passenger.o activity.o

cruiseshipapp.o: cruiseshipapp.cpp passenger.h activity.h
	g++ -c cruiseshipapp.cpp -W -Wall --pedantic

passenger.o: passenger.cpp passenger.h activity.h
	g++ -c passenger.cpp -W -Wall --pedantic

activity.o: activity.cpp activity.h passenger.h
	g++ -c activity.cpp -W -Wall --pedantic

# clean up
clean:
	rm -f cruiseshipapp *.o
