#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

RECOMP_IMPORT("*", void recomp_do_autosave(PlayState* play));

int moon_crashed = 0;
RECOMP_CALLBACK("*", recomp_after_play_update) void post_update(PlayState* play) {
    if (moon_crashed) {
        moon_crashed = 0;
        recomp_do_autosave(play);
    }
}

RECOMP_CALLBACK("*", recomp_after_moon_crash) void post_moon_crash(SramContext* sramCtx) {
    moon_crashed = 1;
}
