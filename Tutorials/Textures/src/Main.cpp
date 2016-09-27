#include "App.h"

int main()
{
	Application* application = new /*Textures*/Advance();

	if (application->start() == true)
	{
		while (application->update() == true)
		{
			application->draw();
		}
		application->destroy();
	}
	delete application;

	return 0;
}