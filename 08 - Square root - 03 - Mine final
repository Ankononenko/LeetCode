class Solution {
    fun mySqrt(x: Int): Int {
        val lenghtOfTheNum: Int = x.toString().length + 1
        var startingPosition: Double = lenghtOfTheNum * 100.0
        if (x == 0 || x == 1)
            startingPosition = x.toDouble()
        else {
            while ((startingPosition * startingPosition).toInt() != x) {
                startingPosition = 0.5 * (startingPosition + (x / startingPosition))
            }
        }
        return startingPosition.toInt()
    }
}

fun main() {
    val callSolution = Solution()
    println(callSolution.mySqrt(0))
    println(callSolution.mySqrt(1))
    println(callSolution.mySqrt(8))
    println(callSolution.mySqrt(9))
    println(callSolution.mySqrt(16))
    println(callSolution.mySqrt(100))
    println(callSolution.mySqrt(1000))
    println(callSolution.mySqrt(10000))
    println(callSolution.mySqrt(125348))
    println(callSolution.mySqrt(2147483647))
}
