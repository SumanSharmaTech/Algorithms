package main

import "fmt"

func insertionSort(arr []int) []int {
	sortedArr := arr
	for i:=1;i<len(sortedArr);i++ {
		key := sortedArr[i]
		j := i-1
		for j>=0 && sortedArr[j]>key {
			sortedArr[j+1] = sortedArr[j]
			j -= 1
		}
		sortedArr[j+1] = key
	}
	return sortedArr
}

func main() {
	usArr := []int{5, 2, 6, 3, 1, 4}
	fmt.Println("Before sort: ", usArr)
	sArr := insertionSort(usArr)
	fmt.Println("After sort: ", sArr)
}
