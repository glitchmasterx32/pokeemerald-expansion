// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [GRADING_SYSTEM] =
    {
        .header = COMPOUND_STRING("Grading Criteria"),
        .desc = COMPOUND_STRING("1. {COLOR RED}{SHADOW LIGHT_GRAY}Viva Questions- 40%. {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}(Oral examination)\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}2. {COLOR RED}{SHADOW LIGHT_GRAY}Practical Battles- 40%. {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}(Dojo tests,\ntournaments)\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}3. {COLOR RED}{SHADOW LIGHT_GRAY}Class Participation- 20%. {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}(Attendance,\n assignments, discussions)"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL
    },
    [HELP_MEGA_EVOLUTION] =
    {
        .header = COMPOUND_STRING("Information: Mega Evolution"),
        .desc = COMPOUND_STRING("In battle, press {START_BUTTON} to Mega Evolve!\n\n"
                                "The Pokémon must hold their Mega Stone\n"
                                "to be able to Mega Evolve.\n"
                                "You can only Mega Evolve once per battle."
                            ),
    },
    [BATTLE_THEORY_CLASS_1] =
    {
        .header = COMPOUND_STRING("VIVA"),
        .desc = COMPOUND_STRING("SCENARIO:\n"
                                "Your Pokémon is paralyzed. Speed reduced.\n"
                                "The opponent, slower, now moves first.\n"
                                "{COLOR RED}{SHADOW LIGHT_GRAY}OPTIONS:\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}A) {COLOR RED}{SHADOW LIGHT_GRAY}Switch out immediately\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}B) {COLOR RED}{SHADOW LIGHT_GRAY}Use a Full Heal\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}C) {COLOR RED}{SHADOW LIGHT_GRAY}Attack anyway\n"
                                "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}D) {COLOR RED}{SHADOW LIGHT_GRAY}Set up stat boosts"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL
    },
    [ACADEMY_TIMETABLE_MONDAY] =
    {
        .header = COMPOUND_STRING("TODAY'S TIMETABLE"),
        .desc = COMPOUND_STRING("9am-11am:  Arts\n"
                                "11am-1pm:  Break\n"
                                "1pm-4pm:  Battle Theory."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL
    },
    // Add more entries
};