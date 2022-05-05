#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <array>
#include "Vertx.h"

class Rectangle
{
    Vertex vertex;
    public:
        Rectangle(const std::array<float,4> _xyzw, const std::array<float,4> _rgba);
        virtual ~Rectangle();
        const Vertex& getVertex() const {
		    return vertex;
        }

};
#endif 
