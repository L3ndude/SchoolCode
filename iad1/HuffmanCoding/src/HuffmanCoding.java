import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
//import java.util.concurrent.ExecutorService;
//import java.util.concurrent.Executors;
import java.util.PriorityQueue;


public class HuffmanCoding {

//	private static final int NTHREDS = 16;

	public static void main(String[] args) {
		
		PriorityQueue<Node> c = HuffmanEncode.countCharacters("Hallo, Ik ben Lennart. Wie ben jij?");
		
		Node one = null;
		Node two = null;
		Node total = null;
		
		while (c.size() > 1) {
			one = null;
			two = null;
			total = null;
					
			one = c.poll();
			two = c.poll();
			
			System.out.println(one.getProbability() + " plus " + two.getProbability() + " is " + (one.getProbability()+two.getProbability()));
			
			total = new Node(one, two, one.getProbability()+two.getProbability());
			
			c.add(total);
		}
		
		System.out.println("Root probability: "+c.peek().getProbability());
		/*
		Iterator<Node> iterator = c.iterator();
		 
		while (iterator.hasNext()) {
		   Node node = iterator.next();
		 
		   System.out.println(node.getKey() + " = " + node.getProbability());
		}
		*/
		
		
		/*
		ExecutorService executor = Executors.newFixedThreadPool(NTHREDS);
		for (int i = 0; i < 500; i++) {
			Runnable worker = new HuffmanEncode("ZOMG"+i);
			executor.execute(worker);
		}

		executor.shutdown();

		while (!executor.isTerminated()) {

		}
		System.out.println("Finished all threads");
		*/
	}

}