module unitn.esame {
        requires javafx.controls;
        requires javafx.fxml;

    opens unitn.esame to javafx.fxml;
    exports unitn.esame;
}