class Solution {
    fun twoSum(nums: IntArray, target: Int): MutableList<Int> {
        var startIndex = 0
        var sumToCheckWithTarget = 0
        val mapToWorkWith = mutableListOf<Int>()
        var stateOfTheSolution = false
        while(!stateOfTheSolution){
            for(element in nums){
                if(nums[startIndex] != element){
                    sumToCheckWithTarget = nums[startIndex] + element
                    if(sumToCheckWithTarget == target) {
                        mapToWorkWith += nums.indexOf(nums[startIndex])
                        mapToWorkWith += nums.indexOf(element)
                        stateOfTheSolution = true
                        break
                    }
                    else startIndex++
                }
            }
        }
        return mapToWorkWith
    }
}

fun main(){
    val runSolution = Solution()
    println(runSolution.twoSum(intArrayOf(2,7,11,15), 9))
    println(runSolution.twoSum(intArrayOf(3, 2, 4), 6))
    //println(runSolution.twoSum(intArrayOf(3, 3), 6))
}
