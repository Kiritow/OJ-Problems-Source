import java.util.Scanner;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner=new Scanner(System.in);
		BigDecimal a,b;
		while(scanner.hasNextBigDecimal()){
			a=scanner.nextBigDecimal();
			b=scanner.nextBigDecimal();
			a=a.add(b);
			String s=a.stripTrailingZeros().toPlainString();
			System.out.println(s);
		}
	}

}
