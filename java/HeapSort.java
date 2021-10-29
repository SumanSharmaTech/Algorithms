import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class HeapSort {
    public void sort(List<Integer> list)
    {
        for (int i = (list.size()/2 - 1); i >= 0; i--) {
            heapify(list, list.size(), i);
        }

        for (int i = list.size() - 1; i > 0; i--) {
            Collections.swap(list,0,i);
            heapify(list, i, 0);
        }
    }

    void heapify(List<Integer> list, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && list.get(l) > list.get(largest)) {
            largest = l;
        }

        if (r < n && list.get(r) > list.get(largest)){
            largest = r;
        }

        if (largest != i) {
            Collections.swap(list, i, largest);
            heapify(list, n, largest);
        }
    }

    public static void main(String[] args)
    {
        List<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,6,7,8,9,10));
        HeapSort heap = new HeapSort();

        Collections.shuffle(list);
        System.out.println(list);
        heap.sort(list);
        System.out.println(list);
    }
}
