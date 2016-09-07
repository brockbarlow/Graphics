#include "Render.h"

int main()
{
	//printf("size of Vertex is: %i\n", sizeof(Vertex));
	//system("pause");
	
	Application* application = new RenderingGeometry();

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