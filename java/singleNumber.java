public class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result ^= nums[i];
        }
        return result;
    }

    public static int singleNumber(int[] nums) {
        // List<Integer> list = IntStream.of(nums).boxed().collect(Collectors.<Integer>toList());
        // return list.stream().reduce(0, (c,e)->c^e);
        // return IntStream.of(nums).reduce(0, (c,e)->c^e);
        return Arrays.stream(nums).reduce(0, (c,e)->c^e);
    }
}