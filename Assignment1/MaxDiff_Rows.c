#include <stdio.h>
#include <limits.h>
//Given a matrix of size N * M where N represent number of rows and M represents number of columns.
//For a row we define a value called DiffValue which is difference between its largest term and the smallest term i.e 
//(maximum term - minimum term). You have to answer the largest DiffValue among all the rows for the given matrix.
int main() {
    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
        int rowMin = 10000, rowMax = 1; //Limits given in question
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < rowMin) {
                rowMin = matrix[i][j];
            }
            if (matrix[i][j] > rowMax) {
                rowMax = matrix[i][j];
            }
        }
        int diff = rowMax - rowMin;
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    printf("The largest DiffValue is: %d\n", maxDiff);
    return 0;
}