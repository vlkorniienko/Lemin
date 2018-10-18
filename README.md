# Lemin
      
      Algorithmic project
      
### The goal of this project is to find the quickest way to get n ants across the farm.

* Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.

* At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)

* At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

* You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links

Lx-y Lz-w Lr-o ...
```
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y, w, o represents the rooms’ names.

#### Map example
![](https://github.com/vlkorniienko/Lemin/blob/master/map_example.png)

### Usage
```
git clone https://github.com/vlkorniienko/Lemin
cd Lemin
make
./lem-in < maps/map01
```
Also as a bonus to this project I decided to find all unique ways on the map and let the ants walk on all of them.

#### Example of programm output

![](https://github.com/vlkorniienko/Lemin/blob/master/screen.png)
