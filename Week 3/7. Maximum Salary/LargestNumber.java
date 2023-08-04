import java.util.*;

import static java.util.Collections.swap;

public class LargestNumber {
    private static String largestNumber(String[] a) {
        //write your code here
        String result = "";

        for (int i = 0; i < a.length; i++) {
            for (int j = i + 1; j < a.length; j++) {
                if (a[j].concat(a[i]).compareTo(a[i].concat(a[j])) > 0) {
                    String temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }

        for (int i = 0; i < a.length; i++) {
            result += a[i];
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.next();
        }

        System.out.println(largestNumber(a));
    }
}

