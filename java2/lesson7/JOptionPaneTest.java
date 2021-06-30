package lesson7;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.BevelBorder;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.border.LineBorder;

public class JOptionPaneTest implements ActionListener {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		JOptionPane.showMessageDialog(null,"URA!","Warning"
//				,JOptionPane.ERROR_MESSAGE);
//		if (JOptionPane.showConfirmDialog(null,"Message","COnfirm!!!!"
//				,JOptionPane.OK_CANCEL_OPTION) == JOptionPane.OK_OPTION) {
//			System.err.println("OK pressed");
//		}
//		else {
//			System.err.println("CANCEL pressed");
//		}
		JPanel		panel = new JPanel(new BorderLayout());
		JTextField	text = new JTextField();
		JLabel		label = new JLabel("<html><body><font color=red>Label</font></body></html>");
		JCheckBox	check = new JCheckBox();
		
		panel.setBorder(new CompoundBorder(new BevelBorder(BevelBorder.RAISED)
						,new LineBorder(Color.red)));
		
		text.setColumns(20);
		panel.add(label,BorderLayout.NORTH);
		panel.add(text,BorderLayout.CENTER);
		panel.add(check,BorderLayout.SOUTH);
	
		ActionListener	al = new JOptionPaneTest();
		
		check.setActionCommand("dfjhsdkjfhkjsdfh");
		check.addActionListener(al);
		text.setActionCommand("TEXTKKJKJKJK");
		text.addActionListener(al);
		
		
		label.setToolTipText("<html><body><font color=green>nazhmi menya</font></body></html>");
		JOptionPane.showMessageDialog(null,panel);
		System.err.println("Text: "+text.getText());
		
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.err.println("Checkbox pressed: "+e.getActionCommand());
	}

}
