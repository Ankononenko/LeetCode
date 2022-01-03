class Solution {
    fun plusOne(digits: IntArray): IntArray {
        for (element in digits.size - 1 downTo 0) {
            digits[element] += 1
            if (digits[element] <= 9) return digits
            digits[element] = 0
        }
        val arrayToReturn = IntArray(digits.size + 1)
        arrayToReturn[0] = 1

        return arrayToReturn
    }
}
