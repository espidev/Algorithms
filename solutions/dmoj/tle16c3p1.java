import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Main {

	public static void main(String[] args) {
		java.util.Scanner scan = new java.util.Scanner(System.in);
		int num = scan.nextInt();
		HashMap<String, Integer> shit = new HashMap<>();
		
		for (int i = 0; i < num; i++){
			String word = scan.next();
			if (shit.containsKey(word))
				shit.put(word, shit.get(word) + 1);
			else
				shit.put(word, 1);
		}
		
		int cunt = 0;
		
		Iterator it = shit.entrySet().iterator();
	    while (it.hasNext()) {
	        Map.Entry pair = (Map.Entry)it.next();
	        if ((pair.getValue()).equals(new Integer(1))){
	        	cunt++;
	        }
	    }
	    
	    System.out.println(cunt);
	}

}
