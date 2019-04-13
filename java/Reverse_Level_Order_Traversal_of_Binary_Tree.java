
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
		reverseorder(bt1.root);
	}
	
	public static void reverseorder(Node node)  
    { 
        Stack<Node> stack = new Stack<>();
        Queue<Node> queue = new LinkedList<>();
        
        queue.add(node);
        while (queue.isEmpty() == false)  
        { 
            node = queue.peek(); 
            queue.remove(); 
            stack.push(node); 
   
            if (node.right != null) 
                queue.add(node.right);  
                  
            if (node.left != null) 
                queue.add(node.left); 
        } 
        
        while (stack.empty() == false)  
        { 
            node = stack.peek(); 
            System.out.println(node.data); 
            stack.pop(); 
        } 
    } 
	
}
