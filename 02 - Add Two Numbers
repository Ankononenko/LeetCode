class Solution {
    fun addTwoNumbers(l1: List<Int>, l2: List<Int>): List<Char> {
        val revertedToListOne = l1.joinToString().replace(", ", "").reversed().toInt()
        val revertedToListTwo = l2.joinToString().replace(", ", "").reversed().toInt()
        val result = revertedToListOne + revertedToListTwo
        val charResult = result.toString().reversed().toList()
        return charResult
    }
}
fun main(){
    val callSolution = Solution()
    print(callSolution.addTwoNumbers(listOf(2, 4, 3), listOf(5, 6, 4)))
}
