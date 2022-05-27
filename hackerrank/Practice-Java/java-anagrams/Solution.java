import java.util.Scanner;
import java.util.*;

public class Solution {

    static boolean isAnagram(String a, String b) {
        // test for invalid input
        if (a == null || b == null || a .equals("") || b.equals("")){
            throw new IllegalArgumentException();
        }

        // Test length of the strings if they match
        if (a.length() != b.length()){
            return false;
        }

        a = a.toUpperCase();
        b = b.toUpperCase();

        // Hash table where the letters are the keys and the frequencies are the values
        Map<Character, Integer> map = new HashMap<>();

        for (int k = 0; k < b.length(); k += 1){
            char letter = b.charAt(k);

            // If the letter is not in the map
            if (!map.containsKey(letter)){
                map.put(letter, 1);
            } else {
                Integer frequency = map.get(letter);
                map.put(letter, frequency += 1);
            }
        }

        for (int k = 0; k < a.length(); k += 1){
            char letter = a.charAt(k);

            if (! map.containsKey(letter)){
                return false;
            }

            Integer frequency = map.get(letter);

            if (frequency == 0){
                return false;
            }else{
                map.put(letter, frequency -= 1); 
            }
        }

        return true;
    }

    public static void main(String[] args) {

        // Scanner scan = new Scanner(System.in);
        // String a = scan.next();
        // String b = scan.next();
        // scan.close();
        String a = "anagram";
        String b = "margana";
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
