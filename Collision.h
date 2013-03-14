#include <vector>
#include "Polyhedra.h"

class Collision
{
public:
	Collision(Polyhedra,Polyhedra);
	virtual ~Collision(void);
	Vector support(Vector);
	bool checkCollision();
	Vector Collision::updateDir(std::vector<Vector>);
private:
	Polyhedra a;
	Polyhedra b;
	std::vector<Vector> simplex;
	Vector origin;
};
