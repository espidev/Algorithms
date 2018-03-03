public class Main {
	public static void main(String[] args) {
		java.util.Scanner scan = new java.util.Scanner(System.in);
		String str = scan.nextLine();
		int upper = 0;
		int lower = 0;
		for(char ch : str.toCharArray()){
			if(ch == '1' || ch == '2' || ch == '3' || ch == '4'||ch == '5'||ch == 
'6'||ch == '7'||ch == '8'||ch == '9'||ch == '0'||ch==' '){
			    continue;
			}
			if(ch > 'Z'){
				lower++;
			}
			else{
				upper++;
			}
		}
		if(upper > lower){
			System.out.println(str.toUpperCase());
		}
		else if (lower > upper){
			System.out.println(str.toLowerCase());
		}
		else{
			System.out.println(str);
		}
	}

}
