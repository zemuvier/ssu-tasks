package hello;

import javafx.application.Application;
import javafx.beans.binding.StringBinding;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import org.json.JSONObject;
import sun.net.www.http.HttpClient;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;


public class Charts extends Application {
    //private HttpClient client = HttpClientBuilder.create().build();
    private final int WIDTH = 800;
    private final String HOST = "localhost";
    private final String PORT = "8080";
    private final String REST_URL = "/rates";
    static JSONObject jsonObject = Reading.JsonObj("cash.json");
    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception{

        primaryStage.setTitle("JavaFX Chart (Series)");
        LineChart<Number, Number> lineChart = new LineChart<Number, Number>(new NumberAxis(2015,
                2017,1), new NumberAxis());
        ChoiceBox<String> cb_cur = new ChoiceBox<>(FXCollections.observableArrayList(getCurrencyList()));
        ChoiceBox<String> cb_year = new ChoiceBox<>(FXCollections.observableArrayList(getYearList()));
        Button showChart = new Button("Build");
        showChart.setOnAction(e -> {
            if (cb_cur.getValue() != null && cb_year.getValue() != null) {
                String value_cb_cur = cb_cur.getValue();
                String value_cb_year = cb_year.getValue();
                DrawChart(value_cb_cur, value_cb_year, lineChart);
            }
        });

        HBox hBox = new HBox();
        hBox.getChildren().addAll(cb_cur, cb_year,showChart);
        VBox vBox = new VBox();
        vBox.getChildren().addAll(hBox, lineChart);
        Scene scene = new Scene(vBox, 800,600);
        primaryStage.setScene(scene);

        primaryStage.show();
    }

    Set<String> getCurrencyList(){
        Set<String> res = new LinkedHashSet<String>();
        res.add("No choice");
        res.addAll(jsonObject.keySet());
        return res;
    }

    Set<String> getYearList(){
        Set<String> res = new LinkedHashSet<String>();
        res.add("No choice");
        res.addAll(jsonObject.getJSONObject("USA").keySet());
        return res;
    }
    void DrawChart(String val1, String val2, LineChart<Number, Number> lineChart) {
        lineChart.getData().clear();
        Set<String> cur = jsonObject.keySet();
        System.out.println(val1+"  "+val2);
        if (val1.equals("No choice")) {
            lineChart.setTitle("Population graph");
                for (String c : cur) {
                    XYChart.Series series = new XYChart.Series();
                    series.setName(c);
                    ObservableList<XYChart.Data> datas = FXCollections.observableArrayList();
                    if (val2.equals("No choice")) {
                        for (int i = 2015; i <= 2017; i++) {
                            datas.add(new XYChart.Data(i, Double.parseDouble(
                                    jsonObject.getJSONObject(c).getString(String.valueOf(i)))));
                        }
                    }
                    else {
                        datas.add(new XYChart.Data(Integer.parseInt(val2),
                                Double.parseDouble(jsonObject.getJSONObject(c).getString(val2))));
                    }
                    series.setData(datas);
                    lineChart.getData().add(series);
            }
        }
        else {
            lineChart.setTitle("Population graph " + val1);
            XYChart.Series series = new XYChart.Series();
            series.setName(val1);
            ObservableList<XYChart.Data> datas = FXCollections.observableArrayList();
            if (val2.equals("No choice")) {
                for (int i = 2015; i <= 2017; i++) {
                    datas.add(new XYChart.Data(i, Double.parseDouble(
                            jsonObject.getJSONObject(val1).getString(String.valueOf(i)))));
                }
            }
            else {
                datas.add(new XYChart.Data(Integer.parseInt(val2),
                        Double.parseDouble(jsonObject.getJSONObject(val1).getString(val2))));

            }
            series.setData(datas);
            lineChart.getData().add(series);
        }
    }
}


