import java.util.*;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // read int
        int C = sc.nextInt(); // read int
        ArrayList<Integer> arr = new ArrayList<Integer>();

        for (int j = 0; j < N; j++) {
            arr.add(sc.nextInt());
        }

        // Use a set to get the unique values
        Set<Integer> mySet = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            mySet.add(arr.get(i));
        }

        // Converting mySet to ArrayList
        ArrayList<Integer> list = new ArrayList<Integer>(mySet);

        // add the unique elements into a hashmap
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < mySet.size(); i++) {
            map.put(list.get(i), Collections.frequency(arr, list.get(i)));
        }

        System.out.println(Arrays.asList(map));

        ArrayList<Integer> tmp = new ArrayList<Integer>();
        ArrayList<Integer> output = new ArrayList<Integer>();

        while (!map.isEmpty()) {
            int maxValueInMap = Collections.max(map.values());  // This will return max value in the HashMap
            for (Entry<Integer, Integer> entry : map.entrySet()) {  // Iterate through HashMap
                if (entry.getValue() == maxValueInMap) {
                    System.out.println(entry.getKey());     // Print the key with max value
                    tmp.add(entry.getKey());
                }
            }

            // check if the length() of tmp is 1 or not
            if (tmp.size() == 1) {
                for (int i = 0; i < map.get(tmp.get(0)); i++) {
                    output.add(tmp.get(0));
                }
                map.remove(tmp.get(0)); // delete the key and value from map
                tmp.clear(); // clear the tmp ArrayList

            } else if (tmp.size() > 1) {
                // these elements have same number of occurrences in the arr ArrayList

                int early_index = 0;

                while (tmp.size() > 0) {
                    for (Integer integer : tmp) {
                        early_index = Math.min(early_index, arr.indexOf(integer)); // get the index of the key in the arr ArrayList
                    }
                    for (int i = 0; i < map.get(arr.get(early_index)); i++) {
                        output.add(arr.get(early_index));
                    }
                    tmp.remove(arr.indexOf(arr.get(early_index)));
                    map.remove(arr.get(early_index));

                    early_index = 0; // reset the variable
                }
            }
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