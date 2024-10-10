module org.example.esame_20230718 {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.esame_20230718 to javafx.fxml;
    exports org.example.esame_20230718;
}