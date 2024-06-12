module org.example.esame_20230617 {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.esame_20230617 to javafx.fxml;
    exports org.example.esame_20230617;
}