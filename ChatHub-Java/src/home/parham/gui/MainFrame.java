package home.parham.gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by parham on 10/3/14.
 */
public class MainFrame {
    private JTextPane inputPanel;
    private JTextPane outputPanel;
    private JButton sendButton;
    private JButton exitButton;

    public MainFrame() {
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {

            }
        });
    }

}
