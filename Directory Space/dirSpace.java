//About
//Simple java program to calculate the size of a directory and all subdirectories using recursion

// Importing File Class
import java.io.File;

// class
public class dirSpace {

    // recursive function 
    public static long getSize(File dir) {
        // variable
        long tempSum = 0;

        // if is a file, add to sum
        if (dir.isFile()) {
            tempSum += dir.length();

        // if is a directory, recurse
        } else if (dir.isDirectory()) {
            
            File[] files = dir.listFiles();
            if (files != null) {
                for (File file : files) {
                    tempSum += getSize(file);
                }
            }
        }

        return tempSum;
    }

    public static void main(String[] args) {

        File file = new File(".");
        long size = getSize(file);
        System.out.println(size);

    }
}