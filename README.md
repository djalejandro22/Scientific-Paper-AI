# Comparative Study of A\*, CSP, and Bayesian Networks in Classic Puzzles  
Supplementary Code Repository
--------------------------------------------------------------------------------

This repo accompanies the scientific paper  
**“Comparative Study of A\*, CSP, and Bayesian Networks in Classic Puzzles”**.  
It contains minimal, self-contained C++ examples that reproduce the **toy
experiments** discussed in the manuscript.

| Folder / File | Technique | Puzzle | What it Demonstrates |
|---------------|-----------|--------|----------------------|
| `astar_8puzzle.cpp` | A\* search | 8-Puzzle (3 × 3 sliding-tile) | Heuristic search with Manhattan distance; prints optimal 31-move solution for a hardest-case start state. |
| `sudoku_csp.cpp` | Constraint Satisfaction (backtracking + forward-checking) | 9 × 9 Sudoku | Solves an example puzzle in milliseconds; illustrates constraint propagation and backtracking. |
| `cups_bayes.cpp` | Bayesian Network (exact enumeration) | “Coin-under-two-cups” toy BN | Builds a tiny BN with exclusivity constraint and computes posteriors \(P(\text{Cup}=\text{True}\,|\,\text{Clue})\). |

> **Note**  
> The Bayesian network example is intentionally **micro-scale**.  Exact
> enumeration works for two hidden variables but scales exponentially; see
> Section V of the paper for discussion.  Larger uncertain puzzles (e.g.,
> Minesweeper) would require approximate inference or specialised BN
> libraries.

---

## Build & Run

All three files are standard C++17 and have **no external dependencies**
besides a recent compiler.

```bash
# Linux / macOS
g++ -std=c++17 -O2 astar_8puzzle.cpp   -o astar
g++ -std=c++17 -O2 sudoku_csp.cpp      -o sudoku
g++ -std=c++17 -O2 cups_bayes.cpp      -o cups

./astar    # prints solution length and timing
./sudoku   # prints solved grid
./cups     # prints posterior probabilities
