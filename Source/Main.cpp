#include "PCH.h"

#include "Renderer.h"

const int width = 960, height = 540;

int main()
{
	Renderer* renderer = new Renderer(width, height);

	renderer->Initialize();
	renderer->Run();
	renderer->Shutdown();

	return 0;
}