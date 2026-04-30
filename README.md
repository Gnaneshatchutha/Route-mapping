# dijkstra-shortest-path-c

> A lightweight, efficient implementation of Dijkstra's shortest path algorithm in C using adjacency lists and a greedy min-node selection strategy.

---

## Overview

This project implements **Dijkstra's Single-Source Shortest Path** algorithm in C. It finds the minimum-cost path between any two nodes in a weighted, undirected graph and supports multiple queries on the same graph in a single run.

---

## Features

- Adjacency list representation using linked lists (memory efficient)
- Handles multiple source-destination queries per graph
- Outputs both the minimum distance and the full path
- Reports `NO_PATH` when no route exists between nodes
- Uses `long long` distances to avoid integer overflow on large weights

---

## Algorithm

The implementation uses the classic **O(V²)** Dijkstra approach:

1. Initialize all distances to infinity, source distance to `0`
2. Greedily pick the unvisited node with the smallest known distance
3. Relax all neighboring edges
4. Repeat until all nodes are visited or no reachable nodes remain
5. Reconstruct the path using a `parent[]` array

---

## Input Format

```
N M
u1 v1 w1
u2 v2 w2
...
s t
s t
-1 -1
```

| Field | Description |
|-------|-------------|
| `N`   | Number of nodes (0-indexed) |
| `M`   | Number of edges |
| `u v w` | Edge between node `u` and `v` with weight `w` (undirected) |
| `s t` | Source and destination for a shortest path query |
| `-1 -1` | Sentinel to end queries |

---

## Output Format

For each query:

```
DISTANCE <d>
PATH <n0> <n1> ... <nk>
```

Or, if no path exists:

```
NO_PATH
```

---

## Example

**Input:**
```
5 6
0 1 10
0 2 3
1 2 1
1 3 2
2 3 8
3 4 7
0 4
0 3
-1 -1
```

**Output:**
```
DISTANCE 19
PATH 0 2 1 3 4
DISTANCE 11
PATH 0 2 1 3
```

---

## Building & Running

```bash
# Compile
gcc -O2 -o dijkstra dijkstra.c

# Run with input file
./dijkstra < input.txt

# Or enter interactively
./dijkstra
```

---

## Project Structure

```
dijkstra-shortest-path-c/
├── dijkstra.c      # Main source file
└── README.md       # This file
```

---

## Complexity

| Metric | Value |
|--------|-------|
| Time   | O(V²) per query |
| Space  | O(V + E) for the graph |

> For large sparse graphs, consider upgrading `getMinNode` to a binary min-heap for O((V + E) log V) performance.

---

## License

MIT License — free to use, modify, and distribute.
