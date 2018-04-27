#include <stdio.h>
#include "Objects.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"

typedef void (* SortFunction)(Vector*, unsigned int);

typedef void (* SortRangeFunction)(Vector*, unsigned int, unsigned int,
                                   unsigned int);

typedef struct {
    SortFunction sortFunction;
    SortRangeFunction sortRangeFunction;
    char* name;
} SortFunctionPair;

int main() {
    printf("Hello! Let's sort this out!\n");
    unsigned int debug = 0;
    int v[] = {72, 29, 38, 22, 60, 2};

    SortFunctionPair functions[] = {
            {Sort_Selection_Vector, Sort_Selection_Vector_Range, "Selection Sort"},
            {Sort_Insertion_Vector, Sort_Insertion_Vector_Range, "Insertion Sort"},
            {Sort_Bubble_Vector,    Sort_Bubble_Vector_Range,    "Bubble Sort"},
            {Sort_Heap_Vector,      Sort_Heap_Vector_Range,      "Heap Sort"}
    };
    int functionsSize = 4;

    for (int i = 0; i < functionsSize; ++i) {
        printf("\nRunning %s\n", functions[i].name);
        Vector* vector = Vector_createFromArrayCopy(v, 6);

        printf("Initial Array:\n");
        Vector_print(vector);

        (*functions[i].sortFunction)(vector, debug);

        printf("Sorted Array:\n");
        Vector_print(vector);

        Vector_destroy(vector);
    }

    unsigned int min = 1, max = 4;
    printf("\nLet's sort just part of the vector, from index %1d to %1d\n", min,
           max);

    for (int i = 0; i < functionsSize; ++i) {
        printf("\nRunning %s\n", functions[i].name);
        Vector* vector = Vector_createFromArrayCopy(v, 6);

        printf("Initial Array:\n");
        Vector_print(vector);

        (*functions[i].sortRangeFunction)(vector, min, max, debug);

        printf("Sorted Array:\n");
        Vector_print(vector);

        Vector_destroy(vector);
    }

    return 0;
}