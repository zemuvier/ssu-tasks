package hello;

import javafx.stage.Stage;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public abstract class Application {

    abstract void start(Stage primaryStage) throws Exception;

    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }

}
