CXX = $(shell wx-config --cxx)
 
PROGRAM = elipsus
SOURCES := main.cpp dialogs/appframe.cpp 
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

# implementation
 
.SUFFIXES: .o .cpp
 
.cpp.o :
	$(CXX) -c `wx-config --cxxflags` -o $@ $<
 
all: $(PROGRAM)
 
$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs`

clean:
	rm -f *.o $(PROGRAM)
	rm -f ./dialogs/*.o
