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

    vertices[0] = Vertex(_xyzw_1, _rgba_1);//BR
    vertices[1] = Vertex(_xyzw_2, _rgba_2);//BL
    vertices[2] = Vertex(_xyzw_3, _rgba_3);//TR
    vertices[3] = Vertex(_xyzw_4, _rgba_4);//TL

}

void Rectangle::changeColor(int red, int green, int blue, int add){
    
    float redcolor = vertices[0].getColor()[0];
    float greencolor = vertices[0].getColor()[1];
    float bluecolor = vertices[0].getColor()[2];
    float range = 0.05f;

    if(red == 1)
    {
        if(add == 1 && vertices[0].getColor()[0] <= 1.0f)
        {
            redcolor += range;
        }
        else if(add == 0 && vertices[0].getColor()[0] >= 0.0f)
        {
            redcolor -= range;
        }
    }
    if(green == 1)
    {
        if(add == 1 && vertices[0].getColor()[1] <= 1.0f )
        {
            greencolor += range;
        }
        else if(add == 0 && vertices[0].getColor()[1] >= 0.0f)
        {
            greencolor -= range;
        }
    }
    if(blue == 1)
    {
        if(add == 1 && vertices[0].getColor()[2] <= 1.0f )
        {
            bluecolor += range;
        }
        else if(add == 0 && vertices[0].getColor()[2] >= 0.0f)
        {
            bluecolor -= range;
        }
    }

    std::array<float,4> rgba = { redcolor, greencolor, bluecolor, 1.0f };
    vertices[0].setCol(rgba);
    vertices[1].setCol(rgba);
    vertices[2].setCol(rgba);
    vertices[3].setCol(rgba);
}

void Rectangle::changeSize(int add)
{

    float range = 0.1f;
    
    std::array<float,4> xyzw_0 = { vertices[0].getPos()[0]+range , vertices[0].getPos()[1]-range, vertices[0].getPos()[3], vertices[0].getPos()[4] };//BR
    std::array<float,4> xyzw_1 = { vertices[1].getPos()[0]-range , vertices[1].getPos()[1]-range, vertices[1].getPos()[3], vertices[1].getPos()[4] };//BL
    std::array<float,4> xyzw_2 = { vertices[2].getPos()[0]+range , vertices[2].getPos()[1]+range, vertices[2].getPos()[3], vertices[2].getPos()[4] };//TR
    std::array<float,4> xyzw_3 = { vertices[3].getPos()[0]-range , vertices[3].getPos()[1]+range, vertices[3].getPos()[3], vertices[3].getPos()[4] };//TL
    
    vertices[0].setPos(xyzw_0);
    vertices[1].setPos(xyzw_1);
    vertices[2].setPos(xyzw_2);
    vertices[3].setPos(xyzw_3);
    
}



