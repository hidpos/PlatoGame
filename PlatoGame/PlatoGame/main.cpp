#include "dewcin.h"

dewcin_app_entry_point
{
	dewcin::Game::SetGameUpdate([&](float delta)
		{
			OutputDebugString(L"game update!");
		}
	);

	return 0;
}