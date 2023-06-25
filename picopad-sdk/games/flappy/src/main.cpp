
// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************

#include "picopad.h"
#include "include.h"
#include "../img/tilesimg.h"

int main()
{
    DeviceInit();
	// select scene set (returns True = OK, False = Esc)
	while (SetSelect())
	{
		// select scene (returns True = OK, False = Esc)
		while (LevSelect())
		{
			NewGame(True);

			// game loop
			while (GameLoop())
			{
				// continue to next scene
				SceneInx++;
				if (SceneInx >= SceneSetNum) break;
				NewGame(False);
			}
		}
	}

    ResetToBootLoader();
	return 0;
}
