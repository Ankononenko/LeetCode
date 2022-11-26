// Merge two sorted lists analog solution
fun merge(listOne: List<Int>, listTwo: List<Int>): List<Int> {
    return (listOne + listTwo).sorted()
}
fun main(){
    println(merge(listOf(1, 2, 3), listOf(1, 3, 4, 5)))
}
