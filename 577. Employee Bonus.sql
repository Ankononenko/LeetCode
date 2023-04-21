SELECT NAME
	,bonus
FROM Employee
LEFT JOIN Bonus ON Employee.empId = Bonus.empId
WHERE Bonus.empId IS NULL
	OR bonus < 1000
