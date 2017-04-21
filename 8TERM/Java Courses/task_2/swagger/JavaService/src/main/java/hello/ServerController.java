package hello;

import io.swagger.annotations.*;
import org.json.JSONObject;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicLong;

@RestController
@Api( value = "/service", description = "Counrties Rates" )
public class ServerController {
    @ApiOperation(value = "getRates")
    @RequestMapping(method = RequestMethod.GET, path="/rates", produces = "application/json")
    @ApiImplicitParams({
            @ApiImplicitParam(name = "country", value = "country", required = false, dataType = "string",
                    paramType = "query", defaultValue="all"),
            @ApiImplicitParam(name = "year", value = "year", required = false, dataType = "string",
                    paramType = "query", defaultValue="")
    })
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "Success", response = Population.class),
            @ApiResponse(code = 401, message = "Unauthorized"),
            @ApiResponse(code = 403, message = "Forbidden"),
            @ApiResponse(code = 404, message = "Not Found"),
            @ApiResponse(code = 500, message = "Failure")})
    public List<Population> greetingSubmit(@RequestParam(value="country", defaultValue="all") String country,
                                           @RequestParam(value="year", defaultValue="") String year) {
        List<String> words = Reading.getCurrency();
        List<String> years = Reading.getYears();
        JSONObject json_file = Reading.JsonObj("cash.json");
        List<Population> countries = new ArrayList<Population>();

        if (year.equals("") && country.equals("all")) {
            for (String elem : words) {
                for (String y : years) {
                    countries.add(new Population(elem,y,json_file.getJSONObject(elem).getString(y)));
                }
            }
        } else if (year.equals("")) {
            if (Reading.getCurrency().contains(country)) {
                for (String y : years) {
                    countries.add(new Population(country,y,json_file.getJSONObject(country).getString(y)));
                }
            }
        } else if (!year.equals("") && country.equals("all")) {
            if (years.contains(year)) {
                for (String cur : words) {
                    JSONObject value = json_file.getJSONObject(cur);
                    countries.add(new Population(cur,year,value.getString(year)));
                }
            }
        } else {
            if (Reading.getCurrency().contains(country)) {
                if (years.contains(year))
                    countries.add(new Population(country,year,json_file.getJSONObject(country).getString(year)));
            }
        }
        return countries;
    }
}
