CXX = g++
CXXFLAGS = -Wall

proj4: Animal.o Carnivore.o Herbivore.o Gazelle.o Lion.o Elephant.o Safari.o driver.cpp
	$(CXX) $(CXXFLAGS) Animal.o Carnivore.o Herbivore.o Gazelle.o Elephant.o Lion.o Safari.o driver.cpp -o proj4

testDrive: Animal.o Carnivore.o Herbivore.o Gazelle.o Lion.o Elephant.o Safari.o testDriver.cpp
	$(CXX) $(CXXFLAGS) Animal.o Carnivore.o Herbivore.o Gazelle.o Elephant.o Lion.o Safari.o testDriver.cpp -o proj4


Animal.o:Animal.cpp Animal.h
	 $(CXX) $(CXXFLAGS)  -c Animal.cpp

Carnivore.o:Animal.o Carnivore.cpp Carnivore.h
	$(CXX) $(CXXFLAGS)  -c Carnivore.cpp

Herbivore.o: Animal.o Herbivore.cpp Herbivore.h
	$(CXX) $(CXXFLAGS) -c Herbivore.cpp

Gazelle.o:Herbivore.o Gazelle.cpp Gazelle.h
	$(CXX) $(CXXFLAGS)  -c Gazelle.cpp

Elephant.o:Herbivore.o Elephant.cpp Elephant.h
	$(CXX) $(CXXFLAGS)  -c Elephant.cpp

Lion.o:Carnivore.o Lion.cpp Lion.h
	 $(CXX) $(CXXFLAGS)  -c Lion.cpp

Safari.o:Animal.o Carnivore.o Herbivore.o Gazelle.o Lion.o Elephant.o Safari.cpp Safari.h
	$(CXX) $(CXXFLAGS)  -c Safari.cpp


clean:
	rm *.o*
	rm *~

run1:
	valgrind ./proj4 proj4_t1.txt

run2:
	valgrind ./proj4 proj4_t2.txt

run3:
	valgrind ./proj4 proj4_t3.txt


