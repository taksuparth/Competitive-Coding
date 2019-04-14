
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
		leftView(bt1.root, 1);
	}
	
	public static void leftView(Node node, int level)  
    { 
        while(node == null){
        	return;
        } 
        
        if(level > maxLevel){
        	System.out.println(node.data);
        	maxLevel = level;
        }
        
        leftView(node.left, level+1);
        leftView(node.right, level+1);
    } 
	
}
