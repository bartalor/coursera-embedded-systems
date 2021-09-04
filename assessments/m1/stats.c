#include <limits.h>
#include <stdio.h>

void print_statistics(int arr[], int N);
void print_array(int arr[], int N);
double find_median();
double find_mean();
int find_maximum();
int find_minimum();
void sort_array();


int main() {
    int arr[6] = {6,5,4,3,2,1};
    print_statistics(arr,6);
}

void print_statistics(int arr[], int N) {

    printf("arr before sort:\n");
    print_array(arr,N);
    printf("\n\n");

    printf("max: %d\n\n", find_maximum(arr,N));

    printf("min: %d\n\n", find_minimum(arr,N));
    
    printf("median: %f\n\n", find_median(arr,N));

    printf("mean: %f\n\n", find_mean(arr,N));

    printf("arr after sort:\n");
    print_array(arr,N);
    printf("\n\n");

    
}

void print_array(int arr[], int N) {
    int i;
    for (i=0; i < N; i++)  {
        printf("%d   ", arr[i]);
    }
}

double find_median(int arr[], int N) {
    sort_array(arr);
    double median;
    if(N==0) {
        printf("error N = 0\n");
        return 0;
    }
    if(N%2 == 0)// even 
        median = ((double)(arr[N/2-1]+arr[N/2]))/2;

    else // odd
        median = arr[N/2];

    return  median;
}

double find_mean(int arr[], int N) {
    int i, sum = 0;
    for(i=0; i<N; i++)  {
        sum += arr[i];
    }
    return ((double)sum)/N;
}

int find_maximum(int arr[], int N) {
    int i=0;
    int max = INT_MIN;
    for(i=0; i<N; i++)  {
        if(max < arr[i]) max = arr[i];
    }
    return max;
}

int find_minimum(int arr[], int N) {
    int i=0;
    int min = INT_MAX;
    for(i=0; i<N; i++)  {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

void sort_array(int arr[], int N) {
    int i, temp, sorted = 0;
    while(!sorted)    {
        sorted = 1;
        for(i=0; i<N-1; i++) {
            if(arr[i+1] < arr[i])   {
                sorted = 0;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

