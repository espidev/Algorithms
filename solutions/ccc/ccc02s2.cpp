public class Main {

	public static void main(String[] args) {
		java.util.Scanner scan = new java.util.Scanner(System.in);
		int numerator = scan.nextInt(), denominator = scan.nextInt();
		for(int i = 2; i < numerator; i++){
			if(numerator % i == 0 && denominator % i == 0){
				numerator = numerator / i;
				denominator /= i;
				i = 2;
			}
		}
		if(numerator == 0 || denominator == 0){
			System.out.println("0");
		}
		else{
			if(numerator > denominator){
				if(numerator%denominator == 0){
					System.out.println((int)numerator/denominator);
				}
				else{
					System.out.println((int)Math.floor(numerator/denominator) 
+ " " + (int)(numerator - Math.floor(numerator/denominator) * denominator) + "/" + denominator);
				}
			}
			else{
				System.out.println(numerator + "/" + denominator);
			}
		}
	}

}
