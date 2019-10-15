package phaohoademo03;

import java.util.Random;

public class Helper {
    protected static Random ra = new Random();
    
    public static int GetRandomInt(int maxValueUpper) {
        return ra.nextInt(maxValueUpper);
    }
    
    
    public static int GetRandomInt(int minValue, int maxValueUpper) {
        return minValue + ra.nextInt(maxValueUpper - minValue);
    }
}
