package connorfrank.craps.main;

import java.util.Random;

/** calculates number of craps wins */
public class Craps {

    static Random rand = new Random();

    /** main method - this is what's run */
    public static void main(String[] args) {
        int firstRoll = 0;
        int rollNumber = 0;
        int die1;
        int die2;
        int dice;
        boolean firstTrial = true;

        while (true) {
            System.out.println();
            System.out.println("roll number " + (++rollNumber)); // add one to roll number after printing
            die1 = rand.nextInt(6) + 1; // die 1 is random 1-6
            System.out.println("die 1: " + die1);
            die2 = rand.nextInt(6) + 1; // die 2 is random 1-6
            System.out.println("die 2: " + die2);
            dice = die1 + die2; // sum of dice
            System.out.println("sum: " + dice);

            if (firstTrial) { // what to do if the current roll is the first one
                if (dice == 7 || dice == 11) {
                    System.out.println("win");
                    break; // rolls 7 or 11 win
                }
                if (dice == 2 || dice == 3 || dice == 12) {
                    System.out.println("lose");
                    break; // rolls 2, 3, or 12 lose
                }
                firstRoll = dice; // store the value of the first role for later use
                firstTrial = false;
            } else {
                if (dice == 7) {
                    System.out.println("lose");
                    break; // roll of 7 loses after the first roll
                }
                if (dice == firstRoll) {
                    System.out.println("win");
                    break; // roll equal to the first one wins
                }
            }
        }
    }
}
