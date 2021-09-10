class ReverseOrder {
    public String reverse(String ray) {
        ray = ray.trim();
        String[] string = ray.split(" ");
        StringBuilder solution = new StringBuilder();

        for (int i = string.length - 1; i >= 0; i--) {
            solution.append(string[i]);
            if (i != 0)
                solution.append(" ");
        }
        return solution.toString();
    }
}

public class labAssignment6A {
    public static void main(String[] args) {
        ReverseOrder solution = new ReverseOrder();
        String ray = "Birla Institute of Technology";
        ray = solution.reverse(ray);
        System.out.println(ray);
    }
}