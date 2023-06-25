#include "st7789.h"
#include "lib_drawtft.h"
#include "lib_mat2d.h"
#include "picopad_key.h"
#include "picopad_init.h"
#include "sdk_watchdog.h"
#include "lib_pwmsnd.h"
#include "lib_decnum.h"
#include "lib_rand.h"
#include "picopad_fonts.h"
#include <string.h>
#include <math.h>

#include "main.h"		// game engine
#include "game.h"		// game engine
#include "game.cpp"		// game engine

#include "../img/background.cpp"
#include "../img/blacksreds.cpp"
#include "../img/cards.cpp"
#include "../img/castle.cpp"
#include "../img/cloud.cpp"
#include "../img/cursor.cpp"
#include "../img/fence.cpp"
#include "../img/flags.cpp"
#include "../img/grass.cpp"
#include "../img/shadow.cpp"
#include "../img/state.cpp"
#include "../img/trumpet.cpp"
#include "../img/win.cpp"

#include "../snd/applause.cpp"
#include "../snd/build_castle.cpp"
#include "../snd/build_fence.cpp"
#include "../snd/card.cpp"
#include "../snd/curse.cpp"
#include "../snd/decrease_stocks.cpp"
#include "../snd/fanfares.cpp"
#include "../snd/increase_power.cpp"
#include "../snd/increase_stocks.cpp"
#include "../snd/ruin_castle.cpp"
#include "../snd/ruin_fence.cpp"