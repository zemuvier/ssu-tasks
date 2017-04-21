package hello;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModelProperty;


public class Population {
    private final String country;
    private final String year;
    private final String value;

    public Population(String country, String year, String value) {
        this.country = country;
        this.year = year;
        this.value = value;
    }



    @JsonProperty(required = true)
    @ApiModelProperty(notes = "rates", required = true)
    public String getCountry() {
        return country;
    }
    public String getYear() {
        return year;
    }
    public String getValue() {
        return value;
    }
}
