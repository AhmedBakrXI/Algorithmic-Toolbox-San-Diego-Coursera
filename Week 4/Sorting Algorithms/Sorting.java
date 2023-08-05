import java.util.Random;

public class Sorting {
    public static void main(String[] args) {
        int[] numbers = new int[10];

        Random random = new Random();
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(100);
        }

        System.out.println("Before sorting: ");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        System.out.println();


        /**************** Start Selection Sorting Test ******************/
//        selection_sort(numbers);
//        System.out.println("After sorting: ");
//        for (int number : numbers) {
//            System.out.print(number + " ");
//        }
//        System.out.println();

        /**************** End Selection Sorting Test ******************/

        /**************** Start Merge Sorting Test ******************/
//        MergeSort(numbers);
//        System.out.println("After sorting: ");
//        for (int number : numbers) {
//            System.out.print(number + " ");
//        }
//        System.out.println();

        /**************** End Merge Sorting Test ******************/

        /**************** Start Quick Sorting Test ******************/
        QuickSort(numbers, 0, numbers.length - 1);
        System.out.println("After sorting: ");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        System.out.println();

        /**************** End Quick Sorting Test ******************/
    }


    private static void selection_sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }

    private static void MergeSort(int[] array) {
        if (array.length < 2)
            return;

        int midIndex = array.length / 2;
        int[] A = new int[midIndex];
        int[] B = new int[array.length - midIndex];

        for (int i = 0; i < midIndex; i++) {
            A[i] = array[i];
        }

        for (int i = midIndex; i < array.length; i++) {
            B[i - midIndex] = array[i];
        }

        MergeSort(A);
        MergeSort(B);

        merge(array, A, B);
    }

    private static void merge(int[] array, int[] leftHalf, int[] rightHalf) {
        int i = 0, j = 0, k = 0;

        while (i < leftHalf.length && j < rightHalf.length) {
            if (leftHalf[i] <= rightHalf[j]) {
                array[k] = leftHalf[i];
                i++;
            } else {
                array[k] = rightHalf[j];
                j++;
            }
            k++;
        }

        while (i < leftHalf.length) {
            array[k] = leftHalf[i];
            i++;
            k++;
        }

        while (j < rightHalf.length) {
            array[k] = rightHalf[j];
            j++;
            k++;
        }

    }


    private static void QuickSort(int[] array, int lowIndex, int highIndex) {
        if (lowIndex >= highIndex)
            return;

        // Choose a pivot
        int pivot = array[highIndex];

        // Partitioning
        int leftPointer = lowIndex;
        int rightPointer = highIndex;

        while (leftPointer < rightPointer) {
            while (array[leftPointer] <= pivot && leftPointer < rightPointer) {
                leftPointer++;
            }
            while (array[rightPointer] >= pivot && rightPointer > leftPointer) {
                rightPointer--;
            }
            swap(array, leftPointer, rightPointer);
        }

        swap(array, leftPointer, highIndex);
        QuickSort(array, lowIndex, leftPointer - 1);
        QuickSort(array, leftPointer + 1, highIndex);
    }

    private static void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}
