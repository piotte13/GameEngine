#include "Window.h"


namespace gameEngine {
	namespace graphics {
		//Declaration of static methods
		void window_resize(GLFWwindow *window, int width, int height);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		//Window constructor
		Window::Window(const char *title, int width, int height) 
		{
		
			m_Title = title;
			m_Width = width;
			m_Height = height;

			//initialize GLFW
			if (!init()) glfwTerminate();

			//Initialize input arrays
			for (int i = 0; i < MAX_KEYS; i ++ ) {
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i ++ ) {
				m_MouseButtons[i]  = false;
			}
		}
		//Destructor
		Window::~Window() 
		{
			glfwTerminate();
		}
		//Window initializor
		bool Window::init() 
		{
			//initialise GLFW
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}
			else
				std::cout << "Success!" << std::endl;
			//Create Window
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			//Check if window creation worked.
			if (!m_Window) {
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);

			//Window resize callback
			glfwSetWindowSizeCallback(m_Window, window_resize);

			//Set input callbacks
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			//GlEW initialisor
			if (glewInit() != GLEW_OK) {
				std::cout << "Could not initialize GLEW" << std::endl;
				return false;
			}

			std::cout << "OpenGl " << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode) const 
		{
			if (keycode >= MAX_KEYS) return false;
			return m_keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const 
		{
			if (button >= MAX_BUTTONS) return false;
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const 
		{
			x = mx;
			y = my;
		}
		//Clear window
		void Window::clear() const 
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		//Update window
		void Window::update() 
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const 
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void window_resize(GLFWwindow *window, int width, int height) 
		{
			glViewport(0, 0, width, height);
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) 
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_keys[key] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}

//End of namespace
	}
}