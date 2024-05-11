#include "Bankislami.h"
#include<windows.h>
using namespace OOPGUIASSIGNMENT;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Bankislami());
	return 0;
}
