#ifndef GUARD_UI_SCREENSHOTS
#define GUARD_UI_SCREENSHOTS

#include "main.h"

void Task_OpenScreenshots(u8 taskId);
void Screenshots_Init(MainCallback callback);
void Screenshots_StartMenuInitCB(void);


enum Screenshots
{
    SCREENSHOT_HOOPA_WAR,
    SCREENSHOT_VEYLOR_BOWING,
    SCREENSHOT_HOOPA_TORMENT,
    SCREENSHOT_AURTHER_DEATH,
    SCREENSHOT_MIRA_DEATH,
    SCREENSHOT_ELYSIA_DEATH,
};


#endif // GUARD_UI_MENU_H
