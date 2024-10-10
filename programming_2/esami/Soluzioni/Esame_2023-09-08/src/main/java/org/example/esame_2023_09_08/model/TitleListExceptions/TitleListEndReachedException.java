package org.example.esame_2023_09_08.model.TitleListExceptions;

public class TitleListEndReachedException extends Exception {
    public TitleListEndReachedException() {
        super("You reached the end of the list");
    }
}
