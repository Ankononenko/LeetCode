class Solution {
    fun mySqrt(x: Int): Int {
        var intToReturn: Double = 1.0
        var isSolved: Boolean = false
        while (isSolved == false) {
            val productOfDivision = x / intToReturn
            if (productOfDivision * productOfDivision == x.toDouble()) {
                isSolved = true
            }
            else intToReturn++
        }
        return intToReturn.toInt()
    }
}

fun main() {
    val callSolution = Solution()
    println(callSolution.mySqrt(9))
    println(callSolution.mySqrt(16))
//    println(callSolution.mySqrt(8))
}
