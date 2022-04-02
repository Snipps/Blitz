#pragma once

#include <Blitz/Common.h>
#include <Blitz/Math/Rect.h>
#include <Blitz/Enum.h>

namespace Blitz {

class Window
{
public:
	enum class Mode
	{
		Windowed,
		Fullscreen,
		FullscreenWindow
	};

	struct Config
	{
		Mode mode;
		Rect<int> rect;
	};

	static constexpr Config defaultConfig = { Mode::Windowed, {0, 0, 1280, 720 } };

	Window(Config config);

	bool IsAlive() const;
};

} // namespace Blitz