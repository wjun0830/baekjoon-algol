import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		sc.nextLine();
		int flag = 0;
		List<Integer> stack = new ArrayList<>();
		for(int i = 0; i<a; i++) {
			String str = sc.nextLine();
			String[] arr = str.split(" ");
			if(arr[0].equals("top")) {
				flag = top(stack,flag);
			}
			else if(arr[0].equals("pop"))
				flag = pop(stack,flag);
			else if(arr[0].equals("size"))
				flag = size(stack,flag);
			else if(arr[0].equals("empty"))
				flag = empty(stack,flag);
			else if(arr[0].equals("push"))
				flag = push(stack,flag,Integer.parseInt(arr[1]));
		}
		
		
		sc.close();
	}

	
	public static int push(List<Integer> stack, int flag, int value) {
		stack.add(value);
		flag++;
		return flag;
	}
	
	public static int pop(List<Integer> stack, int flag) {
		if(flag == 0)
			System.out.println("-1");
		else {
			System.out.println(stack.get(flag-1));
			stack.remove(flag-1);
			flag--;
		}
		return flag;
	}
	
	public static int size(List<Integer> stack, int flag) {
		System.out.println(flag);
		return flag;
	}
	
	public static int empty(List<Integer> stack, int flag) {
		if(flag == 0)
			System.out.println("1");
		else
			System.out.println("0");
		return flag;
	}
	
	public static int top(List<Integer> stack, int flag) {
		if(flag == 0)
			System.out.println("-1");
		else
			System.out.println(stack.get(flag-1));
		return flag;
	}
	
}

