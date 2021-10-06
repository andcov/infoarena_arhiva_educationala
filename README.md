# arhiva educationala infoarena

Solutions to some of the problems from [arhiva educationala infoarena](https://infoarena.ro/arhiva-educationala).

Problems included:
 - [x] [000 - Algoritmul lui Euclid](https://infoarena.ro/problema/euclid2)
 - [x] [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc)
 - [x] [005 - Potrivirea sirurilor](https://infoarena.ro/problema/strmatch)
 - [ ] [008 - Subsir crescator maximal](https://infoarena.ro/problema/scmax)
 - [x] [009 - Algoritmul lui Dijkstra](https://infoarena.ro/problema/dijkstra)
 - [x] [010 - Ciurul lui Eratosthenes](https://infoarena.ro/problema/ciur)
 - [x] [011 - Generare de permutari](https://infoarena.ro/problema/permutari)
 - [x] [012 - Ridicare la putere in timp logaritmic](https://infoarena.ro/problema/lgput)
 - [x] [013 - BFS - Parcurgere in latime](https://infoarena.ro/problema/bfs)
 - [x] [014 - Parcurgere DFS - componente conexe](https://infoarena.ro/problema/dfs)
 - [ ] [016 - Range minimum query](https://infoarena.ro/problema/rmq)
 - [x] [017 - Combinari](https://infoarena.ro/problema/combinari)
 - [x] [022 - Paduri de multimi disjuncte](https://infoarena.ro/problema/disjoint)
 - [x] [025 - Heapuri](https://infoarena.ro/problema/heapuri)
 - [x] [026 - Arbore partial de cost minim](https://infoarena.ro/problema/apm)
 - [ ] [058 - Diametrul unui arbore](https://infoarena.ro/problema/darb)

## Prerequisites
You must have a C++ compiler and CMake installed. If you do not, you will not be able to run the project, but you may still see the solutions (e.g. look at `001_cmlsc.h` for the solution for [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc)). 

## Installation & Usage
 * Clone this repo: `git clone https://github.com/andcov/infoarena_arhiva_educationala.git && cd infoarena_arhiva_educationala`
 * Initialise CMake: `cmake ./`
 * In `main.cpp`, set the header according to the problem you want to solve. (e.g. `#include "001_cmlsc.h"` if you want to run the solution for [001 - Cel mai lung subsir comun](https://infoarena.ro/problema/cmlsc))
 * Build the project: `cmake --build ./`
 * Set `input.in` to your desired input
 * Run the program: `./infoarena_arhiva_educationala`
 * Print the result: `cat output.out`
