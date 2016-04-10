#include <stdlib.h>
#include "MemLeaks.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

int main(int argc, char* argv[])
{
	ReportMemoryLeaks();

	system("pause");
	return 0;
}