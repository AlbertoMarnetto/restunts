# SuperSight - a Restunts-based graphical improvement mod

by Alberto Marnetto

SuperSight is a mod which increases the field of view to a radius of up to 10
tiles around the car and drawing all objects in high resolution. For very
crowded scenes, it automatically reduces the detail to avoid running out of
memory. Additionally it adds a couple of functions:

* F5 turns on/off the display of the 3D engine status
* F6 turns on/off the visibility of illusion tiles

SuperSight is prodigal in term of CPU cycles, re-rendering a scene multiple
times as workaround to some quirks of the rendering engine. However, the
original game had very modest needs and, even after these changes, the game
has been reported to work well on a 386SX 40 MHz or a slightly tuned DOSBox 
set at 25000 cycles.

SuperSight is mostly based on the “orig” disassembly of Stunts, taking from the
Restunts rewrite only a minimum amount of code to ensure maximal compatibility
with the original game. Therefore, its assembly sources (`src\restunts\asm`)
have a very small diff with respect to `asmorig`, and the C sources
(`src\restunts\c`) are reduced to just one file.

In addition, SuperSight adds a script used to generate the tile array:
`src/gen-tiles`. This is not used by the build process, it's meant to be run
manually in case someone wants to alter the tile set.
