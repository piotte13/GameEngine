#include "source/graphics/window.h"
#include "source/maths/maths.h"

int main() {
	using namespace gameEngine;
	using namespace graphics;
	using namespace maths;
	
	Window window("JEngine", 1600, 900);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	vec3 a(1.0f, 1.0f, 1.0f);
	vec3 b(2, 3, 4);
	vec3 c = a + b;


	while (!window.closed()) {

		window.clear();
		std::cout << a << std::endl;
	

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}

	//system("PAUSE");
	return 0;
}