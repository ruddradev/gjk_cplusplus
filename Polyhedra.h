#ifndef POLYHEDRA_H
#define POLYHEDRA_H

#include "Point.h"
class Polyhedra
{
    public:
		Vector* pointList;
		Polyhedra();
        Polyhedra(Vector list[]);
        virtual ~Polyhedra();
		virtual Vector getSupport(Vector);
    protected:
    private:
};

#endif // POLYHEDRA_H
