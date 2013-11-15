import java.util.*;
import java.lang.Math;
public class Seive {
	
	public static void main(String[] args){
		
	
	}
	
	public List<Integer> seive(int max){
		List<Integer> numbers = new LinkedList<Integer>();
		numbers.add(2);
		for (int i = 3; i <= max; i++){
			if(!(i % 2 == 0) ){
				numbers.add(i);
			}
		}
		
		List<Integer> primes = new LinkedList<Integer>();
		
		while(!numbers.isEmpty() && numbers.get(0) <= Math.sqrt(max)){
			int front = numbers.remove(0);
			primes.add(front);
			
			Iterator<Integer> iter = numbers.iterator();
			while(iter.hasNext()){
				int num = iter.next();
				if (num % front == 0){
					iter.remove();
				}
			}
		}
		return primes;
	}

}
