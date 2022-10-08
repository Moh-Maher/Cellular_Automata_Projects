# Cellular Automaton Projects

This is a collection of c++ implementations for for the basics of Wolfram's elementary 1D cellular automaton, and Conway's game of life.

## Wolfram's Elementary 1D Cellular Automaton
 
    A grid of numbers describe the cell states of a given generation, ultimately considered as the “current” generation, 
    and the mechanism by which we compute the next generation.  
    For every cell in the grid:

   - Take a look at the neighborhood states: left, middle, right.

   - Look up the new value for the cell state according to some ruleset.

   - Set the cell’s state to that new value.

# Example: 

![Alt text](https://github.com/Moh-Maher/Cellular_Automata_Projects/tree/main/snaps/rule90.png?raw=true "rule 90")

![Alt text](https://github.com/Moh-Maher/Cellular_Automata_Projects/tree/main/snaps/rule126.png?raw=true "rule 126")

![Alt text](https://github.com/Moh-Maher/Cellular_Automata_Projects/tree/main/snaps/rule150.png?raw=true "rule 150")

![Alt text](https://github.com/Moh-Maher/Cellular_Automata_Projects/tree/main/snaps/rule182.png?raw=true "rule 182")

## Game of Life

    The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, 
    each of which is in one of two possible states, alive (1) or dead (0). 
    Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or 
    diagonally adjacent. At each step in time, the following transitions occur:

- Death. If a cell is alive (state = 1) it will die (state becomes 0) under the following circumstances.

   - Overpopulation: If the cell has four or more alive neighbors, it dies.

   - Loneliness: If the cell has one or fewer alive neighbors, it dies.

- Birth. If a cell is dead (state = 0) it will come to life (state becomes 1) if it has exactly three alive neighbors (no more, no less).

- Stasis. In all other cases, the cell state does not change. To be thorough, let’s describe those scenarios.

   - Staying Alive: If a cell is alive and has exactly two or three live neighbors, it stays alive.

   - Staying Dead: If a cell is dead and has anything other than three live neighbors, it stays dead
## Refrences 
- Weisstein, Eric W. "Elementary Cellular Automaton." From MathWorld--A Wolfram Web Resource: https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
- Daniel Shiffman "The Nature of Code" https://natureofcode.com/book/chapter-7-cellular-automata/ 
