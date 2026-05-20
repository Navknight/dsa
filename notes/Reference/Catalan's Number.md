---
difficulty: Unknown
topics: ["Math", "Dynamic Programming"]
source: Standard
star: false
---

[[Math]] [[Dynamic Programming]]

# Catalan Numbers
#DSA-Theory 

Catalan numbers are a sequence of natural numbers that have important applications in various mathematical and combinatoric problems. They are named after the French-Belgian mathematician Eugene Charles Catalan.

## Definition

The nth Catalan number, often denoted as C(n), is defined by the following formula:

```
C(n) = (2n)! / [(n + 1)! * n!]
```

## Counting Scenarios

Catalan numbers are used to count different types of combinatorial scenarios, such as:

1. **Balanced Parentheses:** The nth Catalan number represents the number of ways to arrange n pairs of parentheses such that they are balanced. For example, for n = 3, the sequences are: ((())), ()(()), (())(), (()()), and ()()().

2. **Binary Search Trees:** The nth Catalan number also counts the number of unique binary search trees that can be formed with n+1 labeled nodes.

3. **Polygon Triangulations:** In a polygon with n+2 sides (a polygon with n+2 vertices), the nth Catalan number gives the count of ways to triangulate it by adding non-intersecting diagonals.

4. **Dyck Words:** Catalan numbers count the number of different Dyck words of length 2n. A Dyck word is a string consisting of "X" and "Y" such that no prefix has more "Y"s than "X"s.

## Properties

1. Catalan numbers grow rapidly but not as fast as factorials or exponential functions.

2. They satisfy the recurrence relation: `C(n+1) = (2(2n+1)/(n+2)) * C(n)`.

3. The sequence of Catalan numbers starts with: 1, 1, 2, 5, 14, 42, 132, ...

## Conclusion

Catalan numbers find applications in a variety of fields including computer science, mathematics, and combinatorics. Their ability to count various combinatorial structures makes them an essential concept in solving problems related to parentheses, trees, and more.