import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int radix = in.nextInt();
        String s = in.next();
        StringBuffer s2 = new StringBuffer(s).reverse();
        int cnt = 0;
        long x = Long.valueOf(s, radix);
        while(!s2.toString().equals(s) && cnt <= 30){
            cnt++;
            x +=  Long.valueOf(s2.toString(), radix);
            s = Long.toString(x,radix);
            s2 = new StringBuffer(s).reverse();
        }
        if(cnt > 30){
            System.out.println("Impossible!");
        } else {
            System.out.println("STEP=" + cnt);
        }
        in.close();
    }
}
