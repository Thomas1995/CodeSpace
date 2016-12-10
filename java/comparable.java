public class comparable {

  private static class A< T extends Comparable<T> > { }

  private static class base implements Comparable<base> {
    @Override
    public int compareTo(base c) {
      return 0;
    }
  }

  private static class derived extends base {
    /*@Override
    public int compareTo(derived c) {
      return 0;
    }*/
  }

  public static void main(String[] args) {
    A<derived> a = new A<derived>();
  }
}
