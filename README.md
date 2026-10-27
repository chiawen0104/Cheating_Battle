# Introduction
We are a team consists of one student from NTU ECON and two students from NTU MATH. This is our final project of Computer Programming, NTUEE, 2021 fall.
The game "Cheatiing Battle" was coded by C++ with SDL package. 

The executable files are in `./Release` and source codes are in `./Source`.  
If you want to learn more about this game, you can watch this demo video: https://youtu.be/Yt1_8lWRjXs.


# Usage

## Windows
Please click `作弊抓耙仔(Cheating Battle).exe` in `./Release` (for Windows user ONLY!), then enter full screen to play the game.

## macOS
### Download and play
Download `CheatingBattle-mac.zip` from `./Release`, unzip it, then double-click `CheatingBattle.app`. 


### Compile & Run
If you want to build the game yourself, install the [SDL2](https://www.libsdl.org/) libraries first. We use [Homebrew](https://brew.sh/):
```bash
brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer pkg-config
```

Then compile and run from the `Source` folder:
```bash
cd Source
make run
```


# Notes

Rules of the game:
![image](https://github.com/chiawen0104/Cheating_Battle/blob/main/Source/Picture/rule.png)

Tips: 
1. Notice the teacher's action carefully.
2. Press down the button consecutively to get higher scores.
3. Raise hands to trap the opponent at the right time.
