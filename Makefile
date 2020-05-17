build:
	g++ -w -std=c++14 -Wfatal-errors \
	./src/*.cpp \
	-o game \
	-I "./lib/lua" \
	-L "./lib/lua" \
	-l lua \
	-l SDL2 \
	-l SDL2_image \
	-l SDL2_ttf \
	-l SDL2_mixer;

clean:
	rm ./game;

run:
	./game;