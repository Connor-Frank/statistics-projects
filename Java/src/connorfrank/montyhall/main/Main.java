package connorfrank.montyhall.main;

import java.util.Scanner;

/** main class */
public class Main {

    static Monty monty = new Monty();
    static Scanner scanner = new Scanner(System.in);

    /** main method */
    public static void main(String[] args) {
        System.out.println("monty hall simulation");
        System.out.println("max trials scanner can handle is 1000000000");
        System.out.print("manual or auto? enter 0 for auto, enter number of trials for manual: ");
        int trials = scanner.nextInt();
        if (trials > 0) {
            monty.comparison(trials);
        } else if (trials == 0) {
            System.out.print("enter max number of trials (0 for recommended max of 1000000000): ");
            int maxTrials = scanner.nextInt();
            if (maxTrials == 0) {
                maxTrials = 1000000000;
            }
            for (int i = 10; i <= maxTrials; i *= 10) {
                System.out.println(i + " trials:");
                monty.comparison(i);
                if (i != maxTrials) {
                    System.out.println("\n");
                }
            }
        }
    }
}
