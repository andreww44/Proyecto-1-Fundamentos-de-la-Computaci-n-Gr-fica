#include "Rectangle.h"


Rectangle::~Rectangle(){

}

Rectangle::Rectangle(const std::array<float,4> _xyzw, const std::array<float,4> _rgba){
    vertex = Vertex(_xyzw, _rgba);
}

