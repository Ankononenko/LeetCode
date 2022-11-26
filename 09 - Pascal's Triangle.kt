class Solution {
    fun generate(numRows: Int): List<List<Int>> {

        if (numRows == 0) return listOf()

        val resolution = ArrayList<List<Int>>()
        resolution.add(listOf(1))

        for (i in 1..numRows - 1) {
            val list = ArrayList<Int>()
            list.add(1)
            for (j in 1..i - 1)
                list.add(resolution[i - 1][j - 1] + resolution[i - 1][j])
            list.add(1)
            resolution.add(list)
        }

        return resolution
    }
}
fun main() {
    val callSolution = Solution()
    println(callSolution.generate(5))
}
