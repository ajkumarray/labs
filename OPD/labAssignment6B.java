class Solution {
    public String longestPalindrome(String ray) {
        if (ray.length() <= 1)
            return ray;

        int max = 0, start = 0, end = 0;
        int result[][] = new int[ray.length()][ray.length()];

        for (int i = 0; i < ray.length(); i++)
            result[i][i] = 1;

        for (int l = 2; l < ray.length(); l++) {
            for (int i = 0; i <= ray.length() - l; i++) {
                int j = i + l - 1;
                if (ray.charAt(i) == ray.charAt(j)) {
                    if (l == 2)
                        result[i][j] = l;
                    else if (result[i + 1][j - 1] > 0)
                        result[i][j] = l;
                }
                if (result[i][j] > max) {
                    max = result[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        return ray.substring(start, end + 1);
    }
}

public class labAssignment6B {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String ray = "nononsense";
        ray = solution.longestPalindrome(ray);
        System.out.println(ray);
    }
}