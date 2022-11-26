class Solution {
    fun strStr(haystack: String, needle: String): Int {
        if (needle.isBlank()) return 0
        if (needle in haystack) return haystack.indexOf(needle)
        else return -1
    }
}
