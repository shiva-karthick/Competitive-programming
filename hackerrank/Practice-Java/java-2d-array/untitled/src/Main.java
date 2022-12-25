import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<List<Integer>> arr = new ArrayList<>();
        // arr = [arrRowItems, arrRowItems, arrRowItems ...]

        for (int i = 0; i < 6; i++) {
            String[] arrRowTempItems = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");
            List<Integer> arrRowItems = new ArrayList<>();
            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowTempItems[j]);
                arrRowItems.add(arrItem);
            }
            arr.add(arrRowItems);
        }
        bufferedReader.close();

        List<Integer> result = new ArrayList<Integer>();
        // Get the middle index
        for (int i = 1; i < 5; ++i) {
            for (int j = 1; j < 5; ++j) {
                // check if left and right is a 0 and the center > 0; store the index of the center

//                    System.out.printf("i = %d, j = %d \n", i, j);
                result.add(arr.get(i).get(j) + arr.get(i - 1).get(j - 1) + arr.get(i - 1).get(j) + arr.get(i - 1).get(j + 1) + arr.get(i + 1).get(j - 1) + arr.get(i + 1).get(j) + arr.get(i + 1).get(j + 1));


//                System.out.println(arr.get(i).get(j));
            }
        }

        System.out.println(Collections.max(result));
//        for (List<Integer> a : arr) {
//            for (int y : a) {
//                System.out.print(y + " ");
//            }
//            System.out.println();
//        }
    }
}