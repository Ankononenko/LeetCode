class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        var stringToReturn: String = ""
        var i: Int = 0
        while (true){
            val letterElement = strs.map { it.getOrNull(i) }.toSet()
            if (null in letterElement || letterElement.size > 1)
                break
            else {
                stringToReturn += letterElement.elementAt(0)
                i ++
            }
        }
        return stringToReturn
        }
}
fun main(){
    val callTheSolution = Solution()
    println(callTheSolution.longestCommonPrefix(arrayOf("tomato", "tomata", "tomat")))
}
