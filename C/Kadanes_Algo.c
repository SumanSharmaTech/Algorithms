// Kadane's Algorithm : Maximum Sum of a Subarray [O(n)]

#include <stdio.h>

int kadane(int arr[], int n) {
  int max_sum = 0,current_sum = 0;

  for(int i=0; i<n; i++) {
    current_sum = current_sum + arr[i];
    if (current_sum < 0)
      current_sum = 0; 
    if(max_sum < current_sum)
      max_sum = current_sum; 
  }
  return max_sum;
}

int main() {
  int n,t;
  printf("Enter a length of array: ");
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++){
      scanf("%d", &t);
      arr[i]=t;
  }
  printf("Maximum SubArray is: %i", kadane(arr, n));
  return 0;
}