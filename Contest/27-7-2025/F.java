import java.math.BigInteger;
import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            Long a = sc.nextLong();
            BigInteger aBig = BigInteger.valueOf(a);
            BigInteger b = sc.nextBigInteger();
            BigInteger gcd = aBig.gcd(b);
            System.out.println(gcd);
        }
        sc.close();
    }
}
