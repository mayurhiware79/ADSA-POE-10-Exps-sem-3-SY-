// // FILE WHICH IMPLEMENTS BFS TRAVERSAL FOR GRAPH

// #include <stdio.h>

// void BFS(int n, int graph[20][20], int visited[20], int source)
// {
//     int queue[20];
//     int front = 0;
//     int rear = 0;
//     visited[source] = 1;
//     queue[rear++] = source;

//     while (front < rear)
//     {
//         int current = queue[front++];
//         printf("visited :%d \n", current);
//         for (int i = 0; i < n; i++)
//         {

//             if (graph[current][i] == 1 && !visited[i])
//             {
//                 visited[i] = 1;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

// int main()
// {
//     int num;
//     int graph[20][20], visited[20] = {0}, source;

//     printf("enter the number of vertices :");
//     scanf("%d", &num);

//     printf("Enter adjacency matrix : \n");
//     for (int i = 0; i < num; i++)
//     {
//         for (int j = 0; j < num; j++)
//         {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     printf("enter the source :");
//     scanf("%d", &source);

//     BFS(num, graph, visited, source);

//     for (int i = 0; i < num; i++)
//     {
//         if (!visited[i])
//         {
//             printf("not connected");
//             break;
//         }
//     }
//     printf(" connected");
// }


// FILE WHICH IMPLEMENTS BFS TRAVERSAL FOR GRAPH
#include <stdio.h>

void BFS(int n, int graph[20][20], int visited[20], int source)
{
    int queue[20];
    int front = 0;
    int rear = 0;
    
    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear)
    {
        int current = queue[front++];
        printf("Visited node: %d\n", current);

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int num;
    int graph[20][20], visited[20] = {0}, source;
    int connected = 1; // flag to check if graph is connected

    printf("Enter the number of vertices: ");
    scanf("%d", &num);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("Edge between vertex %d and %d (1 for yes, 0 for no): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", num - 1);
    scanf("%d", &source);

    if (source < 0 || source >= num)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    printf("\n--- BFS Traversal ---\n");
    BFS(num, graph, visited, source);

    for (int i = 0; i < num; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is not connected.\n");

    return 0;
}
