class Solution {
public:
    void algo(vector<vector<int>>& image, int sr, int sc, int color, int newcolor) {
        // Boundary check and color match check
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color) {
            return;
        }
        
        // Update current pixel color
        image[sr][sc] = newcolor;
        
        // Recursively fill adjacent pixels
        algo(image, sr + 1, sc, color, newcolor);
        algo(image, sr - 1, sc, color, newcolor);
        algo(image, sr, sc + 1, color, newcolor);
        algo(image, sr, sc - 1, color, newcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if (image[sr][sc] == color) {
            return image;
        }

        
        algo(image, sr, sc, image[sr][sc], color);
        
        return image;
    }
};
x