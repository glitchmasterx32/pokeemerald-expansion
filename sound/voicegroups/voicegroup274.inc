	.align 2
voicegroup274:: @ 
    voice_keysplit_all voicegroup191
    voice_keysplit voicegroup191, KeySplitTable1

    // Strings (Pizzicato Strings for tension, and long notes for dramatic impact)
    voice_directsound 60, 0, DirectSoundWaveData_sc88pro_pizzicato_strings, 255, 216, 0, 165
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Bass for foundation (fingered bass) for low-end support
    voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 253, 0, 149
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Timpani for rhythmic depth
    voice_directsound 60, 0, DirectSoundWaveData_sc88pro_timpani, 255, 246, 0, 226
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Voice group split for complex arrangements
    voice_keysplit voicegroup196, KeySplitTable2
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
    voice_keysplit voicegroup197, KeySplitTable3
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Creating sweeping string effects (orchestral synth sound)
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Flute (adding melodic top layers, giving a lighter texture)
    voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 0, 255, 165
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0

    // Adding a high-pitched synth (for dramatic, higher melodic layers)
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
    voice_square_2 60, 0, 2, 0, 1, 7, 1

    // Layered programmable wave (futuristic or dramatic sound for high intensity)
    voice_programmable_wave_alt 60, 0, ProgrammableWaveData_7, 0, 7, 15, 2
    voice_square_1 60, 0, 0, 2, 0, 1, 7, 1

    // High energy square waves for building up intensity and tension
    voice_square_2 60, 0, 0, 0, 1, 7, 1
    voice_square_1 60, 0, 0, 0, 0, 1, 7, 1

    // Transitioning to a dramatic, sweeping orchestral sound
    voice_square_1 60, 0, 0, 0, 0, 0, 7, 1
    voice_square_1 60, 0, 0, 0, 0, 0, 7, 1

    // Final section for dramatic impact, layering and reinforcement
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
    voice_square_1 60, 0, 0, 2, 0, 0, 15, 0