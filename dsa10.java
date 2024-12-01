import java.util.Scanner; 
 
public class dsa10 
{ 
 
 static void print(int arr[]) 
 { 
  int n=arr.length; 
  for(int i=0;i<n;i++) 
  { 
   System.out.print(arr[i]+" "); 
  } 
  System.out.println(); 
 } 
  
 static void shell(int arr[]) 
 { 
  int n=arr.length;  
  for(int gap=n/2;gap>0;gap/=2) 
   for(int i=gap;i<n;i+=1) 
   { 
    int temp=arr[i]; 
    int j; 
    for(j=i;j>=gap && arr[j-gap]>temp;j-=gap) 
     arr[j]=arr[j-gap]; 
    arr[j]=temp; 
   } 
 } 
 static void input(int arr[],int n) 
 { 
  //int n=arr.length; 
  Scanner sc=new Scanner(System.in); 
  for(int i=0;i<n;i++) 
   arr[i]=sc.nextInt(); 
 } 
 public static void main(String arg[]) 
 { 
 
  //int arr[]={10,30,50,60,20,40,80,70}; 
  //int n=arr.length; 
  int arr[] = new int[8]; 
  int n=arr.length; 
  System.out.println("Enter the values of array:"); 
  input(arr,n); 
  System.out.println("Array before sorting:"); 
  print(arr); 
  shell(arr); 
  System.out.println("Array after sorting:"); 
  print(arr); 
   
   
 } 
 
} 
