#include "game.h"

#include <core/kmemory.h>
#include <entry.h>

#include <stdlib.h>

b8 create_game(game* out_game)
{
    // Application configuration.
    out_game->app_config.start_pos_x = 100;
    out_game->app_config.start_pos_y = 100;
    out_game->app_config.start_width = 1280;
    out_game->app_config.start_height = 720;
    out_game->app_config.name = "Kohi Engine Testbed";

    out_game->initialize = game_initialize;
    out_game->update = game_update;
    out_game->render = game_render;
    out_game->on_resize = game_on_resize;

    // TEMPORARY
    out_game->state = kallocate(sizeof(game_state), MEMORY_TAG_GAME);

    return true;
}
