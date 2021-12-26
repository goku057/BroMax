#ifndef SHAPES_H
#define SHAPES_H


class Shapes
{
    public:
        Shapes();
        virtual ~Shapes();
        void circle(int x, int y, double radius, int segments, float r, float g, float b);
        void square(int x, int y, int side, float r, float g, float b);
        void rectangle(int x, int y, int height, int width, float r, float g, float b);
    protected:

    private:
};

#endif // SHAPES_H
