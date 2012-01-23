
public class Test {
  private int i;
  public static int staticFieldInt = 42;
  public static Test[] staticArrayObjects = null;
  
  public Test() {}
  public Test(int i) { this.i = i; }
  
  public int getInt() { return i; }
  
  public static String staticMethod() { return "staticMethod called"; }
  public static int staticMethod(int i) { return i + 1; }
  public static void staticMethodThrows(Exception ex) throws Exception { throw ex; }
}
