SELECT w1.id
FROM Weather AS w1
	,Weather AS w2
WHERE w1.temperature > w2.temperature
	AND datediff(w1.recordDate, w2.recordDate) = 1 k
