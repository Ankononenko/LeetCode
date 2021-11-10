class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        var result = ""
        var i = 0
        // Infinite loop: this way we don't have to find the shortest word
        while (true) {
            // Get element at index i
            val b = strs.map { it.getOrNull(i) }.toSet()
            // if contains null, then at least one of the element ran out of letters
            if (b.contains(null)) {
                break
            }
            // size of set == 1 then all contents same i.e. same character
            if (b.size == 1) {
                result += b.elementAt(0)
                i++
            } else {
                break
            }
        }
        return result
    }
}
fun main () {
    val callTheSolution = Solution()
    println(callTheSolution.longestCommonPrefix(arrayOf("pottato", "pottata", "pottotan")))
}
