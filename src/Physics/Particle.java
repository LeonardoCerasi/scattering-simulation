package Physics;

import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.ArrayList;
/**
 * This class provides the object type Particle, which simulates a free point particle coupled to no force field.
 */
public class Particle extends Object {

    // Constants
    static final int DIMENSION = 3;
    static final String[] DIMENSIONS = { "x", "y", "z" };
    static final String[] PHYSICAL_QUANTITIES = { "x", "y", "z", "vx", "vy", "vz" };

    // Initialization of class parameters

    // Mass
    private double m;

    // Coordinates
    private double x;
    private double y;
    private double z;

    // Velocities
    private double vx;
    private double vy;
    private double vz;

    /**
     * This metod sets the specified physical quantity of the particle to the specifies value.
     * 
     * @param quantity The String that specifies the physical quantity.
     * @param value    The double that specifies the value to assign.
     */
    public void setQuantity(String quantity, double value) {
        switch (quantity) {

            // Mass
            case "m":
                this.m = value;
                break;

            // Coordinates
            case "x":
                this.x = value;
                break;
            case "y":
                this.y = value;
                break;
            case "z":
                this.z = value;
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

            // Deafault: nothing
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

            // Mass
            case "m":
                return this.m;

            // Coordinates
            case "x":
                return this.x;
            case "y":
                return this.y;
            case "z":
                return this.z;

            // Velocities
            case "vx":
                return this.vx;
            case "vy":
                return this.vy;
            case "vz":
                return this.vz;

            // Default: 0
            default:
                return 0d;
        }
    }

    /**
     * This metod initializes a Particle object with the given initial state.
     * @param initial_state Array which describes the initial state of the particle: {m,x,y,z,vx,vy,vz}.
     */
    public Particle(double[] initial_state) {

        //Mass
        m = initial_state[0];

        //Initial coordinates
        x = initial_state[1];
        y = initial_state[2];
        z = initial_state[3];

        //Initial velocities
        vx = initial_state[4];
        vy = initial_state[5];
        vz = initial_state[6];
    }

     /**
     * This metod initializes an array of Particle objects.
     * @param path The path of the .csv file with the initial conditions of the Framework object.
     * @return An ArrayList of Particle objects: the initialized particles.
     */
    public static ArrayList<Particle> particles(String path) {

        // Particles initialization
        ArrayList<Particle> particles = new ArrayList<>();

        //Reading particles' initial states from csv file
        try (BufferedReader file = new BufferedReader(new FileReader(path));) {
            String line = null;
            while ((line = file.readLine()) != null) {
                double[] initial_state = Arrays.stream(line.split(",")).mapToDouble(Double::parseDouble).toArray();
	            particles.add(new Particle(initial_state));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return particles;
    }

    /**
     * This metod moves a point particle of a time interval "delta_t" in the future.
     * @param delta_t The time interval (in seconds) to move in the future.
     */
    public void motion(double delta_t) {

        // Cycle over physical quantities
        for (int i = 0; i < DIMENSION; i++) {
            
            // Constant-velocity linear motion
            this.setQuantity(PHYSICAL_QUANTITIES[i],
                this.getQuantity(PHYSICAL_QUANTITIES[i]) + this.getQuantity("v" + PHYSICAL_QUANTITIES[i]) * delta_t);

        }
    }
}