import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
 
class Graph {
	 private int vertex; 					// No. of vertices
	 private LinkedList<Integer> adj[];		// Adjacency List Representation
	 
   	 Graph(int v){
   		 vertex = v;
   		 adj = new LinkedList[vertex];
   		 for (int i = 0; i < v; ++i)
   			 adj[i] = new LinkedList();
   	 }
   	 
   	 public void addEdge(int u, int v) {
   		 adj[u].add(v);
   	 }
 
   	 // printing the adjacency list representation of graph
   	 public void printGraph(){
   		 for (int i = 0; i < adj.length; i++) {
   			 System.out.println("\nAdjacency list of vertex" + i);
   			 System.out.print("head");
   			 for (int j = 0; j < adj[i].size(); j++) {
   				 System.out.print(" -> " + adj[i].get(j));
   			 }
   			 System.out.println();
   		 }
   	 }

   	 public int numofVertex() {
   		 return vertex;
   	 }

   	 public int first(int i) {		//returning first adjacent node 
   		 if(adj[i].size()!=0)
   			 return adj[i].get(0);
   		 else
   			 return -1;
   	 }
    
   	 public String game(int die){					//operation
   		 int i=1,a,j,roll=0,test,no=0;
   		 String str="";
   		 test=adj[adj.length-2].peekLast();
   		 LinkedList<Integer> path = new LinkedList<Integer>();

   		 while(i<=adj.length-die){        	
   			 if(i>=adj.length-die){
   				 path.add(i);
   				 break;
   			 }
   			 else
   				 path.add(i);
    
   			 a=-1;
   			 for(j=0; j<adj[i].size(); j++){
   				 if	(first(adj[i].get(j)) > adj[i].get(j)+die){		//checking ladder
   					 path.add(adj[i].get(j));
   					 a=first(adj[i].get(j));
   					 break;
   				 }
   				 else if (first(adj[i].get(j)) < adj[i].get(j)) {	//checking snake
   					 no=no+1;
   					 if(no>10)
   						 break;
   					 continue;
   				 }
   				 else 
   					 a=adj[i].get(j);    
   			 }

   			 if(no>10) {						//No solution condition
   				 str=str+-1+"\nNo Solution\n";
   				 while(test>i) {
   					 i=i+1;
   					 str=str+i+" ";
   				 }
   				 str=str+"\n";
   				 return str;
   			 }

   			 if(a>-1) {		//general case
   				 i=a;
   				 roll++;
   			 }      
   		 }
   		 path.add(first(adj.length-2));
   		 str=str+roll+"\n";
    	
   		 while (path.size()>1) 
   			 str=str+path.poll()+"->";
    
   		 int p=path.pop();
   		 str=str+p+"\n"; 
   		 if(p==test)
   			 str=str+"All reachable\n";
   		 else {
   			 while(test>p) {
   				 p=p+1;
   				 str=str+p+" ";
   			 }
   			 str=str+"\n";
   		 }    
       
   		 return str;
   	 }
 
 
   	 // Main
   	 public static void main(String[] args) throws IOException {   	 
   		 int t, die, size, l, s, first, last;
   		 String str,st="";
   		 Graph board;

   		 BufferedReader file = new BufferedReader(new FileReader("D:\\EJAVA\\Graph\\src\\input.txt"));
   		 Scanner scn= new Scanner(file);
   		 t=Integer.parseInt(scn.nextLine());
   		 
   		 if (t>1 && t<=10) {
	   		 for(int i=0; i<t; i++){
	   			 str=scn.nextLine();
	   			 String[] tokens= str.split(" ");
	   			 die=Integer.parseInt(tokens[0]);
	   			 size=Integer.parseInt(tokens[1]);
	   			 
	   			 if((die<2 || die>16) || (size<2 || size>10000) )
	   				 break;
	   			 
	   			 board=new Graph(size+1);					//Graph
	
	   			 l=Integer.parseInt(scn.nextLine());		//ladder
	   			 if(l<1 || l>50)
	   				 break;
	   			 
	   			 for(int j=0; j<l; j++){
	   				 str=scn.nextLine();
	   				 tokens=str.split(" ");
	
	   				 first=Integer.parseInt(tokens[0]);
	   				 last=Integer.parseInt(tokens[1]);
	   				 board.addEdge(first,last);
	   			 }
	
	   			 s=Integer.parseInt(scn.nextLine());		//snake
	   			 if(s<1 || s>50)
	   				 break;
	   			 
	   			 for(int ii=0; ii<s; ii++){
	   				 str=scn.nextLine();
	   				 tokens=str.split(" ");
	
	   				 first=Integer.parseInt(tokens[0]);
	   				 last=Integer.parseInt(tokens[1]);
	   				 board.addEdge(first,last);
	   			 }
	
	   			 for(int k=1; k<board.numofVertex(); k++){
	   				 if(board.first(k)==-1){
	   					 for(int j =1; j<=die; j++){
	   						 if(k+j<board.numofVertex())
	   							 board.addEdge(k, k+j);
	   					 }
	   				 }
	   			 }
	   			 file.close();
	   			 st=st+board.game(die);
	   			 //board.printGraph();
	   		 }
	   		 FileWriter writer=new FileWriter("D:\\EJAVA\\Graph\\src\\output.txt");
	   		 writer.write(st);
	   		 writer.close();
   		 }
   	 }
	 }