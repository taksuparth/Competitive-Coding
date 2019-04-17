
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
		bt1.root.right = new Node(5);
		bt1.root.right.left = new Node(6);
		postorder(bt1.root);
	}
	
	public static void postorder(Node node)  
    { 
        if(node == null){
        	return;
        }
        
        postorder(node.left);
        postorder(node.right);
        System.out.println(node.data);
    } 
	
}
