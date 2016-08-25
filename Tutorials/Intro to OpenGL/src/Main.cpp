#include "App.h"

int main()
{
	Application* application = new SolarApp();

	if (application->start() == true)
	{
		while (application->update() == true)
		{
			application->draw();
		}
		application->end();
	}
	delete application;

	return 0;
}