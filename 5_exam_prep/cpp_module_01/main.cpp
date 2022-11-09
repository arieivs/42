#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

/*
 * Sadly they don't care about memory leaks
 * in the mains provided in the subject.
*/

int main(void)
{
	Warlock richard("Richard", "the Titled");
	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);
	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.learnSpell(fwoosh);
	richard.launchSpell("Fwoosh", bob);

	delete fwoosh;
}
