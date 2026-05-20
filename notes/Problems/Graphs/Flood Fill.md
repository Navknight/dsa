---
difficulty: Easy
topics: ["Graphs", "Matrix", "DFS"]
source: Standard
star: false
link: "https://leetcode.com/problems/flood-fill/"
---

[[Graphs]] [[Matrix]] [[DFS]]

# Problem
An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `color`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**, consider the starting pixel, plus any pixels connected **4-directionally** to the starting pixel of the same color as the starting pixel, plus any pixels connected **4-directionally** to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with `color`.

Return _the modified image after performing the flood fill_.

# Solution
Very similar to the [[Number Of Islands]] Problem, almost same solution

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