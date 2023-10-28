public class Student {
    private
        int age;
        String name;
    public
        Student(int a, String n) {
            this.age = a;
            this.name += n.charAt(3);
        }
        void display() {
            System.out.println(name + " : " + age);
        }

        int getAge() {
            return age;
        }
        String getName() {
            return name;
        }

        void setAge(int a) {
            age = a;
        }
        void setName(String n) {
            name = n;
        }


}
