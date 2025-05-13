#include <core/asserts.h>
#include <core/logger.h>
#include <platform/platform.h>

int main(int argc, char** argv)
{
    KFATAL("oh man, this guy STINKS. id: %f", 1.0f);
    KERROR("oh man, this guy STINKS. id: %f", 1.0f);
    KWARN("oh man, this guy STINKS. id: %f", 1.0f);
    KINFO("oh man, this guy STINKS. id: %f", 1.0f);
    KDEBUG("oh man, this guy STINKS. id: %f", 1.0f);
    KTRACE("oh man, this guy STINKS. id: %f", 1.0f);

    platform_state state;
    if (platform_startup(&state, "KhoPhee Engine Testbed", 100, 100, 1280, 720)) {
        while (true) {
            if (!platform_pump_messages(&state))
                break;
        }
    }
    platform_shutdown(&state);
    KINFO("closed window 1");
    platform_sleep(1000);

    if (platform_startup(&state, "KhoPhee Engine Testbed", 100, 100, 1280, 720)) {
        while (true) {
            if (!platform_pump_messages(&state))
                break;
        }
    }
    platform_shutdown(&state);
    KINFO("closed window 2");
    platform_sleep(1000);

    if (platform_startup(&state, "KhoPhee Engine Testbed", 100, 100, 1280, 720)) {
        while (true) {
            if (!platform_pump_messages(&state))
                break;
        }
    }
    platform_shutdown(&state);
    KINFO("closed window 3");

    return 0;
}
