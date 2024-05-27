package com.company;

import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class ClientApp extends Thread {
    private DatagramSocket socket;
    private DatagramPacket request, response;
    private InetAddress address;
    private int port;
    private ByteBuffer buffer;
    final int usernameSize = 16;
    final int messageSize = 128;
    private byte[] username, tmpUsername, message;

    public ClientApp(String host, int port, byte[] user) throws SocketException, UnknownHostException {
        address = InetAddress.getByName(host);
        this.port = port;
        socket = new DatagramSocket();
        socket.setSoTimeout(1000);
        buffer = ByteBuffer.allocate(usernameSize + messageSize);
        username = new byte[usernameSize];
        username = user;
        tmpUsername = new byte[usernameSize];
        message = new byte[messageSize];
    }

    public void run(){
        response = new DatagramPacket(buffer.array(), buffer.array().length);
        while(!Thread.interrupted()) {
            try {
                socket.receive(response);
                buffer = ByteBuffer.wrap(response.getData());
                buffer.get(tmpUsername);
                buffer.position(usernameSize);
                buffer.get(message);
                System.out.println(new String(tmpUsername) + " > " + new String(tmpUsername));
            } catch (IOException e) {
            }
        }
    }

    public void Send(byte[] message) throws IOException {
        buffer.put(username);
        buffer.position(usernameSize);
        buffer.put(message);
        buffer.position(messageSize);
        request = new DatagramPacket(buffer.array(), buffer.array().length, address, port);
        socket.send(request);
    }
}
