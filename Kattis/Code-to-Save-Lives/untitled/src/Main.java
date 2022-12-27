import java.util.Scanner;
import java.util.ArrayList;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_cases = 0;
        Long total;
        String output = "";

        /* Note that scanner can be very slow on large inputs. Consider using a buffered reader such as the KattIO library if the problem has large inputs*/
        while (sc.hasNextLine()) {
            String data = sc.nextLine();
            if (data.length() == 1) {
                test_cases = Integer.parseInt(data);
            }
            break;
        }
        for (int i = 0; i < test_cases; ++i) {
            String number_1 = sc.nextLine();
            String number_2 = sc.nextLine();
            number_1 = number_1.replaceAll("\\s", "");
            number_2 = number_2.replaceAll("\\s", "");
            total = Long.valueOf(number_1) + Long.valueOf(number_2);

            // convert from int to String
            output = String.valueOf(total);
            String result = Stream.of(output.split(""))
                    .collect(Collectors.joining(" "));
            System.out.println(result);
        }
        sc.close();
    }
}