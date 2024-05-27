package com.company;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.nio.ByteBuffer;
import java.util.ArrayList;

public class Server extends Thread {
    DatagramSocket socket;
    DatagramPacket answer, request;
    ByteBuffer buffer;
    final int bufferSize = Character.BYTES * 128;
    ArrayList<Client> clients;

    public Server(int port) throws SocketException {
        socket = new DatagramSocket(port);
        buffer = ByteBuffer.allocate(bufferSize);
        clients = new ArrayList<>();
    }

    public void run() {
        request = new DatagramPacket(buffer.array(), buffer.array().length);
        boolean newClient;
        while(!Thread.interrupted()) {
            try {
                socket.receive(request);
                System.out.println("New packet received from: " + request.getAddress() + " " + request.getPort());

                newClient = true;
                for (Client client: clients) {
                    if(client.getAddress().equals(request.getAddress())){
                        if(client.getPort() == request.getPort())
                        {
                            newClient = false;
                            break;
                        }
                    }
                }

                if(newClient){
                    clients.add(new Client(request.getAddress(), request.getPort()));
                }

                System.out.println("Clients:");
                for (Client client: clients) {
                    System.out.println("# => " + client.getAddress() + " " + client.getPort());
                }

                for (Client client: clients) {
                    if(client.getAddress() != request.getAddress() && client.getPort() != request.getPort()){
                        answer = new DatagramPacket(request.getData(), request.getLength(), client.getAddress(), client.getPort());
                        socket.send(answer);
                        System.out.println("New packet sent to: " + client.getAddress() + " " + client.getPort());
                    }
                }
            } catch (IOException e) { }
        }
    }
}
