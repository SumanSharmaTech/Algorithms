    #include<bits/stdc++.h>
    using namespace std;
     
    int partition(int arr[], int low, int high) {
    	int pivot = arr[high]; //Taking the last element as pivot
    	int i = low - 1; //index of last element smaller than pivot element
     
    	for (int j = low; j < high; j++) {
    		if (arr[j] < pivot) {
    			i++;
    			swap(arr[i], arr[j]);
    		}
    	}
    	swap(arr[i + 1], arr[high]);
    	return (i + 1);
    }
     
    void quickSort(int arr[], int low, int high) {
    	if (low < high) {
    		int part = partition(arr, low, high);
    		quickSort(arr, low, part - 1);
    		quickSort(arr, part + 1, high);
    	}
    }
     
    int main() {
    	int n;
    	cin >> n;
    	int arr[n];
    	for (int i = 0; i < n; i++)
    		cin >> arr[i];
     
    	quickSort(arr, 0, n - 1);
     
    	for (int i = 0; i < n; i++)
    		cout << arr[i] << " ";
    	cout << endl;
    }
     
    /*
    Example Test case:
    5
    5 4 2 1 3
    */