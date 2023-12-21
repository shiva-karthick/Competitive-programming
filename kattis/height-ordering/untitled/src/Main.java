import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfTestCase = Integer.parseInt(sc.nextLine()); // read int

        int[] heights = new int[20];

        for (int i = 0; i < numOfTestCase; ++i) {
            int timesMoved = 0;
            // Do Sorting
            sc.nextInt();

            for (int j = 0; j < heights.length; j++) {
                heights[j] = sc.nextInt();
            }
            timesMoved = bubbleSort(heights);

            System.out.print(i + 1);
            System.out.print(" ");
            System.out.println(timesMoved);// print the number of times you had to move
        }

        sc.close(); // important; always close at the end of the code
    }

    public static int bubbleSort(int[] arr) {
        int timesMoved = 0;

        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    timesMoved += 1;
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        return timesMoved;
    }
}