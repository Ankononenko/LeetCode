class Solution {
    val RomanToIntMap = mapOf('I' to 1, 'V' to 5, 'X' to 10, 'L' to 50, 'C' to 100, 'D' to 500, 'M' to 1000)
    fun romanToInt(s: String): Int {
        var intToReturn: Int = 0
        var maximum = 0
        for (letter in s.reversed()) {
            if (RomanToIntMap.getValue(letter) >= maximum){
                intToReturn += RomanToIntMap.get(letter)!!
                maximum = RomanToIntMap.getValue(letter)
            } else {
                intToReturn -= RomanToIntMap.getValue(letter)
            }
        }
        return intToReturn
    }
}
fun main() {
    val callTheSolution = Solution()
    println(callTheSolution.romanToInt("LVIII"))
    println(callTheSolution.romanToInt("IV"))
    println(callTheSolution.romanToInt("IX"))
    println(callTheSolution.romanToInt("MCMXCIV"))
}
