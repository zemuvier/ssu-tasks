package hello;

import org.json.JSONObject;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

public class ServerController {
    @RequestMapping (value = "/rating")
    public String greetingSubmit(@RequestParam(value="population", defaultValue="all") String population,
                                 @RequestParam(value="year", defaultValue="") String year) {
        List<String> words = Reading.getCurrency();
        List<String> years = Reading.getYears();
        JSONObject json_file = Reading.JsonObj("cash.json");
        String result = "";

        if (year.equals("") && population.equals("all")) {
            for (String p : words) {
                result += "Country: " + p + "<br>";
                for (String y : years) {
                    result += "&emsp;" + y + ": " + json_file.getJSONObject(p).getString(y) + "<br>";
                }
            }
        } else if (year.equals("")) {
            if (Reading.getCurrency().contains(population)) {
                result+="Country: "+population + "<br>";
                for (String y : years) {
                    result += "&emsp;" + y + ": " + json_file.getJSONObject(population).getString(y) + "<br>";
                }
            } else
                return "No such country";
        } else if (!year.equals("") && population.equals("all")) {
            if (years.contains(year)) {
                for (String cur : words) {
                    JSONObject value = json_file.getJSONObject(cur);
                    result += "Country: " + cur + "<br> &emsp;" + year + " year: " + value.getString(year) + "<br>";
                }
            } else return "No such year";
        } else {
            if (Reading.getCurrency().contains(population)) {
                if (years.contains(year))
                    result = population + ", " + year + ":  " + json_file.getJSONObject(population).getString(year);
                else result = "No result for this year";
            }
            else result = "No result for this country";

        }
        return result;
    }

}