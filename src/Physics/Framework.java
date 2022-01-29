package Physics;

import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Arrays;
/**
 * This class provides the object type Box, which simulates a closed space in motion (both free motion and oscillation):
 */
public class Framework {
    
    // Constants
    static final int DIMENSION = 3;
    static final String[] DIMENSIONS = { "x", "y", "z" };
    static final String[] PHYSICAL_QUANTITIES = { "x", "y", "z", "vx", "vy", "vz" };

    // Initialization of class parameters

    // Minimum edges
    private double x_min;
    private double y_min;
    private double z_min;

    // Maximum edges
    private double x_max;
    private double y_max;
    private double z_max;

    // Velocities
    private double vx;
    private double vy;
    private double vz;

    // Periods of oscillations
    private double tx;
    private double ty;
    private double tz;

    /**
     * This metod sets the value of the specified physical quantity of the Box to the given value.
     * 
     * @param quantity The String that specifies the physical quantity.
     * @param value    The double that specifies the value to assign.
     */
    public void setQuantity(String quantity, double value) {
        switch (quantity) {

            // Minimum edges
            case "x_min":
                this.x_min = value;
                break;
            case "y_min":
                this.y_min = value;
                break;
            case "z_min":
                this.z_min = value;
                break;

            // Maximum edges
            case "x_max":
                this.x_max = value;
                break;
            case "y_max":
                this.y_max = value;
                break;
            case "z_max":
                this.z_max = value;
                break;

            // Velocities
            case "vx":
                this.vx = value;
                break;
            case "vy":
                this.vy = value;
                break;
            case "vz":
                this.vz = value;
                break;

            // Periods of oscillations
            case "tx":
                this.tx = value;
                break;
            case "ty":
                this.ty = value;
                break;
            case "tz":
                this.tz = value;
                break;

            // Default: nothing
            default:
                break;
        }
    }

    /**
     * This metod return the current value of the specified physical quantity.
     * 
     * @param quantity The String that specifies the physical quantity.
     * @return A double: the value of the physical quantity.
     */
    public double getQuantity(String quantity) {
        switch (quantity) {

            // Minimum edges
            case "x_min":
                return this.x_min;
            case "y_min":
                return this.y_min;
            case "z_min":
                return this.z_min;

            // Maximum edges
            case "x_max":
                return this.x_max;
            case "y_max":
                return this.y_max;
            case "z_max":
                return this.z_max;

            // Velocities
            case "vx":
                return this.vx;
            case "vy":
                return this.vy;
            case "vz":
                return this.vz;

            // Periods of oscillations
            case "tx":
                return this.tx;
            case "ty":
                return this.ty;
            case "tz":
                return this.tz;

            // Default: 0
            default:
                return 0d;
        }
    }

    /**
     * This constructor initializes a Framework object with the given initial state.
     * 
     * @param initial_state A double[] array wich specifies the initial parameters of the framework: {x_min,y_min,z_min,x_max,y_max,z_max,vx,vy,vz,tx,ty,tz}.
     */
    public Framework(double[] initial_state) {

        // Initial minimum edges
        x_min = initial_state[0];
        y_min = initial_state[1];
        z_min = initial_state[2];

        // Initial maximum edges
        x_max = initial_state[3];
        y_max = initial_state[4];
        z_max = initial_state[5];

        // Velocities initialized to 0
        vx = initial_state[6];
        vy = initial_state[7];
        vz = initial_state[8];

        // Periods of oscillations initialized to 1
        tx = initial_state[9];
        ty = initial_state[10];
        tz = initial_state[11];
    }

    /**
     * This metod initializes a Framework object interactively.
     * @param path The path of the .csv file with the initial conditions of the Framework object.
     * @return A Framework: the initialized framework.
     */
    public static Framework framework(String path) {

        double[] initial_state = null;

        try (BufferedReader file = new BufferedReader(new FileReader(path));) {
            String line = null;
            while ((line = file.readLine()) != null) {
                initial_state = Arrays.stream(line.split(",")).mapToDouble(Double::parseDouble).toArray();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        //Return the framework
        return new Framework(initial_state);
    }
}
