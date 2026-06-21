This is the README for Jamie's Transformation Pack feature branch, please refer to another branch for the pokeemerald-expansion README

# Videos

## Instant Morph
https://github.com/user-attachments/assets/7ae1551f-83fc-4881-9c66-eff1aeadbcdf
```
OldaleTown_EventScript_Gir::
	instantmorph LOCALID_PLAYER, OBJ_EVENT_GFX_GIRL_3
	end

OldaleTown_EventScript_MartEmployee::
	instantmorph LOCALID_PLAYER
	end
```
## Spin Morph
https://github.com/user-attachments/assets/37eb32d3-9bb1-485c-abea-2c224ea99e1f
```
OldaleTown_EventScript_Zoroark::
	setvar_randompartymon_gfx VAR_0x8005
	spinmorph 1, VAR_0x8005
	end
```

## Mosaic Morph
https://github.com/user-attachments/assets/06e45666-b5c8-442c-b3df-70ff4c317c72
```
OldaleTown_EventScript_Ditto::
	chooseboxmon SELECT_PC_MON_DAYCARE @ I call chooseboxmon with SELECT_PC_MON_DAYCARE insetad of no argument because it forbids picking an egg
	waitstate
	setvar_choosemon_gfx VAR_0x8005
	mosaicmorph 1, VAR_0x8005
	end
```

## Bird Transform (BETA)
https://github.com/user-attachments/assets/435edc97-62d7-4284-9266-5eca6c3e9556
```
OldaleTown_EventScript_Girl::
	setvar_moncanlearnmove_gfx VAR_0x8005, MOVE_FLY
	jumponleftbird VAR_0x8005
	applymovement LOCALID_PLAYER, MovementStuff
	waitmovement
	jumpoffbird
	end

MovementStuff::
	walk_up
	walk_down
	step_end
```

# Usage

## Transformations

A transformation needs 3 arguments: the object you want to transform, the graphics you want to change the object into and the type of effects you want to accompany the trasnformation (referred to as "morph/morphing" in the code to avoid search conflicts with the battle move Transform).
This is why the main transformation command  has the following arguments.
`.macro morphobject localId:req, type:req, graphicsId=NUM_OBJ_EVENT_GFX, map`
- `localId` to represent the object you want to morph with an optional map argument at the end in case you want to refer to an object from a different map
- `type` indicates the transformation effect you want to be applied. These are defined as `enum MorphType` and the possbile values are `INSTANT_MORPH`, `SPIN_MORPH` and `MOSAIC_MORPH`
- `graphicsId` to represent the image you want to change the object into. Check the dedicated section to understand how graphicsId work. If the graphicsId argument is not present, the object will try to change into its "original" form. For Regular object events for example, it would be the graphicsId defined in their template.

In addition to `morphobject`, we have three wrappers functions that take one less argument and include the morph type
`instantmorph/spinmorph/mosaicmorph localId:req, graphicsId=NUM_OBJ_EVENT_GFX, map`
These wrappers also play a sound effect to accompany the transformation. We recommand watching the videos examples to see how the different effects look like

### Bird Transformations (BETA)

This feature branch also contains three additional script commands: `jumponrightbird`, `jumponleftbird` and `jumpoffbird`. These commands are not fully polished. They only works with a centered player character and should be used with caution. I included them because they are somewhat similar and might be interested to some people but they are provided as is and you have to fix them yourself if you have issues.

## Graphics ID

Graphics IDs are the main arguments for transformations. They are the `OBJ_EVENT_GFX_` values you can find in `include/constants/event_objects`.
You can also use `OBJ_EVENT_GFX_SPECIES(SPECIES_NAME)` to get the graphics id of an overworld pokemon. For example `OBJ_EVENT_GFX_SPECIES(MAWILE)`
Jamie's Transformation Pack includes new script commands that generate graphics id based on the pokemon in your party and stores them in variables.

Before going into details about each function, here are a few things they have in common:
- they take a var like `VAR_0x8005` as their first argument and store a graphics id in that var which can then be used as an argument in a transformation command
- if they have an invalid result in some way, they will store `OBJ_EVENT_MON` which is the graphics ID for `SPECIES_NONE` and looks like a substitute doll
- they store the graphics of a pokemon not just a species and as such take into account shinyness and gender dimorphism when relevant

### `setvar_moncanlearnmove_gfx` / `setvar_monknowsmove_gfx`

These functions take two arguments, the var you want the graphics id to be stored in and a move. The game will find the first pokemon in your party that has the move in its moveset for `setvar_monknowsmove_gfx` or has the move in its teachables list (TM/HM + tutor) for `setvar_moncanlearnmove_gfx`

### `setvar_choosemon_gfx`

This function takes one the var you want the graphics id to be stored in. The function is designed to work with the result of `special ChoosePartyMon`/`chooseboxmon` allowing you to let the player pick the mon that will we be used as a basis for graphics from the party or PC

### `setvar_randompartymon_gfx`

This function only takes one argument, the var you want the graphics id to be stored in and will return the graphics id of a random party member

# Questions and Bug Reports

If you have difficulties or encounter a bug, you can post in the #romhacking-help channel of the Team Aqua Hideout (TAH) discord server and ping @Jamie
# Pathfinder 1.1.2

## About

This is a complete reimplementation of [Juanjo's old path finder](https://www.pokecommunity.com/threads/applymovement-vs-a-algorithm-for-pathfinding.445293/) for [`pokeemerald-expansion`](https://github.com/rh-hideout/pokeemerald-expansion) `1.13.0+`.
This branch adds the `moveobjecttocoords` and `approachobject` scripting macros, for generating movement scripts at run time, achieved by using the Weighted A* Algorithm. This branch aims to give romhackers an easier way to create more complex movement scripts and reduce branching.

![demo1](https://github.com/user-attachments/assets/5285b7d1-2e55-4afa-95e2-09312e922544)
![demo2](https://github.com/user-attachments/assets/febabae1-9816-4cd8-96e4-ee33bd0ba198)
![demo3](https://github.com/user-attachments/assets/fcbd8e82-cb36-4905-9237-f1822bd8c7ce)
> Stairs tiles by Zeo254.

## Usage

### `moveobjecttocoords`
```gas
moveobjecttocoords localId:req, x:req, y:req, facingDirection:req, speed=1, maxnodes=256
```

- `facingDirection`, it controls the facing direction. If it is `DIR_NONE`, the facing direction will depend on the generated script.
- `speed`, it controls the movement speed and goes from 0 to 4. 0 is slow, 1 is normal, and so on.
- `maxnodes`, it controls how many nodes can be generated (aka, how many tiles can be checked).

### `approachobject`
```gas
approachobject localId:req, targetLocalId:req, facingDirection:req, approachDirection:req, speed=1, maxnodes=256
```
Same as `moveobjecttocoords`, but keep in mind that `approachDirection` does not support `DIR_NONE`.

### What happens if there is no path?

The system will display an X icon, if it's unable to find a valid path.

![fail](https://github.com/user-attachments/assets/c2d07d42-3308-4e81-9a7f-679c1d4aaa49)

> [!WARNING]
If there is no path, it will most likely lag the game.
Try to only use the macro when you are sure there is a valid path.

## Why Weighted A*?

This variant of the A* algorithm provides better performance for searching the first valid path. This done by giving more priority to nodes more close to the goal.

### A* vs Weighted A*

| A* Algorithm  | Weighted A* Algorithm  |
| ------------- | ---------------------- |
| ![a_star](https://github.com/user-attachments/assets/f3fa2ccc-4074-40da-b03d-d64ccfe83d9e) | ![weighted_a_star](https://github.com/user-attachments/assets/e127af4b-447a-45f2-9ec0-c5aab8965fd7) |

However Weighted A* can generate less natural-looking paths than regual A*, and it can be tricked more easly by mazes, but it provides better performance in most cases, since it requires less nodes to find a valid path.

## Changelog

### 1.1.2 - 2026-6-20
- Updated to `expansion` 1.16.1.

### 1.1.1 - 2026-4-14

### Changed
- Improve preformance by caching metatile behaviors.
- Fix potential UBs.
- Fix hash function `fmix32` implementation.

### 1.1.0 - 2026-1-20

#### Added
- Add `approachobject` macro.
- Add `SLOW_MOVEMENT_ON_STAIRS` support .
- Add `PATH_FINDER_PRINT_TIME`.

#### Changed
- Improve neighbor expansion, about a ~25% faster.

## Credits
- Juanjo, for the orginal path planner idea.
- Phantonomy, for the `approachobject` idea.

## Reference

### Tiles
- [https://www.deviantart.com/zeo254/art/Tileset-Pokemon-Resurgent-495764643](https://www.deviantart.com/zeo254/art/Tileset-Pokemon-Resurgent-495764643)

### Videos
- [https://upload.wikimedia.org/wikipedia/commons/5/5d/Astar_progress_animation.gif](https://upload.wikimedia.org/wikipedia/commons/5/5d/Astar_progress_animation.gif)
- [https://upload.wikimedia.org/wikipedia/commons/8/85/Weighted_A_star_with_eps_5.gif](https://upload.wikimedia.org/wikipedia/commons/8/85/Weighted_A_star_with_eps_5.gif)
