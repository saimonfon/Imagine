CC=g++-4
CFLAGS= 
INCLUDE = -Iirrlicht-1.7.1/include
LDFLAGS= -lIrrlicht -Lirrlicht-1.7.1/lib/Win32-gcc/
EXEC=main
SRC= $(wildcard *.cpp objLoader/*.cpp convexhull/*.cpp geometrie/*.cpp grammaire/*.cpp grammaire/parsing/*.cpp grammaire/condition/*.cpp grammaire/regles/*.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

.PHONY: clean mrproper

doc :
	doxygen Doxyfile
	
clean:
	rm -f $(OBJ)

mrproper: clean
	rm $(EXEC)