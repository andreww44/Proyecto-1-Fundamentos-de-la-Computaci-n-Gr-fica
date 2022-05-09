#include "Rectangle.h"


Rectangle::~Rectangle(){

}

Rectangle::Rectangle(){
    
    std::array<float,4> _xyzw_1 = { 0.5f, -0.5f, 0.0, 1.0f };//bottom right
    std::array<float,4> _rgba_1 = { 0.9f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_2 = {-0.5f, -0.5f, 0.0f, 1.0f};//Bottom Left
    std::array<float,4> _rgba_2 = { 1.0f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_3 = { 0.5f, 0.5f, 0.0, 1.0f };//Top Right
    std::array<float,4> _rgba_3 = { 1.0f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_4 = {-0.5f, 0.5f, 0.0, 1.0f };//Top Left
    std::array<float,4> _rgba_4 = { 1.0f, 0.0f, 0.0f, 1.0f };

    vertices[0] = Vertex(_xyzw_1, _rgba_1);//BT
    vertices[1] = Vertex(_xyzw_2, _rgba_2);//BL
    vertices[2] = Vertex(_xyzw_3, _rgba_3);//TR
    vertices[3] = Vertex(_xyzw_4, _rgba_4);//TL

}



