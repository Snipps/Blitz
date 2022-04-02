#pragma once

#include <Blitz/Common.h>
#include <Blitz/Window.h>

#include <vector>

namespace Blitz {

class Application
{
private:
	double mUptime;
	std::vector<Window> mWindows;
public:
	Application();
	Application(Window::Config windowConfig);
	~Application();

	inline double GetUptime() const { return mUptime; }
	Window* GetWindow(int index = 0);
	const Window* GetWindow(int index = 0) const;
};

} // namespace Blitz