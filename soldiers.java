import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger a,b,m,n;
		int t; BigInteger two = new BigInteger("2");
		BigInteger zero = new BigInteger("0");
		Scanner s = new Scanner(System.in);
		t = Integer.parseInt(s.nextLine());
		while(t-- > 0) {
			String[] in = s.nextLine().split(" ");
			a = new BigInteger(in[0]);
			b = new BigInteger(in[1]);
			if(a.divideAndRemainder(two)[1] == zero) 
				m = a.divide(two);
			else
				m = (a.add(BigInteger.ONE)).divide(two);
			if(b.divideAndRemainder(two)[1] == zero) 
				n = b.divide(two);
			else
				n = (b.add(BigInteger.ONE)).divide(two);
			a = a.multiply(n);
			b = b.multiply(m);
			if( a.compareTo(b) == 1)
				System.out.println(a);
			else
				System.out.println(b);
		}
	}
}
