import java.lang.Math;
import java.util.*;
import java.io.*;

public class dccnlab2A {

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        int[] data, div, divisor, rem, crc;
        int data_bits, divisor_bits, tot_length;

        System.out.print("Enter number of data bits: ");
        data_bits = scan.nextInt();
        data = new int[data_bits];

        System.out.print("Enter data bits: ");
        for (int i = 0; i < data_bits; i++)
            data[i] = scan.nextInt();

        System.out.print("\nEnter number of bits in divisor: ");
        divisor_bits = scan.nextInt();
        divisor = new int[divisor_bits];

        System.out.print("Enter divisor bits: ");
        for (int i = 0; i < divisor_bits; i++)
            divisor[i] = scan.nextInt();

        tot_length = data_bits + divisor_bits - 1;

        div = new int[tot_length];
        rem = new int[tot_length];
        crc = new int[tot_length];

        for (int i = 0; i < data.length; i++)
            div[i] = data[i];

        System.out.print("\nDividend(after appending 0's) are: ");
        for (int i = 0; i < div.length; i++)
            System.out.print(div[i] + " ");
        System.out.println();

        for (int j = 0; j < div.length; j++) {
            rem[j] = div[j];
        }

        rem = divide(div, divisor, rem);

        for (int i = 0; i < div.length; i++) {
            crc[i] = (div[i] ^ rem[i]);
        }

        System.out.print("CRC code: ");
        for (int i = 0; i < crc.length; i++)
            System.out.print(crc[i] + " ");

        System.out.print("\n\nEnter CRC code of " + tot_length + " bits: ");
        for (int i = 0; i < crc.length; i++)
            crc[i] = scan.nextInt();

        System.out.print("\nCRC bits are: ");
        for (int i = 0; i < crc.length; i++)
            System.out.print(crc[i] + " ");
        System.out.println("\n");

        for (int j = 0; j < crc.length; j++) {
            rem[j] = crc[j];
        }
        rem = divide(crc, divisor, rem);
        for (int i = 0; i < rem.length; i++) {
            if (rem[i] != 0) {
                System.out.println("ERROR\n");
                break;
            }
            if (i == rem.length - 1)
                System.out.println("NO ERROR\n");
        }
    }

    static int[] divide(int div[], int divisor[], int rem[]) {
        int cur = 0;
        while (true) {
            for (int i = 0; i < divisor.length; i++)
                rem[cur + i] = (rem[cur + i] ^ divisor[i]);
            while (rem[cur] == 0 && cur != rem.length - 1)
                cur++;
            if ((rem.length - cur) < divisor.length)
                break;
        }
        return rem;
    }
}