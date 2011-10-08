
public class Node implements Comparable {

	private Character key = null;
	private Integer probability = 0;
	
	private Node left = null;
	private Node right = null;
	
	public Node(Character character, Integer probability) {
		
		this.key = character;
		this.probability = probability;
		
	}
	
	public Node(Node left, Node right, Integer probability) {
		
		this.left = left;
		this.right = right;
		this.probability = probability;
		
	}
	
	public Node getLeft()
	{
		return this.left;
	}
	
	public Node getRight()
	{
		return this.right;
	}
	
	public Character getKey()
	{
		return this.key;
	}
	
	public Integer getProbability()
	{
		return this.probability;
	}

	public void setProbability(Integer probability)
	{
		this.probability = probability;
	}

	public int compareTo(Object otherNode) {
		
        if(!(otherNode instanceof Node)){
            throw new ClassCastException("Invalid object");
        }
        
        Integer otherProbability = ((Node) otherNode).getProbability();
        
        if(this.getProbability() > otherProbability)    
            return 1;
        else if ( this.getProbability() < otherProbability )
            return -1;
        else
            return 0;
	}
	
	public boolean isLeaf()
	{
		return (this.key==null)?false:true;
	}
	

}
