LINKER_FLAGS=-lSDL2
C_FLAGS=-w

main:
	g++ main.cpp $(LINKER_FLAGS) $(C_FLAGS) -o main.out
	./main.out

wasm:
	emcc -O1 main.cpp -s USE_SDL=2 -o voronoi.html