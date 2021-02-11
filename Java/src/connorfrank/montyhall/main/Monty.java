package connorfrank.montyhall.main;

import java.util.Random;

/** monty class */
public class Monty {

    static Random rand = new Random();

    /** door choice is not changed */
    public static int noChange(int trials) {
        int wins = 0;
        for (int i = 1; i <= trials; i++) {
            int prize = rand.nextInt(3);
            int choice = rand.nextInt(3);
            if (choice == prize) {
                wins++;
            }
        }
        return wins;
    }

    /** door choice is changed */
    public static int yesChange(int trials) {
        int wins = 0;
        for (int i = 1; i <= trials; i++) {
            int prize = rand.nextInt(3);
            int choice = rand.nextInt(3);
            int wrong = prize;
            while (wrong == prize || wrong == choice) {
                wrong = rand.nextInt(3);
            }
            int other = 3 - (choice + wrong);
            if (other == prize) {
                wins++;
            }
        }
        return wins;
    }

    /** compares the result of whether the subject decides to change their door choice */
    public void comparison(int trials) {
        int wins;

        System.out.println("door unchanged:");
        wins = noChange(trials);
        System.out.println("total wins out of " + trials + ": " + wins);
        System.out.println("percent win: " + (double) wins / trials * 100 + "%");

        System.out.println();
        System.out.println("door changed:");
        wins = yesChange(trials);
        System.out.println("total wins out of " + trials + ": " + wins);
        System.out.println("percent win: " + (double) wins / trials * 100 + "%");
    }
}
