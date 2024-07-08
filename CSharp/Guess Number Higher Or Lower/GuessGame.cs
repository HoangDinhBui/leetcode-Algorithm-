using System;

public class GuessGame
{
    private int pickedNumber;

    public GuessGame(int number)
    {
        pickedNumber = number;
    }

    // Mock guess API
    public int guess(int num)
    {
        if (num > pickedNumber)
            return -1;
        else if (num < pickedNumber)
            return 1;
        else
            return 0;
    }
}