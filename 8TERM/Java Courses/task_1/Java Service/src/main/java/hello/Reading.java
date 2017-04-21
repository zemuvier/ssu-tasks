package hello;

import org.json.JSONObject;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Reading {
    public static JSONObject JsonObj(String name){
        File file = new File(name);
        StringBuilder stringJSON = new StringBuilder();
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNext()) {
                stringJSON.append(scanner.nextLine());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }


        JSONObject file_json = new JSONObject(stringJSON.toString());
        return file_json;
    }

    public static List<String> getCurrency(){
         List<String> currency = new ArrayList<String>();
        currency.add("Russia");
        currency.add("USA");
        currency.add("China");
        currency.add("Germany");
        currency.add("Australia");
        currency.add("France");
        currency.add("Japan");
        return currency;
        }
    public static List<String> getYears(){
        List<String> years = new ArrayList<String>();
        years.add("2015");
        years.add("2016");
        years.add("2017");
        return years;
    }

}
