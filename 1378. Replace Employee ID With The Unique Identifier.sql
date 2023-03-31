SELECT unique_id
	,NAME
FROM Employees
LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id
