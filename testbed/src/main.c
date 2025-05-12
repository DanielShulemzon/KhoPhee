#include <core/asserts.h>
#include <core/logger.h>

int main(int argc, char** argv)
{
    KFATAL("oh man, this guy STINKS. id: %f", 1.0f);
    KERROR("oh man, this guy STINKS. id: %f", 1.0f);
    KWARN("oh man, this guy STINKS. id: %f", 1.0f);
    KINFO("oh man, this guy STINKS. id: %f", 1.0f);
    KDEBUG("oh man, this guy STINKS. id: %f", 1.0f);
    KTRACE("oh man, this guy STINKS. id: %f", 1.0f);

    KASSERT(1 == 0);
    return 0;
}
