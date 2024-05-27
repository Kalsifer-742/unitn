package com.company;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String inputString;

        if (args.length == 1){
            if (args[0].equals("server")){
                System.out.print("Specify server port: ");
                inputString = scanner.nextLine();
                Server server = new Server(Integer.parseInt(inputString));
                server.start();
                System.out.println("Server started on port " + inputString + " ...");
            } else if (args[0].equals("client")){
                String serverAddress;

                System.out.print("Specify server address: ");
                inputString = scanner.nextLine();
                serverAddress = inputString;
                System.out.print("Specify server port: ");
                inputString = scanner.nextLine();

                ClientApp clientApp = new ClientApp(serverAddress, Integer.parseInt(inputString), "Bruco".getBytes(StandardCharsets.UTF_8));
                clientApp.start();
                System.out.println("Client started on address " + serverAddress + " & on port " + inputString + " ...");

                System.out.println("Insert message to send...");
                while (true) {
                    inputString = scanner.nextLine();
                    clientApp.Send(inputString.getBytes(StandardCharsets.UTF_8));
                }
            }
        }
        else{
            System.out.println("Error: missing or wrong argument. Mode must be specified: client | server");
        }
    }
}
