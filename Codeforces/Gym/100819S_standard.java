import java.util.*;
public class Surf {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		State[] list = new State[n];
		for(int i = 0; i < n; i++) {
			list[i] = new State(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(list);
		int[] dp = new int[2000001];
		int index = 0;
		for(int i = 0; i < dp.length-1; i++) {
			while(index < n && list[index].m == i) {
				dp[i+list[index].w] = Math.max(dp[i+list[index].w], dp[i] + list[index].f);
				index++;
			}
			dp[i+1] = Math.max(dp[i+1], dp[i]);
		}
		System.out.println(dp[2000000]);
	}
	static class State implements Comparable<State> {
		public int m,f,w;
		public State(int a, int b, int c){
			m=a;
			f=b;
			w=c;
		}
		public int compareTo(State s) {
			return m - s.m;
		}
	}
}
