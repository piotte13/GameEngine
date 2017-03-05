#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace gameEngine{

#define MAX_KEYS	1024
#define MAX_BUTTONS	32


	namespace graphics {
	
		class Window {
		private:
			int m_Width, m_Height;
			const char *m_Title;
			GLFWwindow *m_Window;
			bool m_Closed;

			//inputs events
			bool m_keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			//mouse position
			double mx, my;

		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;

		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	//end of namespaces
	}
}