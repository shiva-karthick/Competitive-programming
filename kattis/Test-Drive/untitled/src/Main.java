import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.stream.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        List<Integer> list = new ArrayList<Integer>();

        list.add(scanner.nextInt());
        list.add(scanner.nextInt());
        list.add(scanner.nextInt());

        int[] array = list.stream().mapToInt(i -> i).toArray();
        int d1 = array[1] - array[0];
        int d2 = array[2] - array[1];

        if ((d1 * d2) < 0) {
            System.out.println("turned"); // there exists an inflexion point
        } else if (Math.abs(d1) > Math.abs(d2)) {
            System.out.println("braked");
            /*
            * there was a bug whereby I thought 0 5 1 being an inflexion point would give me turned, however, the code I wrote also gave braked. So, I fixed the correct code to detect the turned.
            * */
        } else if (Math.abs(d1) < Math.abs(d2)) {
            System.out.println("accelerated");
        } else if (d1 == d2) {
            System.out.println("cruised");
        }
    }
}