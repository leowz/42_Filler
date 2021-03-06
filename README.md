# Filler - @42Born2Code
![license](https://img.shields.io/github/license/mashape/apistatus.svg)
![UnitTest](https://img.shields.io/badge/42UnitTest-pass-blue.svg)
![42pass](https://img.shields.io/badge/42-pass-brightgreen.svg)

Filler is a project of branch algorithm @42Born2Code. It is also a game of fun to watch and to play with your friend and yourself.
This is my implementation of a player in this game. My player uses a greedy algorithm with the help of the tool called heat map.
The performance of my player is pretty impressive though. With very short amount of code, I won a majority number of games with opponent programs I encountered.

### Contents
* [What is Filler?](#what-is-filler)
* [What's in Filler?](#whats-in-filler)
* [Example usage](#example-usage)
* [Grades](#grades)

### What is filler?
Filler is a game. In this game, two players fight against each other, one after the other on a board defined by X * N cells.

Each player will receive a game piece to place on the board with exactly one cell of overlapping with its previous territory(meanning the region already placed your pieces on the board).
The shape of players' territory must not exceed the area of the board. opponent pieces can not overlap.

If one player cannot place any piece on the board, then he stops there while the other player can keep on placing pieces on the board.

The player who have placed the more pieces on the board wins.

Read filler.en.pdf to learn more details about the game.

### What's in filler?

There are the project files for the player and a resource directory.

In the resource directory we have the VM 'filler-vm' to host the game.
And also there are some other players and some maps for the game situated in the corresponding sub-directory in resource.

#### Algorithm
The algorithm used in my player is just a simply greedy algorithm. In every turn of the game, I try to place the piece as close as possible to my opponent territory. In that way, I'am actually trying to enclose my opponent. And as long as my player can enclose my quickly, my player will definetely win.

The difficulte of this stratety is how to discribe the distance of each cell in the board to the opponent. And a heatmap is here to help.

![heatmap](/res/heatmap.png)  

By giving each cell a value of heat to the opponent territory, can we discribe the distance of each cell. The closer to the opponent the more hot is the cell and vice versa.
This heatmap makes the player easier to find the cell closest to the opponent territory to place the piece.

### Example usage

From the first gif, we can see that my player(blue) is trying to enclose the opponents as fast as possible.
![gif0](/res/fgif0.gif)

From the second, we can see that once the opponent is enclosed the game is over.
![gif1](/res/fgif1.gif)  

### Grades
Filler: 100/100
