import java.util.*;
import java.util.Arrays;


class Staircase{
  public static void main(String[] args) {
	int n = 6;
    int star = 1;
    int space = n-1;
        for (int i = 1; i <= n; i +=1){
            System.out.print(" ".repeat(space));
            System.out.print("#".repeat(star) + "\n");
			star += 1;
			space -= 1;
        }
  }
}
