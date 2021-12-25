#ifndef CRENDER_H
#define CRENDER_H


class cRender
{
    public:
        cRender();
        virtual ~cRender();
        void setCamera(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ);
        void display();
        void animate();

    protected:

    private:
};

#endif // CRENDER_H
