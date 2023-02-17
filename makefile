all: build/main.exe

build/main.exe: build/colors.o build/main.o build/math.o build/particule.o build/progSDL.o build/world.o
	g++ -o build/main.exe build/colors.o build/main.o build/math.o build/particule.o build/progSDL.o build/world.o -lSDL2

build/colors.o: src/colors.cpp include/Colors.hpp
	g++ -c -o build/colors.o src/colors.cpp -I include

build/main.o: src/main.cpp include/ProgSDL.hpp
	g++ -c -o build/main.o src/main.cpp -I include

build/math.o: src/math.cpp include/Math.hpp
	g++ -c -o build/math.o src/math.cpp -I include

build/particule.o: src/particule.cpp include/Particule.hpp include/Utils.hpp include/Math.hpp include/Colors.hpp
	g++ -c -o build/particule.o src/particule.cpp -I include

build/progSDL.o: src/progSDL.cpp include/ProgSDL.hpp include/Utils.hpp include/Colors.hpp include/World.hpp include/Particule.hpp include/Math.hpp
	g++ -c -o build/progSDL.o src/progSDL.cpp -I include

build/world.o: src/world.cpp include/World.hpp include/Particule.hpp include/Utils.hpp include/Math.hpp include/Colors.hpp
	g++ -c -o build/world.o src/world.cpp -I include

clean:
	rm -f build/*.o build/*.exe

# Path: src/main.cpp