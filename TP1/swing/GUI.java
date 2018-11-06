/*!
 * \file
 * \brief  GUI class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.border.*;


public class GUI extends JFrame {
	private static final long serialVersionUID = 1L;
	
	private JMenuBar menuBar = new JMenuBar();
	private JMenu menu = new JMenu("Menu");
	private JToolBar toolBar = new JToolBar();
	private JTextArea txtA = new JTextArea(30,30);
	private PlayAction play = new PlayAction();
	private SearchAction search = new SearchAction();
	private AllAction all = new AllAction();
	private DelItemAction delItem = new DelItemAction();
	private DelGroupAction delGroup = new DelGroupAction();
	private ExitAction exit = new ExitAction();
	private JTextField txtName;
	private MediaClient client = null;


	
	public GUI() {
		
//		 Set dimensions 
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 500, 500);
		getContentPane().setLayout(new BorderLayout(0, 0));
		
//		Set text area default text and assign it to the GUI 
		txtA.setText("");
		getContentPane().add(txtA, BorderLayout.CENTER);
		
		JScrollPane sp = new JScrollPane(txtA,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    getContentPane().add(sp);
		
//	 	Buttons
        
		JLabel lbPlay = new JLabel("Play");
		JButton bttnPlay = new JButton();
		bttnPlay.add(lbPlay);
		bttnPlay.addActionListener(play);
		
		JLabel labBttn2 = new JLabel("Search");
		JButton bttnSearch = new JButton();
		bttnSearch.add(labBttn2);
		bttnSearch.addActionListener(search);
		
		JLabel labExit = new JLabel("EXIT");
		JButton bttnExit = new JButton();
		bttnExit.add(labExit);
		bttnExit.addActionListener(exit);
		
		JLabel labAll = new JLabel("All");
		JButton bttnAll = new JButton();
		bttnAll.add(labAll);
		bttnAll.addActionListener(all);
		
		JLabel labDelM = new JLabel("Del Mult");
		JButton bttnDelM = new JButton();
		bttnDelM.add(labDelM);
		bttnDelM.addActionListener(delItem);
		
		JLabel labDelG = new JLabel("Del Group");
		JButton bttnDelG = new JButton();
		bttnDelG.add(labDelG);
		bttnDelG.addActionListener(delGroup);
		
		
		
		
		
		
		
		sp.setColumnHeaderView(toolBar);

		toolBar.add(bttnPlay);
	    toolBar.add(bttnSearch);
	    toolBar.add(bttnAll);
	    toolBar.add(bttnDelG);
	    toolBar.add(bttnDelM);
	    toolBar.add(bttnExit);
	    
	    JPanel panel = new JPanel();
	    getContentPane().add(panel, BorderLayout.SOUTH);
	    panel.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
	    
	    JLabel lblName = new JLabel("Name");
	    panel.add(lblName);
	    
	    txtName = new JTextField("");
	    txtName.setText("Name");
	    panel.add(txtName);
	    txtName.setColumns(10);
                    
//  	Menu
        
        JMenuItem playMenu = new JMenuItem(play);
        playMenu.setText("Play");
        JMenuItem searchMenu = new JMenuItem(search);
        searchMenu.setText("Search");
        JMenuItem exitMenu = new JMenuItem(exit);
        exitMenu.setText("EXIT");
        JMenuItem allMenu = new JMenuItem(all);
        allMenu.setText("All");
        JMenuItem delMultMenu = new JMenuItem(delItem);
        delMultMenu.setText("Delete mul");
        JMenuItem delGroupMenu = new JMenuItem(delGroup);
        delGroupMenu.setText("Delete group");
        menu.add(playMenu);
        menu.add(searchMenu);
        menu.add(allMenu);
        menu.add(delMultMenu);
        menu.add(delGroupMenu);
        menu.add(exitMenu);
        
        menuBar.add(menu);
        this.setJMenuBar(menuBar);
        
        
		
		pack();
		this.tryToConnect();
		setVisible(true);

	}
	
	
	public final void tryToConnect(){
		try {
	      client = new MediaClient(MediaClient.DEFAULT_HOST, MediaClient.DEFAULT_PORT);
	      System.out.println("Client connected to server at "+ MediaClient.DEFAULT_HOST+":"+ MediaClient.DEFAULT_PORT );
	      txtA.append("\nClient connected to server at "+ MediaClient.DEFAULT_HOST+":"+ MediaClient.DEFAULT_PORT);
	      txtA.append("\nType the name of the file you want to search, play or delete.");
	      txtA.append("\nPress the 'All' button to show all the database");
	      


	    }
	    catch (Exception e1) {
	      System.err.println("Client couldn't connect to "+MediaClient.DEFAULT_HOST+":"+MediaClient.DEFAULT_PORT);
	      txtA.append("\n"  + "Client couldn't connect to "+MediaClient.DEFAULT_HOST+":"+MediaClient.DEFAULT_PORT);
	    }
	}
	
	class PlayAction extends AbstractAction {
	    public PlayAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	String name = txtName.getText();
	    	txtName.setText("");
	    	if ( name != "" && client != null && !name.trim().isEmpty() ) {
				txtA.append("\nRequest: PLAY?" +name);
				String response = client.query("PLAY?" +name);
				if(response == null) {tryToConnect();}
				txtA.append("\nResponse: "  + response);
			} else {
				txtA.append("\nNot a valid name.");
			}
	    	
	    }
	 }
	
	class SearchAction extends AbstractAction {
	    public SearchAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	String name = txtName.getText();
	    	txtName.setText("");
	    	if ( name != "" && client != null && !name.trim().isEmpty() ) {
				txtA.append("\nRequest: SEARCH?" +name);
				String response = client.query("SEARCH?" +name);
				if(response == null) {tryToConnect();}
				txtA.append("\nResponse: "  + response);
			} else {
				txtA.append("\nNot a valid name.");
			}
	    }
	 }
	
	class AllAction extends AbstractAction {
	    public AllAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	txtName.setText("");
	    	txtA.append("\nRequest: ALL");
			String response = client.query("ALL?");
			if(response == null) {tryToConnect();}
			txtA.append("\nResponse: "  + response);
	    }
	 }
	
	class DelItemAction extends AbstractAction {
	    public DelItemAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	String name = txtName.getText();
	    	txtName.setText("");
	    	if ( name != "" && client != null && !name.trim().isEmpty() ) {
				txtA.append("\nRequest: DELMEDIA?" +name);
				String response = client.query("DELMEDIA?" +name);
				if(response == null) {tryToConnect();}
				txtA.append("\nResponse: "  + response);
			} else {
				txtA.append("\nNot a valid name.");
			}
	    }
	 }
	
	class DelGroupAction extends AbstractAction {
	    public DelGroupAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	String name = txtName.getText();
	    	txtName.setText("");
	    	if ( name != "" && client != null && !name.trim().isEmpty() ) {
				txtA.append("\nRequest: DELGROUP?" +name);
				String response = client.query("DELGROUP?" +name);
				if(response == null) {tryToConnect();}
				txtA.append("\nResponse: "  + response);
			} else {
				txtA.append("\nNot a valid name.");
			}
	    }
	 }
	
	class ExitAction extends AbstractAction {
	    public ExitAction() { }
	    public void actionPerformed(ActionEvent e) {
	    	 System.exit(0);
	    }
	 }
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI frame = new GUI();	
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}
