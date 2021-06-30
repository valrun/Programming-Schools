package lesson6;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class SQLTest {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		// TODO Auto-generated method stub
		Class.forName("org.postgresql.Driver");
		try(final Connection	conn = DriverManager.getConnection(
						"jdbc:postgresql://10.77.251.101:5432/postgres"
						,"testuser"
						,"testpassword")) {
			
			try(final ResultSet rs = conn.getMetaData().getTables(null,null,"%",null)) {
				while (rs.next()) {
					System.err.println("Table="+rs.getString("TABLE_NAME"));
				}
			}
			
			try(final Statement stmt = conn.createStatement()) {
				
				try(final ResultSet rs = stmt.executeQuery(
							"select * from chav")) {
					while (rs.next()) {
						System.err.println("Content="+rs.getString(1));
					}
				}
				
				try(final ResultSet rs = stmt.executeQuery(
							"select * from chav order by 1 desc")) {
					while (rs.next()) {
						System.err.println("Content1="+rs.getString(1));
					}
				}
				
				conn.setAutoCommit(false);
				stmt.executeUpdate("insert into chav values (1111)");
				
				try(final ResultSet rs = stmt.executeQuery(
							"select * from chav order by 1 desc")) {
					while (rs.next()) {
						System.err.println("Content2="+rs.getString(1));
					}
				}
				conn.rollback();
			}
		}
	}

}
