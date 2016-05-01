import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BigInteger a=sc.nextBigInteger();
        BigInteger b=sc.nextBigInteger();
        System.out.println(a.multiply(b).divide(a.gcd(b)));
    }
}
