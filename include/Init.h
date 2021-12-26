#include "AllHeaders.h"

#ifndef INIT_H
#define INIT_H
#define ORTHO_LEFT -1000
#define ORTHO_RIGHT 1000
#define ORTHO_TOP 1000
#define ORTHO_BOTTOM -1000
#define ORTHO_NEAR -1000
#define ORTHO_FAR 10000

class Init
{
    public:
        Init();
        virtual ~Init();
        void init();
    protected:

    private:
};

#endif // INIT_H
