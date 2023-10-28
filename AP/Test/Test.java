public class Test {
    
    public static void main(String arg[]) {
        System.out.println("Testing " + Ops.add(2.5,2.0) + "\n");

        Student st1 = new Student(17,"Nhat Bui");
        Student st2 = new Student(71,"Thai Bui");

        st1.display();
        st2.display();
        System.out.println("Total " + Ops.add(st1.getAge(),st2.getAge()) + "\n");
    }

}