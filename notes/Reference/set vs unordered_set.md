---
type: reference
topic: Hash Maps
---

# set vs unordered_set

`set` is a balanced BST (red-black tree), sorted, O(log n) everything. `unordered_set` is a hash table with chaining, O(1) average and O(n) worst. Same for `map` vs `unordered_map` and `multiset` vs `unordered_multiset`.

Related: [[Hash Maps]], [[Binary Search]]

## Quick Compare

| | `set` | `unordered_set` |
|---|---|---|
| Structure | red-black tree | array of buckets, each a linked list |
| Order | sorted by `<` | none, can change on rehash |
| insert / erase / find | O(log n) | O(1) avg, O(n) worst |
| lower_bound / upper_bound | O(log n) | not available |
| min / max | O(1) `begin()` / `prev(end())` | O(n) |
| Predecessor / successor | O(log n) | not possible |
| Key needs | `operator<` (strict weak ordering) | `std::hash` and `operator==` |
| Memory | 3 pointers + color per node | 1 pointer per node + bucket array |
| Iteration | in order, O(n) | O(n + buckets) |
| Iterator invalidation | only the erased element | rehash invalidates all iterators |

## How `set` works

- Each element is a heap-allocated node: key, left, right, parent, color bit.
- Red-black rules keep the height at most 2 log2(n). Insert and erase do at most a few rotations and recolors to restore the rules, so every op is O(log n) worst case. No bad inputs exist.
- `find` walks root to leaf with `<` comparisons. Two keys are equal when neither is less than the other. No `==` is needed.
- In-order traversal gives sorted output. `lower_bound` is a normal BST descent.
- Pointer chasing makes it cache-unfriendly. Each step is a likely cache miss.

## How `unordered_set` works

1. `h = hash(key)`, then `bucket = h % bucket_count`.
2. Walk the chain in that bucket and compare with `==`.

- libstdc++ keeps one singly linked list for all nodes, and each bucket points into it. Bucket count is a prime.
- Load factor = size / bucket_count. Max load factor defaults to 1.0. When an insert would exceed it, the table rehashes: allocate about double the buckets (next prime) and move every node. That insert costs O(n), the amortized cost is O(1).
- `std::hash<int>` is the identity in libstdc++. Bucket is `x % prime`. Fine for normal data.
- Worst case: all keys land in one bucket, so every op is O(n). Causes: a bad hash function or adversarial input. Anti-hash tests exist on Codeforces for this reason (multiples of the bucket prime hurt the identity hash).
- Pointers and references to elements stay valid after rehash. Iterators do not.

## Pitfalls

- No `std::hash` for `pair`, `vector` or tuple. Write a hash or encode the key (`a * K + b` in a `long long`).
- Anti-hash fix on CF: a custom hash with a random seed, such as splitmix64 with `chrono` time mixed in.
- `reserve(n)` up front avoids rehashes. It also makes latency predictable.
- `operator[]` on `unordered_map` and `map` inserts a default value if the key is missing.
- `erase(key)` returns the count removed, so `if (s.erase(x))` finds and erases in one lookup. Same trick as the visited set in [[Word Ladder I]].
- Erasing while iterating: use the iterator returned by `erase(it)`.
- `set` with a custom comparator must be a strict weak ordering. `<=` breaks it and gives undefined behavior.

## When to use which

- Only membership or counting, no order: `unordered_set` / `unordered_map`.
- Need sorted order, min/max under updates, `lower_bound`, nearest value, range queries: `set` / `map`.
- Adversarial input (CF hacks) or hard worst-case latency: `set`, or a custom randomized hash.
- Small n (a few hundred): either works. A sorted `vector` plus binary search often beats both on cache locality.

## Quant interview angles

- **Order book:** price levels in a `map` / `std::set` (sorted, best bid is `begin()` or `rbegin()`). Order id lookup in an `unordered_map`. Each is chosen for the op it supports.
- **Latency:** hash tables have rare O(n) rehash spikes. Trees are slower on average but every op is bounded. `reserve` fixes most of the spikes.
- **Cache:** both are node-based, so both chase pointers. Open addressing tables (flat maps) store entries in one array and are much faster in practice. The standard library does not offer one. Say so.
- **Why the standard unordered containers chain:** the standard requires pointer and reference stability across rehash, which forbids open addressing.
- **Why a tree and not a heap or sorted array:** a sorted array has O(n) insert. A heap has no ordered iteration or erase of an arbitrary element. A tree gives all three in O(log n).
- **Hash quality:** a good hash spreads bits evenly, since the bucket is `h % prime` and patterns in the low bits cause collisions.
- **Expected O(1) assumes:** a good hash and load factor bounded by a constant.

## Likely questions

- Why is `set::find` O(log n) and what guarantees the height?
- What happens on insert when the load factor is exceeded? What is the amortized cost?
- Can you find the smallest element greater than x in an `unordered_set`? (No, there is no order.)
- Which iterators are invalidated by `insert` in each container?
- How would you hash a `pair<int,int>`?
- When can `unordered_set` degrade to O(n), and how do you defend against it?
- Why does the standard force chaining, and what do real systems use instead?
