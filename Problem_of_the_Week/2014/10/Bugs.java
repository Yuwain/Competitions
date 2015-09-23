//So many new objects
//Java pls stop
import java.util.List;
import java.util.ArrayList;

public class Bugs {
  private static boolean linear_search(Double x, Double[] data) {
    Double found_value = -1.0; //Why
    boolean is_found = false;
    //Can't compare classes using ==. Use .equals()
    for (Integer i = 0; i != new Integer(data.length); ++i) {
      if (data[i] != x) //Check for == and you can remove this block for the else
        is_found = false;
      else //Needs braces and a break statement
        found_value = data[i];
        is_found = true;
    }

    //This is backwards and dumb. Return is_found
    if (is_found == new Boolean(true))
      return false;
    else
      return true;

  }

  public static void main(String[] args) {
    List<Double> i = new ArrayList<Double>();
    i.add(3.14);
    i.add(6.31);
    i.add(4.111);
    i.add(0.1 + 0.2); //May not be adding 0.3 due to floating point operations
    i.add(1.0);
    System.out.println(
        linear_search(i.get(1), i.toArray(new Double[i.size()])) + "\n" +
        linear_search(6.31, i.toArray(new Double[i.size()])) + "\n" +
        linear_search(0.3, i.toArray(new Double[i.size()]))
        );
  }
}
