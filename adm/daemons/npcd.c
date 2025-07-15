// npcd.c

#pragma optimize

#include <command.h>
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/girl.c>
#include <npc/masia.c>
#include <npc/indian.c>

string get_random_bodytype()
{
    int r = random(100);
    if (r < 7) return "slim";    // 7%
    if (r < 31) return "light";  // 24%
    if (r < 69) return "normal"; // 38%
    if (r < 93) return "heavy";  // 24%
    return "fat";                // 7%
}
