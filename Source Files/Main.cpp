#include "../Source Files/Tests/ParticleTest.h"
#include "../Source Files/Tests/ForceTest.h"
#include "../Source Files/Tests/JointTest.h"
#include "../Source Files/Tests/CollisionTest.h"

int main(int argc, char* argv[]) 
{
	Test* test = new ForceTest();
	test->Initialize();

	while (!test->IsQuit())
	{
		test->Run();
	}
	delete(test);

	return 0;

}
