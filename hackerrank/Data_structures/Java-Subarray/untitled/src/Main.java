import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int[] array1 = {1, -2, 4, -5, 1}; // initialise the array with n elements

        int count = 0;
        for (int j = 0; j < 5; j++) {
            int sum = 0;
            for (int k = j; k < 5; k++) {
                sum = array1[k] + sum;
                if (sum < 0) {
                    System.out.printf("sum = %d \n", sum);
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}