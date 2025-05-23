#include "game.h"

#include <core/logger.h>

b8 game_initialize(game* game_inst)
{
    KDEBUG("game_initialize() was called!")
    return true;
}

b8 game_update(game* game_inst, f32 delta_time)
{
    KDEBUG("game_update() was called!")
    return true;
}

b8 game_render(game* game_inst, f32 delta_time)
{
    KDEBUG("game_render() was called!")
    return true;
}

void game_on_resize(game* game_inst, u32 width, u32 height)
{
    KDEBUG("game_on_resize() was called!")
    return;
}
