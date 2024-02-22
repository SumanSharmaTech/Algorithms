    #include <iostream>
    using namespace std;
     
    // First subarray is arr[low..mid]
    // Second subarray is arr[mid+1..high]
    void merge(int arr[], int low, int mid, int high)
    {
    	int l1 = mid - low + 1;
    	int l2 = high - mid;
     
    	int left[l1], right[l2];
     
    	for (int i = 0; i < l1; i++) {
    		left[i] = arr[low + i];
    	}
    	for (int i = 0; i < l2; i++) {
    		right[i] = arr[mid + 1 + i];
    	}
     
    	int i = 0, j = 0, k = low;
    	while (i < l1 && j < l2) {
    		if (left[i] <= right[j]) {
    			arr[k] = left[i];
    			i++;
    		}
    		else {
    			arr[k] = right[j];
    			j++;
    		}
    		k++;
    	}
     
    	while (i < l1) {
    		arr[k] = left[i];
    		i++, k++;
    	}
     
    	while (j < l2) {
    		arr[k] = right[j];
    		j++, k++;
    	}
    }
     
     
    void mergeSort(int arr[], int low, int high) {
    	if (low < high) {
    		//calculate mid-point
    		int mid = (low + high) / 2;
     
    		// Sort sub-arrays
    		mergeSort(arr, low, mid);
    		mergeSort(arr, mid + 1, high);
     
    		//merge sorted sub-arrays
    		merge(arr, low, mid, high);
    	}
    }
     
     
    // Driver code
    int main()
    {
    	int n;
    	cin >> n;
    	int arr[n];
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    	}
     
    	mergeSort(arr, 0, n - 1);
     
    	for (int i = 0; i < n; i++)
    		cout << arr[i] << " ";
     
    	return 0;
    }