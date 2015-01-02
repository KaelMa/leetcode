//Problem
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/



//My solution
//by sorted array

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        
        if(numbers == null || numbers.length == 0)
        {
            return res;
        }
        
        int[] sortNumbers = new int[numbers.length];
        System.arraycopy(numbers,0,sortNumbers,0,numbers.length);
        Arrays.sort(sortNumbers);
        
        int a = 0;
        int b = 0;
        
        for(int i = 0;i < sortNumbers.length;i++)
        {
            int j = i+1;
            while(j < sortNumbers.length-1 && sortNumbers[j] < target-sortNumbers[i])
            {
                j++;
            }
            if(j < sortNumbers.length && sortNumbers[j] == target-sortNumbers[i])
            {
                a = sortNumbers[i];
                b = sortNumbers[j];
                break;
            }
        }
        
        int index1 = 0;
        int index2 = 0;
        for(int i =0;i<numbers.length;i++)
        {
            if(numbers[i] == a )
            {
                index1 = i+1;
                break;
            }
        }
        for(int j = numbers.length-1;j>=0;j--)
        {
            if(numbers[j] == b)
            {
                index2 = j+1;
                break;
            }
        }
        
        res[0] = Math.min(index1,index2);
        res[1] = Math.max(index1,index2);
        
        return res;
        
    }
}