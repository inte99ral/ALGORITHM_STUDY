import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    int answer = 0;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      for (int i = 0; i < 10; i++) {
        int tempInt = Integer.parseInt(br.readLine());
        if (answer + tempInt <= 100) {
          answer += tempInt;
        } 
        
        else {
          if (100 - answer < answer + tempInt - 100) {
            break;
          } 
          else {
            answer += tempInt;
            break;
          }
        }
      }

      br.close();
    }

    System.out.println(answer);
    return;
  }
}
