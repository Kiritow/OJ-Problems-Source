import java.util.*;
import java.math.*;
public class Main
{
public static void main(String[] args)
{
BigDecimal bg=new BigDecimal("1");
BigDecimal k=new BigDecimal("1");
BigInteger ss=new BigInteger("1");
BigInteger ddd=new BigInteger("1000000");
for(BigInteger i=new BigInteger("2");!i.equals(ddd);i=i.add(ss))
{
bg=bg.add(k.divide(new BigDecimal(i.multiply(i)),100,BigDecimal.ROUND_HALF_UP));
System.out.print(i);
System.out.print(" ");
System.out.print(bg);
System.out.println();
}
}
}
