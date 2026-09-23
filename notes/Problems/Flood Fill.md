---
link: https://leetcode.com/problems/flood-fill/
difficulty: Easy
topics:
  - "[[Graphs]]"
  - "[[Arrays]]"
  - "[[DFS]]"
source: Standard
star: false
blind75: false
mastery:
review:
insight: "DFS from the start pixel, recolor cells with the old color. return early if old == new"
time: "O(m * n)"
space: "O(m * n)"
date: 
---

# Problem
Recolor the 4-connected region of the start pixel.

# Approach
## DFS
Same as [[Number Of Islands]]. Return early if the color already matches, else it loops forever.

### Code
```cpp
void fill(vector<vector<int>> &image, int sr, int sc, int color, int oldColor){
    if(sr < 0|| sc < 0|| sr >= image.size() || sc >= image[0].size() ||image[sr][sc] != oldColor) return;
    image[sr][sc] = color;
    fill(image, sr + 1, sc, color, oldColor);
    fill(image, sr - 1, sc, color, oldColor);
    fill(image, sr, sc + 1, color, oldColor);
    fill(image, sr, sc - 1, color, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if(image[sr][sc] == color) return image;
    int oldColor = image[sr][sc];
    fill(image, sr, sc, color, oldColor);
    return image;
}
```

### Complexity
- Time: $O(m \cdot n)$
- Space: $O(m \cdot n)$
