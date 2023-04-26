DELETE
FROM Person
WHERE id NOT IN (
		SELECT *
		FROM (
			SELECT min(id)
			FROM Person
			GROUP BY email
			) AS p
		)
