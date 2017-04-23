//java中的多态的实现
public class Duotai {
   public static void main(String args[]){
	   Duotai demo = new Duotai();
	   AnimalSound animalSound = demo.new AnimalSound();
	   Animal duck = demo.new Duck();
	   Animal chicken = demo.new Chicken();
	   animalSound.makeSound(duck);
	   animalSound.makeSound(chicken);
   }
   public abstract class Animal{
	   abstract void makeSound();  //定义抽象类型方法
   }
   public class Chicken extends Animal{
	   public void makeSound(){
		   System.out.println("咯咯咯");
	   }
   }
   public class Duck extends Animal{
	   public void makeSound(){
		   System.out.println("嘎嘎嘎");
	   }
   }
   public class AnimalSound{
	   public void makeSound(Animal animal){  //接收Animal类型的参数
		   animal.makeSound();
	   }
   }
}
