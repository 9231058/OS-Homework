package home.parham.net;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 * Created by parham on 10/3/14.
 */
public class Listener extends Thread {

    private DatagramSocket serverSocket;
    private NetBuffer buffer;

    public Listener() {
        buffer = new NetBuffer();
    }

    @Override
    public void run() {
        try {
            serverSocket = new DatagramSocket(1373);

            while (true) {
                DatagramPacket packet = null;
                serverSocket.receive(packet);
                buffer.add(packet);
            }

        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }
}
