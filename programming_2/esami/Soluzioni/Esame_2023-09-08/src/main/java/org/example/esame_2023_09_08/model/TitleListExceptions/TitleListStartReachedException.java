package org.example.esame_2023_09_08.model.TitleListExceptions;

public class TitleListStartReachedException extends Exception {
    public TitleListStartReachedException() {
        super("You reached the start of the list");
    }
}
