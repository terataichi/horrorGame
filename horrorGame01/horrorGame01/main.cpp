#include <DxLib.h>
#include "Scene/SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	if (!lpSceneMng.SystemInit())
	{
		return -1;
	}
	
	lpSceneMng.Run();

	return 0;
}