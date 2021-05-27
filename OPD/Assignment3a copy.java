public class Assignment3a {
    public static void main(String[] args) {
        if (args.length < 4)
            System.out.println("Not enough elements.");
        else if (args.length > 4)
            System.out.println("More than required elements.");
        else {
            int n = 2, l = 0;
            int[][] ray = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ray[i][j] = Integer.parseInt(args[l]);
                    l++;
                }
            }
            System.out.println("The given Array is: ");
            printArray(ray, n);
            int temp;
            int i = 0;
            int j = 0;
            while (i < n) {
                while (j < n) {
                    temp = ray[i][j];
                    ray[i][j] = ray[n - 1 - i][n - 1 - j];
                    ray[n - 1 - i][n - 1 - j] = temp;
                    j++;
                }
                i++;
            }
            System.out.println("The reverse of the Array is: ");
            printArray(ray, n);
        }
    }

    public static void printArray(int[][] ray, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(ray[i][j] + " ");
            System.out.println("");
        }
    }
}
