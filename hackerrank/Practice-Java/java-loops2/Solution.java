import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt(); // number of queries
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            
            int[] result = new int[n];
            
            for (int count = 0; count < n; count+=1){
                a += (int)Math.pow(2, count) * b;
                result[count] = a;
            }
            for (int count = 0; count < n; count+=1){
                System.out.printf("%d ", result[count]);
            }
            System.out.println();

        }
        in.close();
    }
}

