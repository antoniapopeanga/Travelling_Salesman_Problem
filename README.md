# 🧭 Travelling Salesman Problem (TSP) Solver

This repository contains comprehensive implementations of the Travelling Salesman Problem (TSP) with both exact algorithms and heuristic approaches, featuring interactive visualizations using **SDL/OpenGL**.

---

## 🔍 Problem Description

The TSP seeks the shortest possible route that:

- Visits each city exactly once  
- Returns to the origin city  
- Is NP-Hard with O(n!) complexity for exact solutions  

---

## ✨ Key Features

- **Multi-algorithm implementation**: Exact and heuristic methods  
- **Interactive visualization**: Real-time rendering with SDL/OpenGL  
- **Dynamic point generation**:

```c
point *generatePoints(int n);          // Random points  
point *generateCircles(int n, int k);  // Points on concentric circles  
point *generateConvex(int n);          // Convex hull points  
point *generatePower(int n, double p); // Power-law distributed points  
```

- **Advanced UI controls**:
  - Zoom/pan with mouse  
  - Keyboard controls for algorithm selection  
  - Real-time parameter adjustment  

---

## 🛠 Algorithms Implemented

#### 🔹 Brute Force
- Checks all n! permutations  
- Optimized with early termination  
```c
double tsp_brute_force(point *V, int n, int *P);
```

#### 🔹 Dynamic Programming (Held-Karp)
- `O(n²·2ⁿ)` time complexity  
- Uses memoization for efficiency  

---

### ⚙️ Heuristics

#### 🔹 Flip Optimization
- Iteratively improves solutions by path segment reversal  
```c
void reverse(int *T, int p, int q);
double first_flip(point *V, int n, int *P);
```

#### 🔹 Greedy Algorithm
- Always visits nearest unvisited city  
```c
double tsp_greedy(point *V, int n, int *P);
```

#### 🔹 Minimum Spanning Tree (MST)
- Uses Prim's/Kruskal's algorithm  
- 2-approximation guarantee  

---

## 🎨 Visualization System

### Core Components
```c
void init_SDL_OpenGL();                     // Initialize graphics  
void drawTour(point *V, int n, int *P);     // Render tour  
void drawGraph(point *V, int n, int *P, graph G); // Render graph  
```

### Interactive Controls

| Key       | Function                |
|-----------|-------------------------|
| `h`       | Show help               |
| `q`       | Quit                    |
| `p`       | Pause                   |
| `s`       | Adjust point size       |
| `o`       | Toggle path orientation |
| `r`       | Show root node          |
| `+/-`     | Adjust simulation speed |

### Rendering Pipeline
- OpenGL-based rendering with anti-aliasing  
- Dynamic viewport management  
- Efficient redraw scheduling:  
```c
static unsigned int call_speed = 1 << 7; // Drawing frequency
```

---

## 🚀 Build & Usage

### Prerequisites
- C compiler (GCC/Clang)  
- SDL2 and OpenGL libraries  

### Compilation
```bash
make clean && make
```

### Execution
```bash
./tsp [num_points]  # Default: 10 points
```

### Keyboard Controls During Execution
- `Space`: Pause/resume  
- Arrow keys: Navigate  
- Mouse: Drag points / Zoom  

---

### Complexity Analysis

| Algorithm     | Time       | Space     |
|---------------|------------|-----------|
| Brute Force   | O(n!)      | O(n)      |
| DP            | O(n²·2ⁿ)   | O(n·2ⁿ)   |
| Greedy        | O(n²)      | O(n)      |
