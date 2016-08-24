import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BigInteger a=BigInteger.ZERO;
        BigInteger b=new BigInteger("1");
        int t;
        t=sc.nextInt();
        for(int s=0; s<t; s++)
        {
            a=sc.nextBigInteger();
            a=a.subtract(b);
            System.out.println(a);
        }
    }
}
