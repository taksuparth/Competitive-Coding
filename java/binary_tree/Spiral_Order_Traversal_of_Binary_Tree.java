
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
		spiralorder(bt1.root);
	}
	
	public static void spiralorder(Node node)  
    { 
        Stack<Node> stack1 = new Stack<>();
        Stack<Node> stack2 = new Stack<>();
        
        stack1.push(node);
        while(!stack1.empty() || !stack2.empty()){
        
        	while(!stack1.empty()){
        		
        	Node toBeProcessed = stack1.pop();
        	System.out.println(toBeProcessed.data);
        	
        		if(toBeProcessed.right !=null){
        		stack2.add(toBeProcessed.left);
	        	}
	        	if(toBeProcessed.left !=null){
	        		stack2.add(toBeProcessed.right);
	        	}
        	}
        	
        	while(!stack2.empty()){
        		Node toBeProcessed = stack2.pop();
        		System.out.println(toBeProcessed.data);
        	
        		if(toBeProcessed.left !=null){
        		stack1.add(toBeProcessed.left);
	        	}
	        	if(toBeProcessed.right !=null){
	        		stack1.add(toBeProcessed.right);
	        	}
        	}
        	
        }
    } 
	
}
