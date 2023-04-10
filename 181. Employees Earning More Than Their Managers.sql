SELECT NAME AS Employee
FROM Employee e1
WHERE e1.salary > (
		SELECT salary
		FROM Employee e2
		WHERE e1.managerId = e2.id
		)
