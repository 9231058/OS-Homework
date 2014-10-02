package home.parham.net;

import java.net.DatagramPacket;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Queue;

/**
 * Created by parham on 10/3/14.
 */
public class NetBuffer implements Queue<DatagramPacket> {

    private ArrayList<DatagramPacket> packets;

    @Override
    public int size() {
        return packets.size();
    }

    @Override
    public boolean isEmpty() {
        return packets.isEmpty();
    }

    @Override
    public boolean contains(Object o) {
        return packets.contains(o);
    }

    @Override
    public Iterator<DatagramPacket> iterator() {
        return packets.iterator();
    }

    @Override
    public Object[] toArray() {
        return packets.toArray();
    }

    @Override
    public <T> T[] toArray(T[] ts) {
        return packets.toArray(ts);
    }

    @Override
    public boolean add(DatagramPacket datagramPacket) {
        return packets.add(datagramPacket);
    }

    @Override
    public boolean remove(Object o) {
        return false;
    }

    @Override
    public boolean containsAll(Collection<?> objects) {
        return false;
    }

    @Override
    public boolean addAll(Collection<? extends DatagramPacket> datagramPackets) {
        return packets.addAll(datagramPackets);
    }

    @Override
    public boolean removeAll(Collection<?> objects) {
        return packets.removeAll(objects);
    }

    @Override
    public boolean retainAll(Collection<?> objects) {
        return packets.retainAll(objects);
    }

    @Override
    public void clear() {
        packets.clear();
    }

    @Override
    public boolean offer(DatagramPacket datagramPacket) {
        return false;
    }

    @Override
    public DatagramPacket remove() {
        return packets.remove(0);
    }

    @Override
    public DatagramPacket poll() {
        return null;
    }

    @Override
    public DatagramPacket element() {
        return null;
    }

    @Override
    public DatagramPacket peek() {
        return null;
    }
}
