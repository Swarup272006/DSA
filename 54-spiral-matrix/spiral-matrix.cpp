class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> solution;

        int r = matrix.size();
        int c = matrix[0].size();

        int srow = 0;
        int erow = r - 1;

        int scol = 0;
        int ecol = c - 1;

        while (srow <= erow && scol <= ecol) {

            // Top row
            for (int j = scol; j <= ecol; j++) {
                solution.push_back(matrix[srow][j]);
            }
            srow++;

            // Right column
            for (int i = srow; i <= erow; i++) {
                solution.push_back(matrix[i][ecol]);
            }
            ecol--;

            // Bottom row
            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    solution.push_back(matrix[erow][j]);
                }
                erow--;
            }

            // Left column
            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    solution.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }

        return solution;
    }
};