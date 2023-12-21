import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        /* Note that scanner can be very slow on large inputs. Consider using a buffered reader such as the KattIO library if the problem has large inputs*/
        while (sc.hasNextLine()) {
            String data = sc.nextLine();
            int sum = 0;
            double average = 0;

            // loop over every char
            for (int i = 0; i < data.length(); ++i) {
                char c = data.charAt(i);
                int ascii = (int) c;
                sum += ascii;
            }

            average = sum / data.length();
            System.out.println((char) Math.floor(average));
        }

    }

}