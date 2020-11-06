import java.sql.*;

public class ConnectDB {
    public static void main(String[] args) {
        try{
            Class.forName("com.mysql.jdbc.Driver");
        }catch (ClassNotFoundException cne){
            cne.printStackTrace();
        }
        String dburl = "jdbc:mysql://127.0.0.1:3306/12306?useSSL=false&serverTimezone=UTC";
        String sql = "SELECT * FROM Train_Info";
        try(Connection conn = DriverManager.getConnection(dburl,"root","wangzilong2020");
            Statement stmt = conn.createStatement();
            ResultSet rst = stmt.executeQuery(sql))

        {
            while (rst.next()){
                System.out.println(rst.getString(1) + "\t" + rst.getString(2) + "\t"
                        + rst.getString(3) + "\t" + rst.getInt(4)+"\t"+
                        rst.getInt(5)
                );
            }

        }catch (SQLException se){
            se.printStackTrace();
        }
    }
}