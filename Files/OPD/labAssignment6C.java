import java.util.Scanner;

public class labAssignment6C {
    public static void main(String[] args) {
        String first = "abcXY123XYijk";
        String second = "XY";
        String ans = "";
        int l = 0;
        while (l >= 0) {
            int a = first.indexOf(second, l);
            if (a == -1)
                break;
            else if (a == 0)
                ans += first.charAt(a + second.length());
            else if (a + second.length() + 1 > first.length() || a == first.length() - 1) {
                ans += first.charAt(a - 1);
                break;
            } else {
                ans += first.charAt(a - 1);
                ans += first.charAt(a + second.length());
            }
            l = a + 1;
        }
        System.out.println(ans);
    }
}
