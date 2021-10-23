class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var result = intArrayOf(0, 0)
        var stateOfTheSolution = false
        while (!stateOfTheSolution) {
            for (firstElement in nums.indices) {
                for (secondElement in (firstElement + 1) until nums.size) {
                    if (target == nums[firstElement] + nums[secondElement]) {
                        result = intArrayOf(firstElement, secondElement)
                        stateOfTheSolution = true
                        break
                    }
                }
            }
        }
        //println(result.toList())
        return result
    }
}

fun main(){
    val runSolution = Solution()
    println(runSolution.twoSum(intArrayOf(2,7,11,15), 9))
    println(runSolution.twoSum(intArrayOf(3, 2, 4), 6))
    println(runSolution.twoSum(intArrayOf(3, 3), 6))
}
