all: glad.c Rectangle.h Vertx.h main.cpp Rectangleimple.cpp Vertximpl.cpp Screen.h ScreenImpl.cpp
	g++ main.cpp glad.c Rectangleimple.cpp Vertximpl.cpp ScreenImpl.cpp Rectangle.h Vertx.h Screen.h -ldl -lglfw -lGLEW -lGL -o a

run: 
	./a

clean: 
	rm a

test: glad.c example.cpp 
	g++ example.cpp glad.c -ldl -lGLEW -lGL -lglut -o b

runtest: 
	./b