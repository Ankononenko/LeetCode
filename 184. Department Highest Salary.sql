SELECT Department.NAME AS Department
	,Employee.NAME AS Employee
	,Employee.salary AS Salary
FROM Employee
INNER JOIN Department ON Employee.departmentId = Department.id
WHERE (
		Employee.DepartmentId
		,Salary
		) IN (
		SELECT DepartmentId
			,MAX(Salary)
		FROM Employee
		GROUP BY DepartmentId
		)
