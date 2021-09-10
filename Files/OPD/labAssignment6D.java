import java.util.*;

class ReverseOrder {
    public String reverse(String ray) {
        StringTokenizer st = new StringTokenizer(ray);

        String solution = "";

        while (st.hasMoreTokens())
            solution = st.nextToken() + " " + solution;

        return solution;
    }
}

public class labAssignment6D {
    public static void main(String[] args) {
        ReverseOrder solution = new ReverseOrder();
        String ray = "Birla Institute of Technology";
        ray = solution.reverse(ray);
        System.out.println(ray);
    }
}
