import java.util.Scanner;
public class A_add_B {
    public static void main(String[] args){
        /**给定一个整数数组 nums 和一个目标值 target，
        请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
        示例:
        给定 nums = [2, 7, 11, 15], target = 9
        因为 nums[0] + nums[1] = 2 + 7 = 9
        所以返回 [0, 1]**/
        System.out.print("请输入数组的个数：");
        Scanner reader = new Scanner(System.in);
        int x=reader.nextInt();
        int[] a=new int[x];
        int i;
        for(i=0;i<x;i++)
        {
            System.out.print("请输入第"+(i+1)+"个整数：");
            Scanner reader1 = new Scanner(System.in);
            a[i]=reader1.nextInt();
        }
        System.out.print("请输入目标值：");
        Scanner reader2 = new Scanner(System.in);
        int y=reader2.nextInt();
        Solution c=new Solution();
        c.twoSum(a,y);
    }
}
class Solution {
    public void twoSum(int[] nums, int target) {
        System.out.println("数组中与目标值相同的两个数的下标如下所示：");
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    System.out.println("第"+(i+1)+"组"+"["+i+","+j+"]");
                }
            }
        }
    }
}
