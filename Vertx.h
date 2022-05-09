
#ifndef VERTEX_H_
#define VERTEX_H_
#include <array>

class Vertex
{
    std::array<float,4> XYZW;  
    std::array<float,4> RGBA; 

    public:
        Vertex(const std::array<float,4> xyzw, const std::array<float,4> rgba);
        Vertex();
        virtual ~Vertex();
        std::array<float,4> getPos() const;
        std::array<float,4> getColor() const;
        void setPos(const std::array<float,4> _xyzw);
        void setCol(const std::array<float,4> _rgba);
};
#endif 
