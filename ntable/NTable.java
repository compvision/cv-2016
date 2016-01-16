import java.net.*;
import java.io.*;
import edu.wpi.first.wpilibj.networktables.NetworkTable;

class NTable
{
    public static void main(String [] args) throws Exception
    {
        String serverName = "localhost";
        int port = 3341; 
        try
        {
            Socket client = new Socket(serverName, port);
            OutputStream outToServer = client.getOutputStream();
            DataOutputStream out = new DataOutputStream(outToServer);

            InputStream inFromServer = client.getInputStream();
            DataInputStream in = new DataInputStream(inFromServer);

            NetworkTable.setClientMode();
            NetworkTable.setIPAddress("10.33.41.2");
            NetworkTable table = NetworkTable.getTable("cv");
            //Main loop
            while(true)
            {
                //send the value request
                out.write('\n');

                //grab the values
                Thread.sleep(100); // Update values every 100 ms
                String targetDataRaw = null;
                targetDataRaw = in.readLine();
                if(targetDataRaw == null)
                    break;
                if(targetDataRaw.isEmpty())
                    continue;

                // Implements the FRC 2015 Network Tables Protocol
                boolean found;
                double distance = 0, azimuth = 0;
                String[] parsed = targetDataRaw.split(";"); 
                found = parsed[0].equals("true");
                //System.out.println(parsed[0]); 
                if(found)
                {
                    distance = Double.parseDouble(parsed[1]);
                    azimuth = Double.parseDouble(parsed[2]);
                    System.out.println("Tote found!");
                    System.out.println("Distance: " + distance);
                    System.out.println("Azimuth: " + azimuth); 
                    System.out.println(); 
                    table.putBoolean("toteFound", true);
                    table.putNumber("distance_m", distance);
                    table.putNumber("azimuth_deg", azimuth);
                }
                else
                {
                    //System.out.println("Tote not found");
                    table.putBoolean("toteFound", false);
                    System.out.println(); 
                }
            } 
            out.close();
            in.close();
            client.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
   }    
    
}
