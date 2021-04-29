# This Is My CEG-4110 Spring 2020 Project
**by Dexter Wurn, Nate Schrider, Stephen Moore, Zach Bechoefer, Nathan Dunkman, and Brody Engle-Burdette**

## Modified-Craft

Minecraft clone for Windows, Mac OS X and Linux. Just a few thousand lines of C using modern OpenGL (shaders). Online multiplayer support is included using a Python-based server.

Our project used [Fogleman Craft](http://www.michaelfogleman.com/craft/) as our starting point

![Screenshot](https://i.imgur.com/iGJI8Jn.png)

### Tasks
The Breakdown of Tasks to Pull-Requests is in the [Tasks](./Tasks.md)

### Features

* Simple but nice looking terrain generation using perlin / simplex noise.
* More than 10 types of blocks and more can be added easily.
* Supports plants (grass, flowers, trees, etc.) and transparency (glass).
* Simple clouds in the sky (they don't move).
* Day / night cycles and a textured sky dome.
* World changes persisted in a sqlite3 database.
* Multiplayer support!
* Controller input
* Linux sound libraries
* In game clock
* Help Menu

![Screenshot](https://i.imgur.com/6pm0Ael.png)

### Install Dependencies

#### Mac OS X

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
if you don't already have it. You may use [Homebrew](http://brew.sh) to simplify
the installation:

    brew install cmake

#### Linux (Ubuntu)

    sudo apt-get install cmake libglew-dev xorg-dev libcurl4-openssl-dev
    sudo apt-get build-dep glfw
    sudo apt-get install libalut-dev
    sudo apt install libopenal-dev
    sudo apt install sox

#### Windows

Download and install [CMake](http://www.cmake.org/cmake/resources/software.html)
and [MinGW](http://www.mingw.org/). Add `C:\MinGW\bin` to your `PATH`.

Download and install [cURL](http://curl.haxx.se/download.html) so that
CURL/lib and CURL/include are in your Program Files directory.

Use the following commands in place of the ones described in the next section.

    cmake -G "MinGW Makefiles"
    mingw32-make

### Compile and Run

Once you have the dependencies (see above), run the following commands in your
terminal.

    git clone https://github.com/towny802/Craft.git
    cd Craft
    mkdir build
    cd build
    cmake ..
    make
    cd ..
    ./build/craft

### Controls

- WASD to move forward, left, backward, right.
- Space to jump.
- Left Click to destroy a block.
- Right Click or Cmd + Left Click to create a block.
- Ctrl + Right Click to toggle a block as a light source.
- 1-9 to select the block type to create.
- E to cycle through the block types.
- Tab to toggle between walking and flying.
- ZXCVBN to move in exact directions along the XYZ axes.
- Q to zoom.
- F to show the scene in orthographic mode.
- O to observe players in the main view.
- P to observe players in the picture-in-picture view.
- T to type text into chat.
- Forward slash (/) to enter a command.
- Backquote (`) to write text on any block (signs).
- Arrow keys emulate mouse movement.
- Enter emulates mouse click.
- ESC closes game down.
- F3 opens in game clock.

### Controller Controls (Xbox-One Controller)
- Left Stick moves character.
- Right Stick moves camera.
- Left Trigger places blocks.
- Right Trigger destroys blocks.
- A Jumps.
- Y toggeles fly mode.
- Right Stick pushed like a button zooms.
- Right Bumper goes to next block.
- Left Bumper goes to previous block.
- Select Button goes to Orthographic mode.
- Pause Button closes game down.

### Chat Commands

    /goto [NAME]

Teleport to another user.
If NAME is unspecified, a random user is chosen.

    /list

Display a list of connected users.

    /login NAME

Switch to another registered username.
The login server will be re-contacted. The username is case-sensitive.

    /logout

Unauthenticate and become a guest user.
Automatic logins will not occur again until the /login command is re-issued.

    /offline [FILE]

Switch to offline mode.
FILE specifies the save file to use and defaults to "craft".

    /online HOST [PORT]

Connect to the specified server.

    /pq P Q

Teleport to the specified chunk.

    /spawn

Teleport back to the spawn point.

    /block [Block #]

Selects specified block to place from array of all blocks

### Screenshot

![Screenshot](http://i.imgur.com/foYz3aN.png)

#### Dependencies

* GLEW is used for managing OpenGL extensions across platforms.
* GLFW is used for cross-platform window management.
* CURL is used for HTTPS / SSL POST for the authentication process.
* lodepng is used for loading PNG textures.
* sqlite3 is used for saving the blocks added / removed by the user.
* tinycthread is used for cross-platform threading.
* OpenAL is used for the sound library.


##### Side notes
- Zach Bechhoefer attempted to make pull requests, which were accidentally accepted automatically, these changes were still reviewed and accepted by the team.
