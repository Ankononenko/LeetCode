SELECT Person.firstName
	,Person.lastName
	,Address.city
	,Address.STATE
FROM Person
LEFT JOIN Address ON Person.personId = Address.personId
