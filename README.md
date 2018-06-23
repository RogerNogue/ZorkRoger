# ZorkRoger
Decisions taken:

- Instead of implementing the parser right into the class World I decided to have a static class
called "Parser" to work on it. It's true that having this procedure forces me to add extra stuff
but since almost everything happens in the class World, it looses some weight. Another reason of
this decision is to avoid copying the structure given in the example.

- As for the extra feature I thought of having usable items such as torches that allow the
player to see objects in the dark.