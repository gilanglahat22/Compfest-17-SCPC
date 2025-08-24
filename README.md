# Compfest-17-SCPC Competitive Programming Solutions

This repository contains solutions to competitive programming problems from the Compfest-17-SCPC contest. Each problem is implemented in C++ with optimized algorithms and data structures.

## 📁 Project Structure

```
Compfest-17-SCPC/
├── proba.cpp          # Problem A - Game Winner Determination
├── probb.cpp          # Problem B - Binary Number Validation
├── probc.cpp          # Problem C - Train Scheduling with Fenwick Tree
├── probd.cpp          # Problem D - Array Partitioning (Binary Search)
├── probe.cpp          # Problem E - Matrix Exponentiation & State Transitions
├── probh.cpp          # Problem H - Fibonacci Range Sum
├── probi.cpp          # Problem I - String Permutation Counting
├── probj.cpp          # Problem J - Array Subarray Analysis
├── probk.cpp          # Problem K - Binary Search with Cost Optimization
├── probl.cpp          # Problem L - Tree Queries with Segment Tree
└── probm.cpp          # Problem M - String Minimal Partitioning
```

## 🚀 Problem Descriptions

### Problem A - Game Winner Determination
- **File**: `proba.cpp`
- **Algorithm**: Simple arithmetic and comparison
- **Complexity**: O(n)
- **Description**: Determines the winner between Pak Chanek, Pak Ganesh, or declares a tie ("Mabar") based on the sum of two arrays.

### Problem B - Binary Number Validation
- **File**: `probb.cpp`
- **Algorithm**: Binary number simulation with carry handling
- **Complexity**: O(MAX) where MAX = 200,000
- **Description**: Validates if a given binary number representation is valid by simulating binary arithmetic operations.

### Problem C - Train Scheduling
- **File**: `probc.cpp`
- **Algorithm**: Fenwick Tree, coordinate compression, sorting
- **Complexity**: O(n log n)
- **Description**: Solves a complex train scheduling problem using advanced data structures to count valid train combinations.

### Problem D - Array Partitioning
- **File**: `probd.cpp`
- **Algorithm**: Binary search on answer
- **Complexity**: O(n log(sum))
- **Description**: Finds the minimum maximum sum when partitioning an array into k groups using binary search.

### Problem E - Matrix Exponentiation
- **File**: `probe.cpp`
- **Algorithm**: Matrix exponentiation, state transitions
- **Complexity**: O(n³ log K)
- **Description**: Uses matrix exponentiation to solve a complex state transition problem with modular arithmetic.

### Problem H - Fibonacci Range Sum
- **File**: `probh.cpp`
- **Algorithm**: Matrix exponentiation, Fibonacci sequence
- **Complexity**: O(log n) per query
- **Description**: Calculates the sum of Fibonacci numbers in a range [l, r] using matrix exponentiation and modular arithmetic.

### Problem I - String Permutation Counting
- **File**: `probi.cpp`
- **Algorithm**: Factorial calculation, special case handling
- **Complexity**: O(n)
- **Description**: Counts valid permutations of a string with special handling for n=3 case.

### Problem J - Array Subarray Analysis
- **File**: `probj.cpp`
- **Algorithm**: Monotonic stack, divisibility checking
- **Complexity**: O(n)
- **Description**: Analyzes subarrays to find valid ranges where elements satisfy divisibility constraints.

### Problem K - Cost Optimization
- **File**: `probk.cpp`
- **Algorithm**: Binary search on answer
- **Complexity**: O(n log n)
- **Description**: Uses binary search to find the maximum number of elements that can be selected within a cost limit.

### Problem L - Tree Queries
- **File**: `probl.cpp`
- **Algorithm**: Heavy-light decomposition, segment tree with lazy propagation
- **Complexity**: O(log² n) per query
- **Description**: Handles tree queries with XOR operations using advanced tree data structures.

### Problem M - String Minimal Partitioning
- **File**: `probm.cpp`
- **Algorithm**: Rolling hash, two-pointer technique
- **Complexity**: O(n²)
- **Description**: Finds the minimal number of partitions needed to make a string palindromic using rolling hash.

## 🛠️ Compilation and Usage

### Prerequisites
- C++ compiler with C++11 or later support
- Standard template library (STL)

### Compilation
```bash
# Compile individual problems
g++ -std=c++17 -O2 proba.cpp -o proba
g++ -std=c++17 -O2 probb.cpp -o probb
g++ -std=c++17 -O2 probc.cpp -o probc
# ... and so on for other problems

# Or compile all at once
for file in prob*.cpp; do
    g++ -std=c++17 -O2 "$file" -o "${file%.cpp}"
done
```

### Running Solutions
```bash
# Run compiled executables
./proba
./probb
./probc
# ... etc.

# Or run directly with g++
g++ -std=c++17 -O2 proba.cpp -o proba && ./proba
```

## 📊 Algorithm Categories

- **Binary Search**: Problems D, K
- **Data Structures**: Problems C (Fenwick Tree), L (Segment Tree)
- **Dynamic Programming**: Problems E, H (Matrix Exponentiation)
- **Greedy**: Problem M
- **Graph Theory**: Problem L (Tree algorithms)
- **Number Theory**: Problem J (Divisibility)
- **String Algorithms**: Problem M (Rolling Hash)
- **Sorting & Searching**: Problems C, J, K

## 🔧 Common Optimizations Used

- Fast I/O (`ios_base::sync_with_stdio(false)`, `cin.tie(0)`)
- `#include <bits/stdc++.h>` for comprehensive STL inclusion
- Long long (`ll`) typedef for large numbers
- Modular arithmetic with `const ll MOD = 998244353`
- Efficient macros for common operations
- Memory optimization with vectors and smart data structure choices

## 📝 Input/Output Format

Most problems follow standard competitive programming I/O:
- Input: Space-separated integers/strings
- Output: Single line with the answer
- Multiple test cases handled with `while(t--)` pattern

## 🎯 Contest Information

- **Event**: Compfest-17-SCPC
- **Language**: C++
- **Difficulty**: Mixed (Easy to Hard)
- **Topics**: Algorithms, Data Structures, Competitive Programming

## 🤝 Contributing

Feel free to contribute by:
- Adding problem descriptions for missing problems
- Improving existing solutions
- Adding alternative solutions in different languages
- Fixing bugs or optimizing algorithms

## 📚 Learning Resources

These solutions demonstrate various competitive programming techniques:
- [Competitive Programming Handbook](https://cses.fi/book/book.pdf)
- [CP-Algorithms](https://cp-algorithms.com/)
- [Codeforces](https://codeforces.com/)
- [AtCoder](https://atcoder.jp/)

## 📄 License

This project is for educational purposes. Please respect the original contest rules and guidelines.

---

**Note**: Some problem descriptions may be incomplete. If you have additional information about any problem, please contribute to improve this documentation.
