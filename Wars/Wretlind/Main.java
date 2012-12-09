import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {
	static double[][] connMat;
	public static void loadGraphMatrix(String filename){
		try{
			Scanner scan = new Scanner(new FileReader(filename));
			int numOfVerts = Integer.parseInt(scan.nextLine());
			connMat = new double[numOfVerts][numOfVerts];
			for(int i = 0; i < numOfVerts; i++){
				for(int j = 0; j < numOfVerts; j++){
					connMat[i][j] = scan.nextDouble();
				}
			}
			scan.close();
		} catch(Exception e){
			e.printStackTrace();
		}
	}	
	public static int solve(int populationSize, int generations, double chanceOfMutation){
		loadGraphMatrix("Graph1.txt");
		int i = 0;
		List<Integer> nodes = new ArrayList<Integer>();
		for(double[] d: connMat){
			nodes.add(i);
			i++;
		}
		i = 0;
		List<ArrayList<Integer>> possible = new ArrayList<ArrayList<Integer>>();
		for(i = 0; i < populationSize; i++){
			Collections.shuffle(nodes);
			possible.add(new ArrayList<Integer>(nodes));
		}
		i = 0;
		List<Integer> prevLowestCost = new ArrayList<Integer>();
		List<Integer> currentLowestCost = new ArrayList<Integer>();
		int convergence = 0;
		Random r = new Random();
		for(i = 0; i < generations; i++){
			r.setSeed(System.currentTimeMillis());
			int lowestCost = pathCost(possible.get(0));	
			currentLowestCost = possible.get(0);
			for(List<Integer> pathToCheck: possible){
				int currentCost = pathCost(pathToCheck);
				if(currentCost < lowestCost){
					currentLowestCost = pathToCheck;
					lowestCost = currentCost;
				}
			}
			List<ArrayList<Integer>> buffer = new ArrayList<ArrayList<Integer>>(possible);
			int j = 0;
			int k = 0;
			for(List<Integer> currentMate: buffer){
				j = 0;
				if(!(currentMate.equals(currentLowestCost))){
					for(int node: currentMate){
						if(r.nextInt((int)(chanceOfMutation*100)) > 10){
							int indexToSwapWith = r.nextInt((j==0)?1:currentMate.size());
							int currentIndex = possible.get(possible.indexOf(currentMate)).indexOf(node);
							Collections.swap(possible.get(possible.indexOf(currentMate)), currentIndex, indexToSwapWith);
						}
						else{
							Collections.reverse(possible.get(buffer.indexOf(currentMate)));
							Collections.swap(possible.get(buffer.indexOf(currentMate)), possible.get(possible.indexOf(currentMate)).indexOf(node), possible.get(possible.indexOf(currentLowestCost)).indexOf(node));
						}
						j++;
					}
				}
				k++;
			}
			if(currentLowestCost.equals(prevLowestCost)){
				convergence++;
			} else{
				convergence = 0;
			}
			System.out.println(i + " " + convergence + " " + lowestCost);
			prevLowestCost = currentLowestCost;
		}
		System.out.println(currentLowestCost);
		System.out.println(pathCost(currentLowestCost));
		System.out.println(possible);
		return pathCost(currentLowestCost);
	}
	public static int pathCost(List vector){
		int cost = 0;
		for(int i = 0; i < connMat.length; ++i){
			for(int j = i + 1; j < connMat.length; ++j){
	            cost += cost(vector, i, j) * connMat[i][j];        
			}
		}
		return cost;
	}
	public static int cost(List path, int i1, int i2){
		if(path.lastIndexOf(i1) == path.size() || path.lastIndexOf(i2) == path.size() ){
			return 0;
		} else{
			return Math.abs(path.indexOf(i1) - path.indexOf(i2));
		}
	}
	public static void main(String[] args) {
		long t1 = System.currentTimeMillis();
		solve(1000,10000,.25);
		long t2 = System.currentTimeMillis();
		System.out.println((t2-t1) + " Miliseconds or " + (double)((t2-t1)/1000.0) + " Seconds");
	}
}