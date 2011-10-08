import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeSet;


public class HuffmanEncode implements Runnable {
	
	//private String string;

	public HuffmanEncode(String string) {
//		this.string = string;
	}

	@Override
	public void run() {
		
	}
	
	public static PriorityQueue<Node> countCharacters(String target)
	{
		ArrayList<Node> characters = new ArrayList<Node>();
		
		boolean found = false;
		
		for (int i = 0; i<target.length(); i++)
		{
			found = false;
			for (int j = 0; j<characters.size() && !found; j++)
			{
				if (target.charAt(i) == characters.get(j).getKey())
				{
					characters.get(j).setProbability(characters.get(j).getProbability() + 1);
					found = true;
				}
			}
			
			if (!found)
				characters.add(new Node(target.charAt(i), 1));
		}

		Collections.sort(characters);
		
		PriorityQueue<Node> chars = new PriorityQueue<Node>(characters);
		
		return chars;
	}
	
	public static LinkedHashMap sortHashMapByValues(HashMap passedMap) {
	    List mapKeys = new ArrayList(passedMap.keySet());
	    List mapValues = new ArrayList(passedMap.values());
	    
	    Collections.sort(mapValues);
	    Collections.sort(mapKeys);
	        
	    LinkedHashMap sortedMap = 
	        new LinkedHashMap();
	    
	    Iterator valueIt = mapValues.iterator();
	    while (valueIt.hasNext()) {
	        Object val = valueIt.next();
	        Iterator keyIt = mapKeys.iterator();
	        
	        while (keyIt.hasNext()) {
	            Object key = keyIt.next();
	            String comp1 = passedMap.get(key).toString();
	            String comp2 = val.toString();
	            
	            if (comp1.equals(comp2)){
	                passedMap.remove(key);
	                mapKeys.remove(key);
	                sortedMap.put((String)key, (Integer)val);
	                break;
	            }

	        }

	    }
	    return sortedMap;
	}
	
	
	
	
}

