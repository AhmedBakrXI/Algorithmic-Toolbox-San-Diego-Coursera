public class Sorting {
    public static void main(String[] args) {
        int[] numbers = {9, 3, 2, 5, 10, 3, 7};

        System.out.println("Before sorting: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();


        /**************** Start Selection Sorting Test ******************/
//        selection_sort(numbers);
//        System.out.println("After sorting: ");
//        for (int i = 0; i < numbers.length; i++) {
//            System.out.print(numbers[i] + " ");
//        }
//        System.out.println();

        /**************** End Selection Sorting Test ******************/

        /**************** Start Merge Sorting Test ******************/
        MergeSort(numbers);
        System.out.println("After sorting: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
        /**************** End Merge Sorting Test ******************/
    }


    public static void selection_sort(int[] array) {
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

    public static void MergeSort(int[] array) {
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

    public static void merge(int[] array, int[] leftHalf, int[] rightHalf) {
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
}
