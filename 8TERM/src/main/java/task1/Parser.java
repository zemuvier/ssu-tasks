package task1;

import java.util.Scanner;
import java.util.Map;
import java.io.FileReader;
import java.util.LinkedHashMap;
import org.codehaus.jackson.map.ObjectMapper;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.*;


public class Parser {

//   private Scanner scanner = new Scanner(new FileReader("/Users/alina/Documents/ssu-tasks/8TERM/data/dollars.txt"));

    private Scanner myMethod() {

        try {
            Scanner scanner = new Scanner(new FileReader("/Users/alina/Documents/ssu-tasks/8TERM/data/dollars.txt"));
            return scanner;
        } catch(FileNotFoundException fnfe) {
            System.out.println(fnfe.getMessage());
        }
        return scanner;
    }

    private Scanner scanner = myMethod();


    private Map<String, String> personMap = new LinkedHashMap<String, String>();
//    private String json = new ObjectMapper();

    private String line;
    private boolean person = false;


    public String parse() {
        while (scanner.hasNext()) {
            line = scanner.next();
            if (line.startsWith("#") && !line.isEmpty()) {
                line = scanner.next();
                System.out.println(line);
                person = true;
            }

            if (person) {
                if (!line.startsWith("#") && !line.isEmpty()) {
                    String[] columns = line.split(" ");
                    for (String str : columns) {
                        System.out.println(str);
                    }
                    personMap.put(columns[0], columns[1]);
                }
            }
        }
        String string = personMap.toString();
        return string;
    }
}

