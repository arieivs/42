#include "Warlock.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"

int main()
{
	Warlock			richard("Richard", "foo");
	Fireball*		fireball = new Fireball();
	Polymorph*		polymorph = new Polymorph();
	TargetGenerator	tarGen;
	BrickWall		model1;

	richard.setTitle("Hello, I'm Richard the Warlock!");
	richard.learnSpell(polymorph);
	richard.learnSpell(fireball);

	tarGen.learnTargetType(&model1);
	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);

	delete fireball;
	delete polymorph;
	delete wall;
}
