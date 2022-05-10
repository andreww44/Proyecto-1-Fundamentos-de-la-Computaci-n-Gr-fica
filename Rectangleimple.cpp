#include "Rectangle.h"


Rectangle::~Rectangle(){

}

Rectangle::Rectangle(){
    
    std::array<float,4> _xyzw_1 = { 0.5f, -0.5f, 0.0, 1.0f };//bottom right
    std::array<float,4> _rgba_1 = { 0.5f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_2 = {-0.5f, -0.5f, 0.0f, 1.0f};//Bottom Left
    std::array<float,4> _rgba_2 = { 0.5f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_3 = { 0.5f, 0.5f, 0.0, 1.0f };//Top Right
    std::array<float,4> _rgba_3 = { 0.5f, 0.0f, 0.0f, 1.0f };

    std::array<float,4> _xyzw_4 = {-0.5f, 0.5f, 0.0, 1.0f };//Top Left
    std::array<float,4> _rgba_4 = { 0.5f, 0.0f, 0.0f, 1.0f };

    vertices[0] = Vertex(_xyzw_1, _rgba_1);//BT
    vertices[1] = Vertex(_xyzw_2, _rgba_2);//BL
    vertices[2] = Vertex(_xyzw_3, _rgba_3);//TR
    vertices[3] = Vertex(_xyzw_4, _rgba_4);//TL

}

void Rectangle::changeColor(int red, int green, int blue, int add){
    
    float redcolor = vertices[0].getColor()[0];
    float greencolor = vertices[0].getColor()[1];
    float bluecolor = vertices[0].getColor()[2];
    //float alpha = vertices[0].getColor()[3];

    if(red == 1)
    {
        if(vertices[0].getColor()[0] >= 1.0f || vertices[0].getColor()[0] < 0.0f)
        { return; }
        if(add == 1){redcolor += 0.1f;}
        else{redcolor -= 0.1f;}
    }
    if(green == 1)
    {
        if(vertices[0].getColor()[1] >= 1.0f || vertices[0].getColor()[1] < 0.0f)
        { return; }
        if(add == 1){greencolor += 0.1f;}
        else{greencolor -= 0.1f;}
    }
    if(blue == 1)
    {
        if(vertices[0].getColor()[2] >= 1.0f || vertices[0].getColor()[2] < 0.0f)
        { return; }
        if(add == 1){bluecolor += 0.1f;}
        else{bluecolor -= 0.1f;}
    }

    std::array<float,4> rgba = { redcolor, greencolor, bluecolor, 1.0f };
    vertices[0].setCol(rgba);
    vertices[1].setCol(rgba);
    vertices[2].setCol(rgba);
    vertices[3].setCol(rgba);
}



