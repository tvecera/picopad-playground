#include "st7789.h"
#include "lib_drawtft.h"
#include "lib_mat2d.h"
#include "picopad_key.h"
#include "picopad_init.h"
#include "sdk_watchdog.h"
#include "lib_pwmsnd.h"
#include "lib_decnum.h"
#include <string.h>
#include <math.h>

#include "main.h"		// main code
#include "objects.h"	// movable objects
#include "balls.h"		// balls
#include "blueenemy.h"	// blue enemies
#include "gameloop.h"	// game loop
#include "gamemap.h"	// game map
#include "chicken.h"	// chicken
#include "levels.h"		// game levels
#include "mushroom.h"	// mushrooms
#include "random.h"		// random number generator
#include "redenemy.h"	// red enemies
#include "select.h"		// select scene
#include "scene.h"		// scene
#include "solutions.h"	// solutions
#include "tiles.h"		// tiles

#include "balls.cpp"
#include "blueenemy.cpp"
#include "gameloop.cpp"
#include "gamemap.cpp"
#include "chicken.cpp"
#include "levels.cpp"
#include "mushroom.cpp"
#include "objects.cpp"
#include "random.cpp"
#include "redenemy.cpp"
#include "scene.cpp"
#include "select.cpp"
#include "solutions.cpp"
#include "tiles.cpp"