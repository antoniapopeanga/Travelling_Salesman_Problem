# Travelling Salesman Problem (TSP) Solver

This repository contains implementations of various algorithms to solve the **Travelling Salesman Problem (TSP)**, a classic optimization problem in computer science and operations research. The goal is to find the shortest possible route that visits each city exactly once and returns to the origin city.

## 🔍 Problem Description
The **Travelling Salesman Problem (TSP)** is defined as follows:
- Given a list of cities and the distances between each pair of cities, find the shortest possible route that visits each city exactly once and returns to the origin city.
- TSP is an **NP-Hard** problem, meaning that exact solutions become computationally infeasible as the number of cities increases.

## 🛠 Algorithms Implemented
This repository includes the following approaches to solve TSP:
1. **Brute Force (Exact Solution)** – Checks all possible permutations (only feasible for small instances).
2. **Dynamic Programming (Held-Karp Algorithm)** – More efficient than brute force but still limited by memory.
3. **Nearest Neighbor (Greedy Heuristic)** – A fast approximation that may not always yield the optimal solution.
