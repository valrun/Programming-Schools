
package javaapplication;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import javax.swing.JColorChooser;
import javax.swing.JEditorPane;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.border.LineBorder;

public class JavaApplication {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        final JFrame    f = new JFrame("Caption");
        final Dimension scr = Toolkit.getDefaultToolkit()
                .getScreenSize();
        
        f.setSize(new Dimension(scr.width*3/4,scr.height*3/4));
        f.setMinimumSize(new Dimension(100,100));
        f.setMaximumSize(new Dimension(800,600));  
        f.setLocation(scr.width/8,scr.height/8);

        JMenuItem   item1 = new JMenuItem("ITEM 1");
        JMenuItem   item2 = new JMenuItem("ITEM 2");
        JMenu       submenu = new JMenu("Submenu");
        JMenuBar    bar = new JMenuBar();
        
        submenu.add(item1);
        submenu.add(new JSeparator());
        submenu.add(item2);
        bar.add(submenu);
        f.getContentPane().add(bar,BorderLayout.NORTH);
        
        item1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser    fc = new JFileChooser();
                
                if (fc.showOpenDialog(f) == JFileChooser.APPROVE_OPTION) {
                    System.err.println("Selected: "+fc.getSelectedFile());
                }
                else {
                    System.err.println("CAncelled....");
                }
            }
        });

        item2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                JColorChooser.showDialog(f,"Choose color", Color.yellow);
                
                
                
            }
        });
        
        JPanel  stateString = new JPanel(
                new FlowLayout(FlowLayout.LEFT));
        JLabel  state = new JLabel("READY!");
        
        stateString.add(state);
        stateString.setBorder(new LineBorder(Color.RED));
        
        f.getContentPane().add(stateString,BorderLayout.SOUTH);
        
        JSplitPane  split = new JSplitPane();
        
        JTabbedPane tab = new JTabbedPane();
        
        JTable      table = new JTable(
                new String[][]{
                new String[]{"line 1.1", "line 1.2"}, 
                new String[]{"line 2.1","line 2.2"}
                },
                new String[]{"head1","head2"});
        JScrollPane pane = new JScrollPane(table);
        
        tab.addTab("first",pane);
        tab.addTab("second",new JLabel("SECOND"));
        
        JEditorPane editor = new JEditorPane();
        //JTextArea
        
        split.setLeftComponent(editor);
        split.setRightComponent(tab);
        f.getContentPane().add(split,BorderLayout.CENTER);
        
        f.pack();
        
        f.setVisible(true);        
    }
    
}
