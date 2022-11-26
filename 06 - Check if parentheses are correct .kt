/**
 * Here we create a mutable list of Char. List is of opened brackets.
 * Brackets are added to the list as we iterate over the string if they are in the values of the map.
 * Based on the situation it either adds to the list or detracts.
 * If the final list is empty - we return true. If it is not - false.
**/
class Solution {
    fun isValid(s: String): Boolean {
        if (s.length % 2 != 0) return false
        val brackets = mapOf(')' to '(', ']' to '[', '}' to '{')
        val opened = arrayListOf<Char>()
        for (element in s) {
            if (element in brackets.values) {
                opened.add(element)
            } else if (opened.size == 0 || brackets.get(element) != opened.removeAt(opened.size - 1)) {
                    return false
            }
        }
        return opened.isEmpty()
    }
}
