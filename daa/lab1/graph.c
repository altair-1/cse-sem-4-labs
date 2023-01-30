#include <stdio.h>
#include <stdlib.h>

void init(int arr[][10], int v) {
  int i, j;
  for (i = 0; i < v; i++)
    for (j = 0; j < v; j++)
      arr[i][j] = 0;
}

void addEdge(int arr[][10], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void printAdjMatrix(int arr[][10], int v) {
  int i, j;
  for (i = 0; i < v; i++) {
    printf("%d: ", i+1);
    for (j = 0; j < v; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

typedef struct AdjNode {
	int vertex;
	struct AdjNode *next;
} ADJ_NODE_t, *ADJ_NODE_ptr;

typedef struct AdjListNode {
	int count;
	ADJ_NODE_ptr head;
} ADJ_LIST_NODE_t, *ADJ_LIST_NODE_ptr;

ADJ_NODE_ptr createAdjNode (int value) {
	ADJ_NODE_ptr adjNode = (ADJ_NODE_ptr)malloc(sizeof(ADJ_NODE_t));
	adjNode->vertex = value;
	adjNode->next = NULL;
	return adjNode;
}

ADJ_LIST_NODE_ptr createAdjListNode () {
	ADJ_LIST_NODE_ptr adjListNode = (ADJ_LIST_NODE_ptr)malloc(sizeof(ADJ_LIST_NODE_t));
	adjListNode->count = 0;
	adjListNode->head = NULL;
	return adjListNode;
}

void insertAdjNode (ADJ_NODE_ptr *head, int value) {
	if (*head == NULL) {
		*head = createAdjNode(value);
		return;
	}
	ADJ_NODE_ptr temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = createAdjNode(value);
}

ADJ_LIST_NODE_ptr * inputAdjList (int arr[][10], int v) {
	int i, vertex;
	ADJ_LIST_NODE_ptr *listHeadArr = (ADJ_LIST_NODE_ptr *)calloc(v, sizeof(ADJ_LIST_NODE_ptr));
	ADJ_LIST_NODE_ptr temp;
	for (i = 0; i < v; ++i) {
		*(listHeadArr + i) = createAdjListNode();
		temp = *(listHeadArr + i);
		printf("vertex %d, enter the connected vertices (1 - %d), 0 to break: \n", i+1, v);
		do {
			scanf(" %d", &vertex);
			if (vertex != 0)
        addEdge(arr, i, vertex-1);
				insertAdjNode(&temp->head, vertex);
		} while (vertex != 0);
	}
	return listHeadArr;
}

void printAdjList (ADJ_LIST_NODE_ptr *listHeadArr) {
	int i = 0;
	ADJ_LIST_NODE_ptr temp = *(listHeadArr + i);
	while (temp != NULL) {
		printf("\n%d | ", i+1);
		temp = *(listHeadArr + i);
		ADJ_NODE_ptr p = temp->head;
		while (p->next != NULL) {
			printf("%d -> ", p->vertex);
			p = p->next;
		}
		printf("%d ", p->vertex);
		temp = *(listHeadArr + (++i));
	}
}

int main (int argc, const char * argv []) {
  int adjMatrix[10][10];
	int v, e;
	printf("enter number of vertices: ");
	scanf(" %d", &v);
	printf("enter number of edges: ");
	scanf(" %d", &e);
  init(adjMatrix, v);
  ADJ_LIST_NODE_ptr *list = inputAdjList(adjMatrix, v);
  printf("\nlist representation");
  printAdjList(list);
  printf("\n\nmatrix representation\n");
  printAdjMatrix(adjMatrix, v);
	printf("\n");
	return 0;
}