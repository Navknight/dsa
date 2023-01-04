#include <iostream>
#include <vector>

using namespace std;

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



int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    floodFill(image, sr, sc, color);
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[0].size(); j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}