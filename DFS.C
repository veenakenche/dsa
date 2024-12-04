#include <stdio.h>
#define MAX 5

void depth_first_search(int adj[MAX][MAX], int visited[], int start) {
    int stack[MAX], top = -1, i;


    stack[++top] = start;
    visited[start] = 1;

    printf("%c-", start + 65);

    while (top != -1) {
        int current = stack[top];
        int found = 0;

        for (i = 0; i < MAX; i++) {
            if (adj[current][i] && visited[i] == 0) {

                stack[++top] = i;
                visited[i] = 1;
                printf("%c-", i + 65);
                found = 1;
                break;
            }
        }


        if (!found) {
            top--;
        }
    }
}

int main() {
    int adj[MAX][MAX], visited[MAX] = {0}, i, j;

    printf("Enter the adjacency matrix (%dx%d):\n", MAX, MAX);
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("DFS Traversal: ");
    depth_first_search(adj, visited, 0);
    printf("\n");


    for (i = 0; i < MAX; i++) {
        if (visited[i] == 0) {
            printf("The graph is not connected.\n");
            return 0;
        }
    }
    printf("The graph is connected.\n");
    return 0;
}
