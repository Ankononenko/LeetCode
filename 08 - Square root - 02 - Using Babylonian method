class Solution {
    fun mySqrt(x: Int): Int {
        val lenghtOfTheNum: Int = x.toString().length + 1
        var startingPosition: Double = lenghtOfTheNum * 100.0
        while ((startingPosition * startingPosition).toInt() != x) {
            startingPosition = 0.5 * (startingPosition + (x / startingPosition))
        }
        return startingPosition.toInt()
    }
}

fun main() {
    val callSolution = Solution()
    println(callSolution.mySqrt(8))
    println(callSolution.mySqrt(9))
    println(callSolution.mySqrt(16))
    println(callSolution.mySqrt(100))
    println(callSolution.mySqrt(1000))
    println(callSolution.mySqrt(10000))
    println(callSolution.mySqrt(125348))
}
