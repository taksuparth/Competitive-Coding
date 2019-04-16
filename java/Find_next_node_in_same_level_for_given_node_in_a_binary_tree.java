
import java.util.*;
import java.lang.*;
import java.io.*;

class Node{
	int data;
	Node left, right;
	
	public Node(int key){
		data = key;
		left=null;
		right=null;
	}
}

class BT{
	Node root;
	static int maxLevel = 0; 
	
	BT(int key){
		root = new Node(key);
	}
	
	BT(){
		root = null;
	}
	
	public static void main(String[] args){
		BT bt1=new BT(5);
		bt1.root.left = new Node(4);
		bt1.root.left.left = new Node(8);
		bt1.root.right = new Node(5);
		bt1.root.right.left = new Node(6);
		Node ans = nextRight(bt1.root, 5);
		
	}
	
	public static Node nextRight(Node node, int k)  
    { 
        while(node == null){
        	return null;
        } 
        
        Queue<Node> queue1 = new LinkedList<Node>();
        Queue<Integer> queue2 = new LinkedList<Integer>();
        int level = 0;
        queue1.add(node);
        queue2.add(level);
        while (queue1.size()!= 0) {
        	Node temp = queue1.peek();
        	Integer top = queue2.peek();
        	queue1.remove();
        	queue2.remove();
        	
        	if(temp.data ==k){
        		if(queue2.size() ==0 || queue2.peek()!=level){
        			return null;
        		}
        		return queue1.peek();
        	}
        	
        	if(node.left!=null){
        		queue1.add(node.left);
        		queue2.add(level+1);
        	}
        	
        	if(node.right!=null){
        		queue1.add(node.right);
        		queue2.add(level+1);
        	}
        }
		return null;
    } 
	
}
