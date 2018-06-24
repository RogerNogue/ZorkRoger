# ZorkRoger
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