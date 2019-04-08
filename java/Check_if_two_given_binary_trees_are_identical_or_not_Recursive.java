
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
		
		BT bt2=new BT(5);
		
		BT bt3=new BT(5);
		
		bt1.root.left = new Node(4);
		bt2.root.left = new Node(4);
		bt1.root.right = new Node(5);
		bt2.root.right = new Node(5);
		System.out.println(identical(bt1.root,bt2.root));
	}
	
	public static boolean identical(Node a, Node b){
		
		if(a == null && b == null){
			return true;
		}
		
		if(a != null && b != null) 
			return ((a.data == b.data) && identical(a.left, b.left) && identical(a.right, b.right));
		else
			return false;
	}
	
}
