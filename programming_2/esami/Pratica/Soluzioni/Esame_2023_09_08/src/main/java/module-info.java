module org.example.esame_2023_09_08 {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.esame_2023_09_08 to javafx.fxml;
    exports org.example.esame_2023_09_08;
}