# Scientific-Paper-AI
Scientific Paper of COMPARATIVE STUDY OF A*, CSP, AND BAYESIAN NETWORKS IN CLASSIC PUZZLES
# Comparative Study of **A\***, CSP, and Bayesian Networks in Classic Puzzles  
This repository contains the full artefacts for the scientific paper  
**“Comparative Study of A\*, Constraint-Satisfaction, and Bayesian Networks in Classic Puzzles”**  
(written as a second-year AI course assignment).

---

## ✨ What you’ll find

| Path                       | Contents                                                                            |
|----------------------------|-------------------------------------------------------------------------------------|
| `paper/`                   | **LaTeX source** (`main.tex`) &nbsp;•&nbsp; pre-compiled **PDF** (`paper.pdf`)       |
| `code/a_star_8_puzzle/`    | Minimal, _optimal_ 8-puzzle solver (C++17, A\* with Manhattan heuristic)            |
| `code/sudoku_csp/`         | Backtracking + constraint-propagation Sudoku solver (C++17)                         |
| `code/bayes_cups/`         | **Fully runnable** “coin-under-two-cups” Bayesian-network demo (C++17, no external libs) |
| `figures/`                 | PNG/SVG diagrams used in the paper (search trees, CSP grids, BN graphs)             |
| `data/`                    | Sample puzzles & timelog CSVs used for the lightweight experimental section         |

---

## 🔧 Requirements

| Tool / Library | Version tested | Notes                             |
|----------------|---------------|-----------------------------------|
| **g++ / clang++** | ≥ C++17      | build the three demo programs      |
| **LaTeX** (TeX Live) | 2023       | compile the paper from source      |
| *(optional)* `make` | —           | convenient Makefiles are included  |

No external Bayesian-network library is required: the BN demo enumerates the four possible worlds directly.

---

## 🚀 Quick start

```bash
# 1. clone the repo
git clone https://github.com/<your-user>/classic-puzzle-ai-study.git
cd classic-puzzle-ai-study

# 2. build & run the 8-puzzle A* demo
cd code/a_star_8_puzzle
g++ -std=c++17 a_star_8puzzle.cpp -o eight
./eight        # should print "Solution found with cost = 31 moves."

# 3. build & run the Sudoku CSP demo
cd ../sudoku_csp
g++ -std=c++17 sudoku_csp.cpp -o sudoku
./sudoku       # prints solved grid

# 4. build & run the Bayesian “cups” demo
cd ../bayes_cups
g++ -std=c++17 bayes_cups.cpp -o cups
./cups         # prints P(Cup1)=0, P(Cup2)=1

# 5. view the PDF
xdg-open ../paper/paper.pdf   # or open it manually
