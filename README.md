# ZorkRoger
The game is inspired on the game Zork.

Authors: Roger Nogué Ballbé.

github repo: https://github.com/RogerNogue/ZorkRoger


Decisions taken:

- Instead of implementing the parser right into the class World I decided to have a static class
called "Parser" to work on it. It's true that having this procedure forces me to add extra stuff
but since almost everything happens in the class World, it looses some weight. Another reason of
this decision is to avoid copying the structure given in the example.

- As for the extra feature I thought of having usable items such as torches that allow the
player to see objects in the dark.

- At some point i realised that in I would have put the classes Exit and Room together since it
makes some sense to have a path to another room as an element of the room. I have not done it to
maintain the initial structure.

- the final item can be grabbed even if you don't see it. Like IRL, if you know something is there,
it can be grabbed even if you don't see it.

Guide of how to play the game:

Commands:						Effects

look							looks around
look x							looks into the item x, if it contains one or more items, grabs one
inventory						shows items in the player's possesion
go (north, south, east, west)	tries to go in the direction
grab x							tries to grab the item x
drop x							tries to drop x
use x							tries to use x
talk x							tries to talk to x
put x y 						tries to put x into y


Guide of how to beat the game:

The player starts in front of the graveyard doors, which are closed. Looking around (command: look)
a suspicious stone can be seen, if you look into it (command: look stone) you find and automatically
grab a key, which allows you to go through the door (command: go north).

Once in the graveyard entrance you can fina a vigilante (command: look) who you can talk to 
(command: talk vigilante). The vigilante will be pleased that you talked to him, so he will 
automatically give you a torch. You can proceed by going north (command: go north).

In the center of the graveyard there is nothing at all (look), so by going east(command: go east)
you proceed.

In the sanctum entrance there are some cool things like a box that contains a paper, or where you can
put things (command: put x box), but that's not relevant to beat the game, you can get inside
the sanctum (command: go east)

Once inside the sanctum you can look around (look) and see a tomb. Looking at the tomb 
(command: look tomb) you will see nothing at all. And that's what karma is for! If you use the
torch the vigilante gave you (command: use torch) and you look into the tomb (command: look tomb)
you'll find something that may be helpful!


List of all items and its names:
stone: 	item that contains other items and can not be grabbed
stick: 	useless item that can be grabbed and dropped and put inside other container items
torch: 	item that can be used, grabbed, dropped and put inside containers
box: 	container item that can not be grabbed
paper: 	item that can be grabbed, dropped and put inside containers
tomb: 	container item that can not be grabbed
cupon: 	hard to see item that can only be seen with enough light. It can be grabbed even if you
		don't see it if you know where it is though.
