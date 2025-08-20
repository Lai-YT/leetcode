int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int count = 0;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (y && x && matrix[y][x]) {
                matrix[y][x] +=
                    MIN(matrix[y - 1][x],
                        MIN(matrix[y][x - 1], matrix[y - 1][x - 1]));
            }
            count += matrix[y][x];
        }
    }
    return count;
}
