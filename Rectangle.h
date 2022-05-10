#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <array>
#include "Vertx.h"

class Rectangle
{
    std::array<Vertex, 4> vertices;
    
    public:       
        Rectangle();
        virtual ~Rectangle();
        const Vertex& getVertex(int ind) const {
		    return vertices[ind];
        }
        void setVertexPos(int ind, const std::array<float,4> _xyzw){
            vertices[ind].setPos(_xyzw);
        }
        void setVertexCol(int ind, const std::array<float,4> _rgba){
            vertices[ind].setCol(_rgba);
        }
        
        void changeColor(int red, int green, int blue, int add);
        void minusRed();
        //void minusRed(); 
};
#endif 
