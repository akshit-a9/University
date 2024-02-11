import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.File;
import java.io.IOException;
import javax.sound.sampled.*;


public class PianoGUI extends JFrame implements KeyListener {

    private JButton pressedKeyButton = null;

    public PianoGUI() {
        super("Java Piano App");

        // Set up the piano keys
        JButton cButton = createPianoKey("C");
        JButton dButton = createPianoKey("D");
        JButton eButton = createPianoKey("E");
        JButton fButton = createPianoKey("F");
        JButton gButton = createPianoKey("G");
        JButton aButton = createPianoKey("A");
        JButton bButton = createPianoKey("B");
        setLayout(new GridLayout(1, 0));

        add(cButton);
        add(dButton);
        add(eButton);
        add(fButton);
        add(gButton);
        add(aButton);
        add(bButton);

        addKeyListener(this);
        setFocusable(true);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private JButton createPianoKey(String note) {
        JButton button = new JButton(note);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                playSound(note);
            }
        });

        return button;
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    @Override
    public void keyPressed(KeyEvent e) {
        char keyChar = e.getKeyChar();

        for (Component component : getContentPane().getComponents()) {
            if (component instanceof JButton) {
                JButton button = (JButton) component;
                if (button.getText().equalsIgnoreCase(String.valueOf(keyChar))) {
                    highlightKey(button);
                    playSound(button.getText());
                    return;
                }
            }
        }

        System.out.println("Invalid key: " + keyChar);
    }

    @Override
    public void keyReleased(KeyEvent e) {
        resetKeyAppearance();
    }

    private void highlightKey(JButton button) {
        resetKeyAppearance();
        pressedKeyButton = button;
        pressedKeyButton.setBackground(Color.YELLOW);
    }

    private void resetKeyAppearance() {
        if (pressedKeyButton != null) {
            pressedKeyButton.setBackground(null);
            pressedKeyButton = null;
        }
    }

    private void playSound(String note) {
        try {
            // Load the sound file dynamically based on the note
            File soundFile = new File("C:\\Users\\211200\\Desktop\\multimedia_piano_211200\\sound\\" + note + ".wav");
            
            // Check if the sound file exists
            if (!soundFile.exists()) {
                System.out.println("Sound file not found for note: " + note);
                return;
            }

            AudioInputStream audioIn = AudioSystem.getAudioInputStream(soundFile);

            // Get a Clip resource
            Clip clip = AudioSystem.getClip();

            // Open audio clip and load samples from the audio input stream
            clip.open(audioIn);

            // Start playing the sound
            clip.start();
        } catch (UnsupportedAudioFileException | IOException | LineUnavailableException ex) {
            ex.printStackTrace();
        }
    }


    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new PianoGUI();
            }
        });
    }
}