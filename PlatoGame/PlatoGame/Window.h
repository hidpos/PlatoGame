#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	bool init();
	bool release() const;
	bool broadcast();
	bool isRun() const;

	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy();

	~Window();
private:
	HWND m_hwnd{};
	bool m_is_run;
};