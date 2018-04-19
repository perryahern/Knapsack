#include <stdlib.h>
#include <stdio.h>

void insertionSort(int sortArray[], int syncArray1[], int syncArray2[], int n)
{
  for (int i = 0; i < n; i++) {
    int temp1 = sortArray[i];
    int temp2 = syncArray1[i];
    int temp3 = syncArray2[i];
    int j = i - 1;
    while (j >=0 && sortArray[j] > temp1) {
      sortArray[j + 1] = sortArray[j];
      syncArray1[j + 1] = syncArray1[j];
      syncArray2[j + 1] = syncArray2[j];
      j--;
    }
    sortArray[j + 1] = temp1;
    syncArray1[j + 1] = temp2;
    syncArray2[j + 1] = temp3;
  }
}

int main(int argc, char **argv) {
  char *file = argv[1];
  int indexes[10] = {0};
  int costs[10] = {0};
  int values[10] = {0};
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int items[10] = {};
  int total_value = 0;
  int total_cost = 0;
  int MAXCOST = 100;
  int ITEMCOUNT = 10;
  FILE *fp;

  // printf("file to open: %s\n", file);

  if ((fp = fopen(file, "r")) == NULL) {
    printf("Error opening file, exiting.\n");
    exit(1);
  }

  while(fscanf(fp, "%d %d %d", &num1, &num2, &num3) == 3) {
    int i = num1 - 1;
    indexes[i] = num1;
    costs[i] = num2;
    values[i] = num3;
  }
  
  fclose(fp);
  printf("\nInitial order:\n");
  printf("The indexes array contains:  ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", indexes[i]);
  }
  printf("\n");

  printf("The costs array contains:    ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", costs[i]);
  }
  printf("\n");

  printf("The values array contains:   ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", values[i]);
  }
  printf("\n");

  // start with the most valuable and solve from there
  insertionSort(values, costs, indexes, ITEMCOUNT);
  printf("\nSorted by value:\n");
  printf("The indexes array contains:  ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", indexes[i]);
  }
  printf("\n");

  printf("The costs array contains:    ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", costs[i]);
  }
  printf("\n");

  printf("The values array contains:   ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", values[i]);
  }
  printf("\n");
  // for (int i = ITEMCOUNT - 1; i >= 0; i--) {
  //   int temp_cost = costs[i];
  //   int temp_items[10] = {NULL};
  //   temp_items[ITEMCOUNT] = 1;
  //   int j = ITEMCOUNT - 2;
  //   while (temp_cost <= MAXCOST && j >= 0) {
  //     if (temp_cost + costs[j] <= MAXCOST) {

  //     }
  //   }
  // }

  // start with the smallest weight (cost) and solve from there
  insertionSort(costs, values, indexes, ITEMCOUNT);
  printf("\nSorted by cost:\n");
  printf("The indexes array contains:  ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", indexes[i]);
  }
  printf("\n");

  printf("The costs array contains:    ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", costs[i]);
  }
  printf("\n");

  printf("The values array contains:   ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", values[i]);
  }
  printf("\n");

  // testing
  insertionSort(indexes, values, costs, ITEMCOUNT);
  printf("\nSorted by index (original order):\n");
  printf("The indexes array contains:  ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", indexes[i]);
  }
  printf("\n");

  printf("The costs array contains:    ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", costs[i]);
  }
  printf("\n");

  printf("The values array contains:   ");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", values[i]);
  }
  printf("\n\n");

  // averages - get a cost/value ratio for each item and solve from highest down

  // brute force method


  return 0;
};