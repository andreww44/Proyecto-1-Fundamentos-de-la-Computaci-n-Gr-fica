#include "Vertx.h"

Vertex::Vertex(const std::array<float,4> _xyzw, const std::array<float,4> _rgba){

	std::copy(std::begin(_xyzw), std::end(_xyzw),std::begin(XYZW));
	std::copy(std::begin(_rgba), std::end(_rgba),std::begin(RGBA));
}

Vertex::Vertex(){

}

Vertex::~Vertex(){

}

std::array<float,4>
Vertex::getPos() const{
	return XYZW;
}

std::array<float,4>
Vertex::getColor() const{
	return RGBA;
}