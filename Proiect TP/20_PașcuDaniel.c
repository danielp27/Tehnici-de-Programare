#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void spiralFill(int k, int m, int n, int a[20][20])
{
    // Initialize value to be filled in matrix
    int val = 1;

    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index */
    int l = 0;
    while (k < m && l < n)
    {
        /* Print the first row from the remaining
          rows */
        for (int i = l; i < n; ++i)
            a[k][i] = val++;

        k++;

        /* Print the last column from the remaining
          columns */
        for (int i = k; i < m; ++i)
            a[i][n-1] = val++;
        n--;

        /* Print the last row from the remaining
           rows */
        if (k < m)
        {
            for (int i = n-1; i >= l; --i)
                a[m-1][i] = val++;
            m--;
        }

        /* Print the first column from the remaining
           columns */
        if (l < n)
        {
            for (int i = m-1; i >= k; --i)
                 a[i][l] = val++;
            l++;
        }
    }
}

int main() {
	int n, k, m, a[20][20], i, j, x;
	printf("Introduceti numarul de linii si de coloane (1 <= n <= 18): ");
	scanf("%d", &n);
	while (n < 1 || n > 18) {
		printf("n nu este cuprins in intervalul dorit, introduceti alt numar: ");
		scanf("%d", &n);
	}
	while (n >= 1 && n <= 18) {
		printf("Introduceti numarul k (1 <= k <= %d): ", n);
		scanf("%d", &k);
		while (k < 1 || k > n) {
			printf("k nu este cuprins in intervalul dorit, introduceti alt numar: ");
			scanf("%d", &k);
		}
		m = n;
		while (k >= 1 && k <= n) {
//			for (i = 0; i < n; i++)
//				for (j = 0; j < n; j++) {
//					if (x == i * j) {
//						m[i][j] = x;
//						x++;
//					}
//				}
			spiralFill(k, n, m, a);
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
			break;
		}
		break;
	}






	return 0;
}
