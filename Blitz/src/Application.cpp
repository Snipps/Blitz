#include <Blitz/Application.h>

namespace Blitz {

Application::Application() :
	Application(Window::defaultConfig)
{}

Application::Application(Window::Config windowConfig) :
	mUptime(0)
{
	mWindows.emplace_back(windowConfig);
}

Application::~Application()
{

}

Window* Application::GetWindow(int index)
{
	if (index < mWindows.size()) {
		Window* window = &mWindows[index];
		if (window->IsAlive())
			return window;
	}

	return nullptr;
}

const Window* Application::GetWindow(int index) const
{
	return const_cast<Application*>(this)->GetWindow();
}

} // namespace Blitz