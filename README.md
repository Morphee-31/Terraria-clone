# A Terraria-like game by a newbie

A type of game a bit like Terraria developped in C++ with SMFL.

## Commands 
- Spacebar  // Jump
- Right Click  // place blocks
- Left Clicks  // breaks blocks
- hotkeys from 1 to 6 (Dirt, Sand, Lava, Water, Ladder, Stone)
- Z   // Forward
- Q   // Left
- S   // Backward
- D   // Right
- // Sorry for the controls, French Keyboard, but you can change it easily in utility.hpp

## Technologies utilisées
- C++20
- SFML 3

## Functionalities
- Procedural generation (Perlin Noise)
- Block system (break & place)
- Collisions
- Rendering Engine

## How to compile it
Open the folder '.sln' with Visual Studio and run the compilation process.
You have to link the project with SFML, I might try to automate the linking but not of my reach yet, and use at least C++17 (try 20 if it doesn't work)
In the future, I want my project to be running even if you don't have SFML, it is not my priority yet but maybe some day
using C-make or something else.

## ideas for the future
- a menu
- a hotbar like in Minecraft
- an inventory
- a day/night cycle

Feel free to tell me what can I add to my game, I'll try to implement it

## Project Structure
'''
📦 Terraria clone
├── 📂 Core
│   ├── main.cpp
│   ├── InitGame.cpp / .hpp
│   ├── Collisions.cpp / .hpp
│   └── Config.hpp
├── 📂 Player
│   ├── Player.cpp
│   └── Player.hpp
├── 📂 Procedural_Generation
│   ├── MapGen.cpp / .hpp
│   ├── PerlinNoise.cpp / .hpp
├── 📂 Rendering_Engine
│   ├── Rendering_Engine.cpp
│   └── Rendering_Engine.hpp
├── 📂 World
│   ├── Blocks.cpp / .hpp
│   └── TileName.hpp
└── 📂 Utility
    ├── Utility.cpp / .hpp
    └── Colors.hpp
'''

## Personnal comment
It is my first "big project" in C++, and my point is not really the Game itself, I only want to understand how games works under the hood.
Feel free to critisize it, it might help me, and also, my point is not using C++ features just because they exist I am trying to implement 
Thanks for your understanding
