---
type: reference
topic: Tricks
---

## Finding Mid - 
Using `left + (right - left)/2` over `(left + right)/2` ensures that integer overflow does not happen while doing `left + right`.
