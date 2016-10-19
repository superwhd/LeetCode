public class Solution {

    public Solution(int[] nums) {
        map = new HashMap<Integer, ArrayList<Integer>>();
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (!map.containsKey(x)) {
                map.put(x, new ArrayList<Integer>());
            }
            map.get(x).add(i);
        }
    }
    
    public int pick(int target) {
        ArrayList<Integer> lst = map.get(target);
        return lst.get((new Random()).nextInt(lst.size()));
    }
    private Map<Integer, ArrayList<Integer>> map;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
