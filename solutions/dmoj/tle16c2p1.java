public class Main {

	public static void main(String[] args) {
		java.util.Scanner scan = new java.util.Scanner(System.in);
		int nom = scan.nextInt();
		int num = 0;
		int cache = 0;
		int cache1 = 0;
		for(int i = 0; i < nom; i++){
			String input = scan.next();
			if(input.equals("borrow")){
				num -= scan.nextInt();
			}
			else if(input.equals("return")){
				num += scan.nextInt();
			}
			if (num < cache1){
				cache = i + 1;
				cache1 = num;
			}
		}
		System.out.println(cache);
	}

}
