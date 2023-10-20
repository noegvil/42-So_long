# 42-So_long
"So long" was my first graphic design project at 42 school. 
The primary objective of this project was to acquire the skills needed to utilize a graphics library and develop a 2D game using the C programming language. Through this project, I gained essential expertise in graphic creation and game programming, allowing me to explore fundamental concepts in interactive software development.

About the game:

In this project, I created a 2D game where the player's objective is to collect all objects on the map and exit by choosing the shortest route possible. The main features of the game include:

-  Movement controlled by the W, A, S, and D keys for the main character.
-  Four directions of movement: up, down, left, and right.
-  Collision detection to prevent the player from entering walls.
-  Real-time display of the number of movements in the terminal after each move.
-  Utilized a 2D top-down or side-scrolling perspective.
-  Non-real-time gameplay, allowing turn-based movement.
-  Thematic flexibility to create the desired game world.

Graphics Management:

The game features a graphical interface with the following functionalities:

-  Clean window management, including window switching and minimizing.
-  The ESC key closes the window and terminates the program gracefully.
-  Clicking the red cross on the window closes the window and ends the program cleanly.
-  The MLX42 library is used for graphics rendering.

Map:

The map is constructed with three main components: walls, collectibles, and open spaces. Key aspects of the map include:

-  A map composed of five characters: 0 for an empty space, 1 for a wall, C for a collectible, E for the exit, and P for the player's initial position.
-  The map must contain an exit, at least one collectible, and a player's initial position.
-  Rectangular map structure.
-  The map must be enclosed by walls; otherwise, the program returns an error.
-  Verification of a valid path on the map.
-  Compatibility with various map configurations, as long as the specified rules are followed.
-  Graceful handling of configuration errors with explicit error messages.
