public class Assignment3b {
    public static void main(String[] args)
    {
        if(args.length < 9)
            System.out.println("Not enough elements.");
        else
            if(args.length > 9)
                System.out.println("More than required elements.");
            else
            {
                int n = 3;
                int max = 0;
                int l = 0;
                int[][] ray = new int[n][n];
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        ray[i][j] = Integer.parseInt(args[l]);
                        l++;
                    }
                }
                System.out.println("The given array is: ");
                printArray(ray,n);

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        max = Math.max(max,ray[i][j]);
                    }
                }
                System.out.println("The greatest number in array is: "+max);
            }
    }
    public static void printArray(int[][] ray,int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(ray[i][j]+" ");
            }
            System.out.println("");
        }
    }
}