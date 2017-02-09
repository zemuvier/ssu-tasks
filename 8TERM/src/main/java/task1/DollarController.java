package task1;

import java.util.concurrent.atomic.AtomicLong;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import task1.Parser;

@RestController
public class DollarController {

    private Parser mapValue = new Parser();

    @RequestMapping("/dollar")
    public Dollar dollar() {
        return new Dollar(mapValue.parse());
    }
}